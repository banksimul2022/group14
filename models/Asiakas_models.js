const db = require('../database');

const Asiakas = {
  getById: function(id, callback) {
    return db.query('select * from Asiakas where id_Asiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Asiakas', callback);
  },
  add: function(Asiakas, callback) {
    return db.query(
      'insert into Asiakas (name,author,isbn) values(?,?,?)',
      [Asiakas.name, Asiakas.author, Asiakas.isbn],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Asiakas where id_Asiakas=?', [id], callback);
  },
  update: function(id, Asiakas, callback) {
    return db.query(
      'update Asiakas set name=?,author=?, isbn=? where id_Asiakas=?',
      [Asiakas.name, Asiakas.author, Asiakas.isbn, id],
      callback
    );
  }
};
module.exports = Asiakas;