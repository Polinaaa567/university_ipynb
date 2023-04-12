// Асинхронные функции
async function readConfig (name) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(1) config from ' + name + ' loaded'))
        }, Math.floor(Math.random() * 10000))
    })
}

async function doQuery (statement) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(2) SQL query executed: ' + statement))
        }, Math.floor(Math.random() * 1000))
    })
}

async function httpGet (url) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(3) Page retrieved: ' + url))
        }, Math.floor(Math.random() * 1000))       
    })
}

async function readFile (path) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(4) Readme file from ' + path + ' loaded'))
        }, Math.floor(Math.random() * 1000))  
    })
}

// Вызов функций
console.log('start')

readConfig('myConfig').
then(()=>doQuery('select * from cities')).
then(()=>httpGet('http://google.com')).
then(()=>readFile('README.md')).
catch(()=>console.log('end'))

console.log('end')
