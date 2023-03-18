function Rabbit() {} 
Rabbit.prototype = { 
    eats: true 
}; 

let rabbit = new Rabbit(); 
//Rabbit.prototype = {};  //true 
//Rabbit.prototype.eats = false; //false ссылаемся на созданный объект, а не на прототип
//delete rabbit.eats; //true, т.к. пытаемся удалить свойство из объекта rabbit, а там и так его нет//
 delete Rabbit.prototype.eats; //undefined удалили свойство у прототипа, поэтому при вызове его уже не существует 

console.log(rabbit.eats); // true 