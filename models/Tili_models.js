const db = require('../database');

const Tili = {
  getById: function(id, callback) {
    return db.query('select * from Tili where id_Tili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Tili', callback);
  },
  add: function(Tili, callback) {
    return db.query(
      'insert into Tili (name,author,isbn) values(?,?,?)',
      [Tili.name, Tili.author, Tili.isbn],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Tili where id_Tili=?', [id], callback);
  },
  update: function(id, Tili, callback) {
    return db.query(
      'update Tili set name=?,author=?, isbn=? where id_Tili=?',
      [Tili.name, Tili.author, Tili.isbn, id],
      callback
    );
  }
};
module.exports = Tili;