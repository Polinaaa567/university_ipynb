// Асинхронные функции
function readConfig (name, callback) {
    setTimeout(() => {
        console.log('(1) config from ' + name + ' loaded')
        callback()
    }, Math.floor(Math.random() * 1000))
}

function readConfigNotify() {
    doQuery('select * from cities', doQueryNotify);
}

function doQuery (statement, callback) {
    setTimeout(() => {
        console.log('(2) SQL query executed: ' + statement)
        callback()
    }, Math.floor(Math.random() * 1000))
}

function doQueryNotify (){
    httpGet('http://google.com', httpGetNotify);
}

function httpGet (url, callback) {
    setTimeout(() => {
        console.log('(3) Page retrieved: ' + url)
        callback()
    }, Math.floor(Math.random() * 1000))
}

function httpGetNotify() {
    readFile('README.md', callback)
}

function readFile (path, callback) {
    setTimeout(() => {
        console.log('(4) Readme file from ' + path + ' loaded')
        callback()
    }, Math.floor(Math.random() * 1000))
}

function callback () {
    console.log('It is done!')
}
// Вызов функций
console.log('start')

//a
// readConfig('myConfig', () => {
//     doQuery('select * from cities', () => {
//         httpGet('http://google.com', () => {
//             readFile('README.md', callback)
//         })
//     })
// })

//b
readConfig('myConfig', readConfigNotify);

console.log('end')