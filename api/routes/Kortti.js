const express = require('express');
const router = express.Router();
const Kortti = require('../models/Kortti_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    Kortti.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    Kortti.getAll(function(err, dbResult) {
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
  Kortti.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id?', 
function(request, response) {
  Kortti.delete(request.body.idKortti, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
router.get('/userid/:korttinumero?', 
function(request, response) {
  Kortti.getID(request.params.korttinumero, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});



router.put('/:id?', 
function(request, response) {
  Kortti.update(request.body.idKortti, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});



module.exports = router;