function f3() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            const ass = {
                a: 5,
                b: 10,
                Summ() {
                    return this.a + this.b
                }
            }
            console.log(`Промежуточный результат ${ass}`)
            resolve(ass)
        }, 2000)
    })
}


console.log('start')
f3(5, 6).
then((b)=>f3(b))
console.log('end')
