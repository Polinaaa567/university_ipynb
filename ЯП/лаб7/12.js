'use strict'

function func () {
    return new Date().getDate()
}
    
function func1() {
    return new Date().getMonth() + 1
}

function func2() {
    return new Date().getFullYear()
}

let [year = func2(), month = func1(), day = func()] = []

console.log(year, month, day)