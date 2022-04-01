const db = require('../database');

const Tili = {
  getById: function(id, callback) {
    return db.query('select * from Tili where idTili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Tili', callback);
  },
  add: function(Tili, callback) {
    return db.query(
      'insert into Tili (Saldo, Credit, Luottoraja) values(?,?,?)',
      [Tili.Saldo, Tili.Credit, Tili.Luottoraja],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Tili where idTili=?', [id], callback);
  },
  update: function(id, Tili, callback) {
    return db.query(
      'update Tili set Saldo=?, Credit=?, Luottoraja=? where idTili=?',
      [Tili.Saldo, Tili.Credit, Tili.Luottoraja, id],
      callback
    );
  }
};
module.exports = Tili;