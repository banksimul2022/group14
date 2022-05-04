const db = require('../database');

const login={
  checkPIN: function(korttinumero, callback) {
      return db.query('select PIN from kortti where korttinumero= ? AND lukko=0',[korttinumero], callback); 
    }
};

module.exports = login;
