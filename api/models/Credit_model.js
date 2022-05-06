const db = require('../database');

const Credit = {

  update: function(id, Credit,callback) {
    return db.query(
      'call credit3(?,?)',
      [Credit.saldomuutos, Credit.tiliID],callback

    );
  },

}
module.exports = Credit;