'use strict'

function func ({color = 'black', width, height}) {
    console.log(color, width, height);
}

func({ color: 'red', width: 400, height: 500 })
    