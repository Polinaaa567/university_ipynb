'use strict'

function unite(...res) {
    return res;
}

let result = unite([1, 2, 3], [4, 5, 6], [7, 8, 9]); 
console.log(result); // выведет [ [1, 2, 3,] [4, 5, 6], [7, 8, 9] ]