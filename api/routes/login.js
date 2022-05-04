const express = require('express');
const db = require('../database');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const kortti = require('../models/Kortti_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');
const { token } = require('morgan');
let laskuri=0;

router.post('/', 
  function(request, response) {
    if(request.body.korttinumero && request.body.PIN){
      const korttinumero = request.body.korttinumero;
      const PIN = request.body.PIN;

        login.checkPIN(korttinumero, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(PIN,dbResult[0].PIN, function(err,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  const token = generateAccessToken({ korttinumero: korttinumero });
                  response.send(token);
                }
                else {
                    console.log("wrong PIN");
                    response.send(false);
                    laskuri++;
                    if(laskuri==3){
                      return db.query('update kortti set lukko=1 where korttinumero=?', [korttinumero]), /*callback)*/
                      console.log("card locked")
                    }
                }
              }
              );
            }
            else{
              console.log("korttinumero does not exists or card is locked");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("korttinumero or PIN missing");
      response.send(false);
    }
  }
);

function generateAccessToken(korttinumero) {

  dotenv.config();
  return jwt.sign(korttinumero, process.env.MY_TOKEN, { expiresIn: '1800s' });
  laskuri=0;
}

module.exports=router;
