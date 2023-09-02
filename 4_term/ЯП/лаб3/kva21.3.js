let a = [
    [4, 8, 5, 9],
    [4, 1, 5, 5.8]
]

function sum() {
    let sum = 0
    for(var i = 0; i < a.length; i++) {
        let max1 = 0
        
        for(var j = 0; j < a[i].length; j++) {       
            if(a[i][j] > max1) {
                max1 = a[i][j]
            }
        }
        sum += max1    
    }
    console.log(sum)
}

function proizv() {
    let proizvedenie = 1
    for(var j = 0; j < a[0].length; j++) {
        let max2 = 0 

        for(var i = 0; i < a.length; i++) {
            if(a[i][j] > max2) {
                max2 = a[i][j]
            }
        }
        proizvedenie *= max2
    }
    console.log(proizvedenie)
}

sum();
proizv();