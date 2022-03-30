const db = require('../database');

const login={
  checkPassword: function(idKortti, callback) {
      return db.query('select * from asiakas  JOIN Asiakas_tili on asiakas.idAsiakas=asiakas.idasiakas join tili on asiakas_tili.idtili=tili.idtili join kortti on tili.idtili=kortti.tili_idtili',[idKortti], callback); 
    }
};
          
module.exports = login;