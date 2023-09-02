let hamster = { 
    stomach: [], 
    eat(food) { 
        this.stomach.push(food); 
    } 
}; 

let speedy = { 
    __proto__: hamster,
    stomach: [] //свой животик
}; 

let lazy = { 
    __proto__: hamster,
    stomach: [] //и у этого свой животик
}; 

// Этот хомяк нашёл еду 
speedy.eat("apple"); 
console.log(speedy.stomach); // apple 

// У этого хомяка тоже есть еда. Почему? Исправьте 
console.log(lazy.stomach); // apple