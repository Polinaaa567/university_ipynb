let variable = "Глобальная переменная";
function f() { 
    let variable = "Локальная переменная"; 
    console.log(variable); 
} 
f(); 
console.log(variable);