export async function doQuery (statement) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(console.log('(2) SQL query executed: ' + statement))
        }, Math.floor(Math.random() * 1000))
    })
}