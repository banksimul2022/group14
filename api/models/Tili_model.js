const db = require('../database');

const Tili = {
  getById: function(idTili, callback) {
    return db.query('select idtili, saldo, credit from Tili where idTili=?',
     [idTili], callback);
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
  delete: function(idTili, callback) {
    return db.query('delete from Tili where idTili=?', [idTili], callback);
  },
  update: function(id, Tili,callback) {
    return db.query(
      'call otto10(?,?)',
      [Tili.saldomuutos, Tili.tiliID],callback

    );
  },

}
module.exports = Tili;