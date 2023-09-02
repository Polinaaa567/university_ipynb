'use strict';

async function func(volume) {
    return new Promise(resolve => setTimeout(resolve, volume))
}

async function interviews()
{   
    let number = 1;
    for (let i = 0; i < arguments.length; i++)
    {
        setTimeout(async()=> 
        {
            console.log(arguments[i][0], "started the", number, "task");
            await func(arguments[i][1] * 1000);
            
            console.log(arguments[i][0], "moved on to the defense of the", number, "task");
            await func(arguments[i][2] * 1000);
            
            console.log(arguments[i][0], "completed the", number, "task");
            
            console.log(arguments[i][0], "is resting");
            
            await func(5000);
            
            number = 2;
            
            console.log(arguments[i][0], "started the", number, "task");
            await func(arguments[i][3] * 1000);
            
            console.log(arguments[i][0], "moved on to the defense of the", number, "task");
            await func (arguments[i][4] * 1000);
            
            console.log(arguments[i][0], "completed the", number, "task");

        });
    }
}

interviews(['Ivan', 5, 2, 7, 2], ['John', 3, 4, 5, 1], ['Sophia', 4, 2, 5, 1]);
