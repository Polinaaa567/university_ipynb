export async function readFile (path) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(4) Readme file from ' + path + ' loaded'))
        }, Math.floor(Math.random() * 1000))  
    })
}