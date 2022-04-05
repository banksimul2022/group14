const express = require('express');
const router = express.Router();
const Tilitapahtumat = require('../models/Tilitapahtumat_model');

router.get('/:id?',
 function(request, response) {
  if (request.body.idTilitapahtumat) {
    Tilitapahtumat.getById(request.body.idTilitapahtumat, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    Tilitapahtumat.getAll(function(err, dbResult) {
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
  Tilitapahtumat.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id?', 
function(request, response) {
  Tilitapahtumat.delete(request.body.idTilitapahtumat, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id?', 
function(request, response) {
  Tilitapahtumat.update(request.body.idTilitapahtumat, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;