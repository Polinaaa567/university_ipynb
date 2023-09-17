// Добавление свойства по умолчанию к встроенному объекту
String.prototype.color = "black"; 
// Добавление (изменение) метода к встроенному объекту 

String.prototype.size = "15";

String.prototype.write = stringWrite; 

function stringWrite() { 
    console.log("Цвет текста: " + this.color); 
    console.log("Размер шрифта: " + this.size);
    console.log("Текст: " + this.toString());
} 
// используем измененный класс 
let s = new String("Это строка"); 
s.color = "red"; 
s.size = "18";
s.write();  

let s2 = new String("Вторая строка"); 
s2.write();
