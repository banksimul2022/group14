const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const user={
  get: function(callback) {
    return db.query('select * from user_table', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from user_table where id_user=?', [id], callback);
  },
  add: function(user, callback) {
    bcrypt.hash(user.PIN, saltRounds, function(err, hash) {
      return db.query('insert into user_table (idKortti, PIN) values(?,?)',
      [user.idKortti, hash], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from user_table where id_user=?', [id], callback);
  },
  update: function(id, user, callback) {
    bcrypt.hash(user.PIN, saltRounds, function(err, hash) {
      return db.query('update user_table set idKortti=?, PIN=? where id_user=?',
      [user.idKortti, hash, id], callback);
    });
  }

}
          
module.exports = user;