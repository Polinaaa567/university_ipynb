let obj = {
    read(a, b) {
        this.a = a
        this.b = b
    },

    sum() {
        return this.a + this.b
    },
    
    mul() {
        return this.a * this.b
    }
}

obj.read(15, 5)
console.log(obj.sum())
console.log(obj.mul())