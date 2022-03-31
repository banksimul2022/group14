const mysql = require('mysql');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'bankuser',
  password: 'bank',
  database: 'bank'
});
module.exports = connection;