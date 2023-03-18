function recursiya(n){
    if (n <= 1){
        return 1;
    }
    return Math.sin(recursiya(n-1)) + 1;
} 

console.log(recursiya(3));
