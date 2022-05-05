const db = require('../database');

const Credit = {

  update: function(id, Credit,callback) {
    return db.query(
      'call credit2(?,?)',
      [Credit.saldomuutos, Credit.tiliID],callback

    );
  },

}
module.exports = Credit;