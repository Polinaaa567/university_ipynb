let n = Number(prompt());

let mas = new Array();

document.write("Matrix: <br>")
for(let i = 0; i < n; i++){
    mas[i] = new Array();
    for(let j = 0; j < n; j++){
        mas[i][j] = Math.floor(Math.random() * 10);
        document.write(mas[i][j] + "  ");
    }
    document.write("<br>")
}
