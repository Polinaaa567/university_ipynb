'use strict'

function mean(...values) {
    let sr_znac =0
    
    for (let arg of values) {
        sr_znac = (sr_znac + arg)
    }
    console.log(sr_znac/values.length)
}

mean(1,5,3,4)