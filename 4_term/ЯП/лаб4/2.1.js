let animal = { 
    jumps: null 
};
let rabbit = { 
    __proto__: animal, 
    jumps: true 
};

console.log(rabbit.jumps); // true, так как в объекте значение свойства было как true

delete rabbit.jumps;

console.log(rabbit.jumps); // null, так как после удаления свойства jumps, вывелось значение свойство объекта animal 

delete animal.jumps; 

console.log(rabbit.jumps); //undefined, так как ни в первом ни во втором объекте больше нету такого свойства 