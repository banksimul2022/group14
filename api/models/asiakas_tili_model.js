const db = require('../database');

const asiakas_tili = {
  getById: function(id, callback) {
    return db.query('select * from asiakas_tili where id_asiakas_tili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas_tili', callback);
  },
  add: function(asiakas_tili, callback) {
    return db.query(
      'insert into asiakas_tili (name,author,isbn) values(?,?,?)',
      [asiakas_tili.name, asiakas_tili.author, asiakas_tili.isbn],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas_tili where id_asiakas_tili=?', [id], callback);
  },
  update: function(id, asiakas_tili, callback) {
    return db.query(
      'update asiakas_tili set name=?,author=?, isbn=? where id_asiakas_tili=?',
      [asiakas_tili.name, asiakas_tili.author, asiakas_tili.isbn, id],
      callback
    );
  }
};
module.exports = asiakas_tili;