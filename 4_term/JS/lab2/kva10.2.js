var age = Number(prompt("Сколько вам лет? "))
if (age <= 17 && age >= 1) {
    document.write("Для детей");
}
else if (age >= 18 && age <= 30) {
    document.write("Для молодёжи");
}
else {
    document.write("Для всех возрастов");
}

