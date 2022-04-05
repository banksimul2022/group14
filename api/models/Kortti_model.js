const db = require('../database');
const bcrypt = require('bcryptjs');
const saltRounds=10;


const Kortti = {
  getById: function(idKortti, callback) {
    return db.query('select * from Kortti where idKortti=?', [idKortti], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Kortti', callback);
  },
  add: function(Kortti, callback) {
    bcrypt.hash(Kortti.PIN, saltRounds, function(err, hash) {
      return db.query('insert into Kortti (Tili_idTili,korttinumero,PIN,voimassaolo,Asiakas_idAsiakas,lukko) values(?,?,?,?,?,?)',
      [Kortti.Tili_idTili,Kortti.korttinumero,hash,Kortti.voimassaolo,Kortti.Asiakas_idAsiakas,Kortti.lukko], callback);
    });
  },
  delete: function(idKortti, callback) {
    return db.query('delete from Kortti where idKortti=?', [idKortti], callback);
  },
  update: function(id, Kortti, callback) {
    bcrypt.hash(Kortti.PIN, saltRounds, function(err, hash) {
      return db.query('update Kortti set idKortti=?, PIN=? where idKortti=?',
      [Kortti.idKortti, hash, Kortti.idKortti], callback);
    });
  }
};
module.exports = Kortti;