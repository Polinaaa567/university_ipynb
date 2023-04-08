function F(x)
{
    f1(x);
}

function f1(x) {

    setTimeout(() => {
        let result = x**2;
        console.log(`Промежуточный результат ${result}`);
        f1Notify(x, result)
    }, 1000)
}

function f1Notify(x, result) {
    f2(x, result)
}

function f2(x, result) {
    setTimeout(() => {
        let res = result + x * 2;
        console.log(`Промежуточный результат ${res}`)
        f2Notify(x, res)
    }, 1000)
}

function f2Notify(x, result) {
    console.log(`Pезультат при n = 2: ${result}`)
    f3(x, result)
}

function f3(x, result) {
    setTimeout(() => {
        let res = result - 2;
        console.log(`Промежуточный результат ${res}`)
        f3Notify(x, res)
    }, 1)
}

function f3Notify(x, result) {
    f4(x, result)
}

function f4(x, result) {
    setTimeout(() => {
        let res = result ** 3
        console.log(`Промежуточный результат ${res}`)
        f4Notify(x, res)
    }, 1000)
}

function f4Notify(x, result) {
    console.log(`Pезультат при n = 4: ${result}`)
    f5(x, result)
}

function f5(x, result) {
    setTimeout(() => {
        let res = result * 3
        console.log(`Промежуточный результат ${res}`)
        f5Notify(x, res)
    }, 1000)
}

function f5Notify(x, result) {
    f6(x, result)
}

function f6(x, result) {
    setTimeout(() => {
        let res = result - 3
        console.log(`Промежуточный результат ${res}`)
        f6Notify(x, res)
    }, 1000)
}
function f6Notify(x, result) {
    console.log(`Pезультат при n = 6: ${result}`)

}

console.log('start')
F(3);
console.log('end')