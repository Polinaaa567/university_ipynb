function init(x, y, z) {
    u = (Math.max(x,y) + Math.max(x + y,z))/Math.pow(Math.max(0.5, x + z),2)
    return u;
}
console.log(init(1, 2, 3));
