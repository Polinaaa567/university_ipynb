const x = 3

async function f1() {
    return new Promise ((resolve, reject) => {
        setTimeout(() => {
            const NewRes = x ** 2;
            console.log(`Промежуточный результат ${NewRes}`);
            resolve(NewRes);
        }, 0)
    })
}

async function f2(OldRes) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            let NewRes = OldRes + x * 2;
            console.log(`Pезультат n = 2: ${NewRes}`)
            resolve(NewRes)
        }, 0)
    })
}

async function f3(OldRes) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            let NewRes = OldRes - 2;
            console.log(`Промежуточный результат ${NewRes}`)
            resolve(NewRes)
        }, 1000)
    })
}

async function f4(OldRes) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            let NewRes = OldRes ** 3;
            console.log(`Pезультат при n = 4: ${NewRes}`)
            resolve(NewRes)
        }, 10000)
    })
}

async function f5(OldRes) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            let NewRes = OldRes * 3;
            console.log(`Промежуточный результат ${NewRes}`)
            resolve(NewRes)
        }, 1000)
    })
}

async function f6(OldRes) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            let NewRes = OldRes - 3;
            console.log(`Pезультат при n = 6: ${NewRes}`)
            resolve(NewRes)
        }, 1000)
    })
}

console.log('start')
f1().
then((a)=>f2(a)).
then((NewRes)=>f3(NewRes)).
then((NewRes)=>f4(NewRes)).
then((NewRes)=>f5(NewRes)).
then((NewRes)=>f6(NewRes))

console.log('end')