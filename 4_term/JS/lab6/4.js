let summ = function(value) {
    return new Promise(function(resolve, reject) {    
        setTimeout(() => {
            (typeof value[0] === 'number' && typeof value[1] === 'number') ? resolve([value[0] + value[1], value[1], value[2] + 1]) : reject('Error');
        }, 2000);
    })
};

// summ([4, 5, 0]).then(
//     response => {
//         console.log(response[0], response[2]);
//         return summ([response[0], 8, response[2]])
//     } 
    
// ).then(
//     response => {
        
//         console.log(response[0], response[2]);
//         return summ([response[0], 15,response[2]])
//     }
// ).then(
//     response => {
        
//         console.log(response[0], response[2]);
//         return summ([response[0], 2, response[2]])
//     }
// ).then(
//     response => {
        
//         console.log(response[0], response[2]);
//         return summ([response[0], 36, response[2]])
//     }
// ).then(
//     response => {
        
//         console.log(response[0], response[2]);
//         return summ([response[0], 4, response[2]])
//     }
// ).catch(
//     response => {
//         console.log(response);
//     }
// )

summ([4, '5', 0]).then(
    response => {
        console.log(response[0], response[2]);
        return summ([response[0], 8, response[2]])
    } 
    
).then(
    response => {
        
        console.log(response[0], response[2]);
        return summ([response[0], 15,response[2]])
    }
).then(
    response => {
        
        console.log(response[0], response[2]);
        return summ([response[0], 2, response[2]])
    }
).then(
    response => {
        
        console.log(response[0], response[2]);
        return summ([response[0], 36, response[2]])
    }
).then(
    response => {
        
        console.log(response[0], response[2]);
        return summ([response[0], 4, response[2]])
    }
).catch(
    response => {
        console.log(response);
    }
)