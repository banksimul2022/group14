const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.idKortti && request.body.PIN){
      const idKortti = request.body.idKortti;
      const PIN = request.body.PIN;
      
        login.checkPIN(idKortti, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(PIN,dbResult[0].PIN, function(err,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  const token = generateAccessToken({ idKortti: idKortti });
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
              console.log("idKortti does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("idKortti or PIN missing");
      response.send(false);
    }
  }
);

function generateAccessToken(idKortti) {
  dotenv.config();
  return jwt.sign(idKortti, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;