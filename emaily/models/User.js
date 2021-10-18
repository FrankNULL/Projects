const mongooes = require('mongoose');
//const Schema = mongooes.Schema;
const { Schema } = mongooes;

const userSchema = new Schema({
    googleId: String,
    credits: {type : Number, default: 0}
});

mongooes.model('users', userSchema);