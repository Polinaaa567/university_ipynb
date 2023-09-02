function Calculator() {    
    this.read = function(a,b) {
        this.a = a
        this.b = b
    } 
    this.sum = function() {
        return this.a + this.b
    }

    this.mul = function() {
        return this.a * this.b
    }
}

let res = new Calculator()

res.read(11, 5)
console.log(res.sum())
console.log(res.mul())
