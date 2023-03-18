let a = [5, 4, 7, 2, 1]
let isSorted = true

for(var i = 0; i < a.length - 1; i++) {
    if(a[i] < a[i + 1]) {
        console.log(i + 2)
        isSorted = false
        break
    }    
}

if (isSorted) {
    for (var i = a.length - 1; i >= 0; i--) {
        console.log(a[i])
    }
}