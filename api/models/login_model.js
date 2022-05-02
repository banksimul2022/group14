const db = require('../database');

const login={
  checkPIN: function(korttinumero, callback) {
      return db.query('select PIN from kortti where korttinumero= ?',[korttinumero], callback); 
    }
};

module.exports = login;
