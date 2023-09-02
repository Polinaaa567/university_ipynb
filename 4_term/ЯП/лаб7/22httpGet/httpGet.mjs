export async function httpGet (url) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(3) Page retrieved: ' + url))
        }, Math.floor(Math.random() * 1000))       
    })
}