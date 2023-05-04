let n = prompt()
let numbers = []
for (i = 0 ; i<n; i++) {
    numbers.pop(Math.random())

    if (numbers.length === 5){
        document.write(numbers.reverse())
        numbers = []
    }
}

