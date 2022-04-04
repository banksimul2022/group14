const express = require('express');
const router = express.Router();
const Asiakas = require('../models/Asiakas_model');

router.get('/:id?',
 function(request, response) {
  if (request.body.idAsiakas) {
    Asiakas.getById(request.body.idAsiakas, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    Asiakas.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  Asiakas.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id?', 
function(request, response) {
  Asiakas.delete(request.body.idAsiakas, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id?', 
function(request, response) {
  Asiakas.update(request.params.idAsiakas, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;