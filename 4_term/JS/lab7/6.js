'use strict'

function merge(...res) {
    
    
    return [].concat(...res);
}

let result = merge([1, 2, 3], [4, 5, 6], [7, 8, 9]); 
console.log(result); // выведет [1, 2, 3, 4, 5, 6, 7, 8, 9] 
