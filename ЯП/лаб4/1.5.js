let obj = {
    name: "fmkd",
    age: 23,
    "number a": 45
}

function multiplyNumeric(obj) {
    for (let i in obj) {
        if(typeof obj[i] === 'number') {
            obj[i] *= 2
        }
    }
    console.log(obj)
}

multiplyNumeric(obj)