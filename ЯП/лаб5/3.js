function F(x)
{
    f1(x);
}

function f1(x) {

    setTimeout(() => {
        let result = x**2;
        console.log(result)
        f1Notify(x, result)
    }, 0)
}

function f1Notify(x, result) {
    f2(x, result)
}

function f2(x, result) {
    setTimeout(() => {
        let res = result + x * 2;
        console.log(res)
        f2Notify(x, res)
    }, 0)
}

function f2Notify(x, result) {
    f3(x, result)
}

function f3(x, result) {
    setTimeout(() => {
        let res = result - 2;
        console.log(res)
        f3Notify(x, res)
    }, 0)
}

function f3Notify(x, result) {
    console.log(x, result)
}

console.log('start')
F(3);
console.log('end')