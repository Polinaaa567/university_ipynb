function recursiya(x){
    if (x <= 1){
        return 1;
    }
    return recursiya(x - 1) + recursiya(x - 2);
} 
var n = Number(prompt("Enter the number n "))
document.write(recursiya(n));
