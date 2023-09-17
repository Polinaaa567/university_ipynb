let a = Array.from({
    length: 5
}, () => Math.trunc(Math.random() * 10));
console.log(a);

function Max() {
    c = a.indexOf(Math.min.apply(null,a))
    g = a.indexOf(Math.max.apply(null,a))
    
    b = a[c];

    a[c] = a[g];
    a[g] = b 
    console.log(a);
}

Max()