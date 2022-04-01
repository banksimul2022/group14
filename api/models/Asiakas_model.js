const db = require('../database');

const Asiakas = {
  getById: function(id, callback) {
    return db.query('select * from Asiakas where idAsiakas=?', [id], callback);
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
  delete: function(id, callback) {
    return db.query('delete from Asiakas where id_Asiakas=?', [id], callback);
  },
  update: function(id, Asiakas, callback) {
    return db.query(
      'update Asiakas set Etunimi=?, Sukunimi=?, Puhelinnumero=?, Osoite=?, Henkilöturvatunnus=? where idAsiakas=?',
      [Asiakas.Etunimi, Asiakas.Sukunimi, Asiakas.Puhelinnumero, Asiakas.Osoite, Asiakas.Henkilöturvatunnus, id],
      callback
    );
  }
};
module.exports = Asiakas;