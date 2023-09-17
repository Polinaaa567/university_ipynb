let x = Number(prompt("Введите число "));
let y = Number(prompt("Введите число "));
let count = 0;
let res = 1;

while (count < y) { 
    res = res * x;
    count++;
}
document.write(res);