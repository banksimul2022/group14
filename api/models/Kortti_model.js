const db = require('../database');

const Kortti = {
  getById: function(id, callback) {
    return db.query('select * from Kortti where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Kortti', callback);
  },
  add: function(Kortti, callback) {
    return db.query(
      'insert into Kortti (Tili_idTili, korttinumero, voimassaolo, PIN, Asiakas_idAsiakas, lukko) values(?,?,?,?,?,?)'
      [Kortti.Tili_idTili, Kortti.korttinumero, Kortti.voimassaolo, Kortti.PIN, Kortti.Asiakas_idAsiakas, Kortti.lukko],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Kortti where idKortti=?', [id], callback);
  },
  update: function(id, Kortti, callback) {
    return db.query(
      'update Kortti set tili_idTili=?, korttinumero=?, voimassaolo=?, PIN=?, Asiakas_idAsiakas=?, lukko=? where idKortti=?',
      [Kortti.Tili_idTili, Kortti.korttinumero, Kortti.voimassaolo, Kortti.PIN, Kortti.Asiakas_idAsiakas, Kortti.lukko, id],
      callback
    );
  }
};
module.exports = Kortti;