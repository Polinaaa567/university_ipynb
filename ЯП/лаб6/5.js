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

// Await()


// const x = 3

// async function f1() {
//     return new Promise ((resolve, reject) => {
//         setTimeout(() => {
//             const NewRes = x ** 2;
//             console.log(`Промежуточный результат ${NewRes}`);
//             resolve(NewRes);
//         }, 0)
//     })
// }

// async function f2(OldRes) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             let NewRes = OldRes + x * 2;
//             console.log(`Pезультат n = 2: ${NewRes}`)
//             resolve(NewRes)
//         }, 0)
//     })
// }

// async function f3(OldRes) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             let NewRes = OldRes - 2;
//             console.log(`Промежуточный результат ${NewRes}`)
//             resolve(NewRes)
//         }, 1000)
//     })
// }

// async function f4(OldRes) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             let NewRes = OldRes ** 3;
//             console.log(`Pезультат при n = 4: ${NewRes}`)
//             resolve(NewRes)
//         }, 10000)
//     })
// }

// async function f5(OldRes) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             let NewRes = OldRes * 3;
//             console.log(`Промежуточный результат ${NewRes}`)
//             resolve(NewRes)
//         }, 1000)
//     })
// }

// async function f6(OldRes) {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             let NewRes = OldRes - 3;
//             console.log(`Pезультат при n = 6: ${NewRes}`)
//             resolve(NewRes)
//         }, 1000)
//     })
// }

// async function Await(){
//     await true
//     // Вызов функций
//     console.log('start')
//     const readc = await f1();
//     const NewRes = await f2(readc)
//     const newRes2 = await f3(NewRes)
//     const newRes3 = await f4(newRes2)
//     const newRes4 = await f5(newRes3)
//     await f6(newRes4)
//     console.log('end')    
// }

// Await()


const summ = async (value) => {
    let res = [...value];
    if (typeof res[0] !== 'number' || typeof res[1] !== 'number' || !Array.isArray(value) || value.length !== 3) {
        throw "Error";
    }
    res = [res[0] + res[1], res[1], res[2] + 1];
    return res;
};


let res = [4, 5, 0];
let count = 0;
const interval = setInterval(async () => {
    try {
        res = await summ(res);
        console.log(res[0], res[2]);
        count++;
        if (count === 5) {
            clearInterval(interval);
        }
    } catch (error) {
        console.log(error);
        clearInterval(interval);
    }
}, 2000);
