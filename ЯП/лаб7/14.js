'use strict'

function func ([name, surname, department, position = 'джуниор']) {
    console.log(name, surname, department, position)
}

func(['John', 'Smit', 'development'])
    