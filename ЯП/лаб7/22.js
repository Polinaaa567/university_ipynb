// // Асинхронные функции
// async function readConfig (name) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve(console.log('(1) config from ' + name + ' loaded'))
//         }, Math.floor(Math.random() * 1000))
//     })
// }

// async function doQuery (statement) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve(console.log('(2) SQL query executed: ' + statement))
//         }, Math.floor(Math.random() * 1000))
//     })
// }

// async function httpGet (url) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve(console.log('(3) Page retrieved: ' + url))
//         }, Math.floor(Math.random() * 1000))       
//     })
// }

// async function readFile (path) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve(console.log('(4) Readme file from ' + path + ' loaded'))
//         }, Math.floor(Math.random() * 1000))  
//     })
// }

// async function Await(){
//     await true
//     // Вызов функций
//     console.log('start')
//     await readConfig('myConfig');
//     await doQuery('select * from cities')
//     await httpGet('http://google.com')
//     await readFile('README.md')    
//     console.log('end')    
// }