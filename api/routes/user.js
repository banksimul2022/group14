const express = require('express');
const router = express.Router();
const user = require('../models/user_model');

router.get('/:id?',
 function(request, response) {
  if (request.body.idKortti) {
    user.getById(request.body.idKortti, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    user.getAll(function(err, dbResult) {
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
  user.add(request.body, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body); 
    }
  });
});

router.delete('/:id?', 
function(request, response) {
  user.delete(request.body.idKortti, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(count);
    }
  });
});


router.put('/:id?', 
function(request, response) {
  user.update(request.body.idKortti, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;