const mongooes = require('mongoose');
//const Schema = mongooes.Schema;
const { Schema } = mongooes;

const recipientSchema = new Schema({
    email: String,
    responded: {type: Boolean, default : false}
});

module.exports = recipientSchema;