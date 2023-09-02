let a = [1, 2, 5, 4, 6]
let b = [8, 2, 5, 9, 5]

let l =  a.length + b.length;

let n = a.concat(b)
n.sort()

function test() {
    if (l % 2 == 0) {
        console.log((n[l / 2] + n[(l / 2) + 1]) / 2)
    } else {
        console.log(n[Math.trunc(l / 2)])
    }
}
console.log(n)

test()