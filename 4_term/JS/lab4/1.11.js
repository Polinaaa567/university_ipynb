function Accumulator(stringValue) {
    this.value = stringValue;

    this.read = function(a) {
        this.a = a
        this.value +=  +this.a;
    }

}

let res = new Accumulator(1);

res.read(7)
res.read(9)

console.log(res.value)
