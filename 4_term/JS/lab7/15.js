'use strict'

function func (department, [name, surname], [year, month, day]) {
    console.log(department);
    console.log(name, surname);
    console.log(year, month, day);

}
func('development', ['John', 'Smit'], [2018, 12, 31])
