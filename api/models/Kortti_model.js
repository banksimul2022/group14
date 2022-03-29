const db = require('../database');

const Kortti = {
  getById: function(id, callback) {
    return db.query('select * from Kortti where id_Kortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Kortti', callback);
  },
  add: function(Kortti, callback) {
    return db.query(
      'insert into Kortti (name,author,isbn) values(?,?,?)',
      [Kortti.name, Kortti.author, Kortti.isbn],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Kortti where id_Kortti=?', [id], callback);
  },
  update: function(id, Kortti, callback) {
    return db.query(
      'update Kortti set name=?,author=?, isbn=? where id_Kortti=?',
      [Kortti.name, Kortti.author, Kortti.isbn, id],
      callback
    );
  }
};
module.exports = Kortti;