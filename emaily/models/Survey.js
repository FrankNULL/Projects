const mongooes = require('mongoose');
//const Schema = mongooes.Schema;
const { Schema } = mongooes;
const RecipientSchema = require('./Recipient');


const surveySchema = new Schema({
    title: String,
    body: String,
    subject: String,
    recipients: [RecipientSchema],
    yes : {type: Number, default : 0},
    no : {type: Number, default : 0},
    _user: {type : Schema.Types.ObjectId, ref : 'User'},
    dataSent: Date,
    lastResponded: Date
});

mongooes.model('surveys', surveySchema);