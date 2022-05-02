const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const kortti = require('../models/Kortti_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

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
                }
              }
              );
            }
            else{
              console.log("korttinumero does not exists");
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
}

module.exports=router;
