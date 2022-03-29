var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
const mysql = require('mysql');

const asiakas_tiliRouter = require('./routes/asiakas_tili');
const AsiakasRouter = require ('./routes/Asiakas');
const KorttiRouter = require ('./routes/Kortti');
const TiliRouter = require('./routes/Tili');
const TilitapahtumatRouter = require('./routes/Tilitapahtumat');


app.use(basicAuth({users: { 'admin': '1234' }}))

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));


app.use('/asiakas_tili', asiakas_tiliRouter);
app.use('/Asiakas', AsiakasRouter);
app.use('/Kortti', KorttiRouter);
app.use('/Tili', TiliRouter);
app.use('/Tilitapahtumat', TilitapahtumatRouter);

module.exports = app;
