const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'mysql',
  database: 'bankautomat'
});
module.exports = connection;