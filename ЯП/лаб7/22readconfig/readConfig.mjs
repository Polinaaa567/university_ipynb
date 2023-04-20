export async function readConfig (name) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(1) config from ' + name + ' loaded'))
        }, Math.floor(Math.random() * 1000))
    })
}