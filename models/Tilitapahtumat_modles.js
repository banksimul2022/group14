const db = require('../database');

const Tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from Tilitapahtumat where id_Tilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Tilitapahtumat', callback);
  },
  add: function(Tilitapahtumat, callback) {
    return db.query(
      'insert into Tilitapahtumat (name,author,isbn) values(?,?,?)',
      [Tilitapahtumat.name, Tilitapahtumat.author, Tilitapahtumat.isbn],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Tilitapahtumat where id_Tilitapahtumat=?', [id], callback);
  },
  update: function(id, Tilitapahtumat, callback) {
    return db.query(
      'update Tilitapahtumat set name=?,author=?, isbn=? where id_Tilitapahtumat=?',
      [Tilitapahtumat.name, Tilitapahtumat.author, Tilitapahtumat.isbn, id],
      callback
    );
  }
};
module.exports = Tilitapahtumat;