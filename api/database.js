const mysql = require('mysql');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'root',
  password: 'root1',
  database: 'test_db2'
});
module.exports = connection;