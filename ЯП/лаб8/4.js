let number = Number(prompt("Enter the number "))

for (let i = 0; i <= Math.floor(Math.sqrt(number/2)); i++) {
    let j = Math.sqrt(number - i ** 2);
    if (j - Math.floor(j) == 0) document.write(i, " ", j );
}
