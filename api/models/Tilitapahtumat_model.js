const db = require('../database');

const Tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select PVM,saldonmuutos from Tilitapahtumat where Tili_idTili=? order by pvm desc limit 10', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Tilitapahtumat', callback);
  },
  add: function(Tilitapahtumat, callback) {
    return db.query(
      'insert into Tilitapahtumat (Tili_idTili, PVM, Saldonmuutos) values(?,CURRENT_TIMESTAMP,?)',
      [ Tilitapahtumat.Tili_idTili,  Tilitapahtumat.Saldonmuutos],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  update: function(Tili_idTili, Tilitapahtumat, callback) {
    return db.query(
      'update Tilitapahtumat set Tili_idTili=?, PVM=?, Saldonmuutos=? where idTilitapahtumat=?',
      [Tilitapahtumat.Tili_idTili, Tilitapahtumat.PVM, Tilitapahtumat.Saldonmuutos, idTilitapahtumat],
      callback
    );
  }
};
module.exports = Tilitapahtumat;