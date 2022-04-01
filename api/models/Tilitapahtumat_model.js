const db = require('../database');

const Tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from Tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Tilitapahtumat', callback);
  },
  add: function(Tilitapahtumat, callback) {
    return db.query(
      'insert into Tilitapahtumat (Tili-idTili, PVM, Kellonaika, Saldonmuutos) values(?,?,?,?)',
      [ Tilitapahtumat.Tili_idTili, Tilitapahtumat.PVM, Tilitapahtumat.Kellonaika, Tilitapahtumat.Saldonmuutos],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  update: function(id, Tilitapahtumat, callback) {
    return db.query(
      'update Tilitapahtumat set Tili_idTili=?, PVM=?, Kellonaika=?, Saldonmuutos=? where idTilitapahtumat=?',
      [Tilitapahtumat.Tili_idTili, Tilitapahtumat.PVM, Tilitapahtumat.Kellonaika, Tilitapahtumat.Saldonmuutos, id],
      callback
    );
  }
};
module.exports = Tilitapahtumat;