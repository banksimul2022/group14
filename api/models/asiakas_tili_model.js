const db = require('../database');

const asiakas_tili = {
  getById: function(idAsiakas, callback) {
    return db.query('select * from asiakas_tili where idAsiakas=?', [idAsiakas], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas_tili', callback);
  },
  add: function(asiakas_tili, callback) {
    return db.query(
      'insert into asiakas_tili (idAsiakas,idTili) values(?,?)',
      [asiakas_tili.idAsiakas, asiakas_tili.idTili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas_tili where idAsiakas=?', [id], callback);
  },
  update: function(id, asiakas_tili, callback) {
    return db.query(
      'update asiakas_tili set idTlil=? where idAsiakas=?',
      [asiakas_tili.name, asiakas_tili.author, asiakas_tili.isbn, id],
      callback
    );
  }
};
module.exports = asiakas_tili;