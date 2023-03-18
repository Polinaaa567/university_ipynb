function test(x1, x2, x3, y1, y2, y3) {
    return Math.abs((x2-x1) * (y3 - y1) -(x3 - x1) * (y2 - y1)) / 2
}

console.log(test(-1, 3, 1, 0, 0, 4))