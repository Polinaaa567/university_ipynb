'use strict'

// let arr = [...12345]

// console.log(arr); //number 12345 is not iterable (cannot read property Symbol(Symbol.iterator))

let arr = [..."12345"]

console.log(arr);

//dsdjl [ '1', '2', '3', '4', '5' ]
