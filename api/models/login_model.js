const db = require('../database');

const login={
  checkPIN: function(idKortti, callback) {
      return db.query('select PIN from kortti where idkortti= ?',[idKortti], callback); 
    }
};
          
module.exports = login;