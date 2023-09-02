let a = [5, 4, 3, 2, -1]

for(var i = 0; i < a.length; i++) {
    if(i % 2 != 0 && a[i] > 0) {
        console.log(a[i] * 3)
    }    

    else if (i % 2 === 0 && a[i] < 0) {
        console.log(a[i] / 5 )
    }

    else {
        console.log(a[i])
    }
}