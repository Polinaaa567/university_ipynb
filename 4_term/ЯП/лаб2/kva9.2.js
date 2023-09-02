let x = String(prompt("Введите email " ))
if (x.includes("@")) {
    console.log(x)
} else {
    console.log('please enter a valid email')
}