var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
const mysql = require('mysql');
const jwt = require('jsonwebtoken');
const loginRouter = require('./routes/login');
const asiakas_tiliRouter = require('./routes/asiakas_tili');
const AsiakasRouter = require ('./routes/Asiakas');
const KorttiRouter = require ('./routes/Kortti');
const TiliRouter = require('./routes/Tili');
const CreditRouter = require('./routes/Credit');
const TilitapahtumatRouter = require('./routes/Tilitapahtumat');

var app = express();
process.env.TZ = "Europe/Helsinki";
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use('/login',loginRouter);

app.use(authenticateToken);
app.use('/asiakas_tili', asiakas_tiliRouter);
app.use('/Asiakas', AsiakasRouter);
app.use('/Kortti', KorttiRouter);
app.use('/Tili', TiliRouter);
app.use('/Credit', CreditRouter);
app.use('/Tilitapahtumat', TilitapahtumatRouter);

module.exports = app;

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }