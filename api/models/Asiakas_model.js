const db = require('../database');

const Asiakas = {
  getById: function(idAsiakas, callback) {
    return db.query('select * from Asiakas where idAsiakas=?', [idAsiakas], callback);
    console.log["where"]
  },
  getAll: function(callback) {
    return db.query('select * from Asiakas', callback);
  },
  add: function(Asiakas, callback) {
    return db.query(
      'insert into Asiakas (Etunimi, Sukunimi, Puhelinnumero, Osoite, Henkilöturvatunnus) values(?,?,?,?,?)',
      [ Asiakas.Etunimi, Asiakas.Sukunimi, Asiakas.Puhelinnumero, Asiakas.Osoite, Asiakas.Henkilöturvatunnus],
      callback
    );
  },
  delete: function(idAsiakas, callback) {
    return db.query('delete from Asiakas where idAsiakas=?', [idAsiakas], callback);
  },
  update: function(id, Asiakas, callback) {
    return db.query(
      'update Asiakas set Etunimi=?, Sukunimi=?, Puhelinnumero=?, Osoite=?, Henkilöturvatunnus=? where idAsiakas=?',
      [Asiakas.Etunimi, Asiakas.Sukunimi, Asiakas.Puhelinnumero, Asiakas.Osoite, Asiakas.Henkilöturvatunnus, Asiakas.idAsiakas],
      callback
    );
  }
};