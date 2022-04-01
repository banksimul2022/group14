const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const user={
  get: function(callback) {
    return db.query('select * from Kortti', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from Kortti where idKortti=?', [id], callback);
  },
  add: function(user, callback) {
    bcrypt.hash(user.PIN, saltRounds, function(err, hash) {
      return db.query('insert into Kortti (idKortti, PIN) values(?,?)',
      [user.idKortti, hash], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from Kortti where idKortti=?', [id], callback);
  },
  update: function(id, user, callback) {
    bcrypt.hash(user.PIN, saltRounds, function(err, hash) {
      return db.query('update Kortti set idKortti=?, PIN=? where idKortti=?',
      [user.idKortti, hash, id], callback);
    });
  }

}