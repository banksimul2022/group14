const express = require('express');
const router = express.Router();
const Credit = require('../models/Credit_model');


router.put('/:id?', 
function(request, response) {
  Credit.update(request.body.idTili, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});






module.exports = router;