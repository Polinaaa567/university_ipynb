function ask_password(login, password, success, failure) {
    let vowels = ["a", "e", "i", "o", "u", "y"];
    let consonants = ["b", "c", "d", "f", "g", "h", "j", "k", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z"];
    let countV = 0;
    let countC = 0;

    for (const key in password) {
        const letter = password[key];
        if(password.length === 6) {
            if (vowels.includes(letter) && login.includes(letter)){
                countV += 1;
            }
            else if (consonants.includes(letter) && login.includes(letter)){
                countC += 1;
            }
            
        }
    }

    if (countV === 3 && countC === 3) {
        success(login);
    }
    else if (countC != 3) {
        failure(login, "Wrong consonants");
    } 
    else if (countV != 3) {
        failure(login, "Wrong number of vowels");
    } else {
        failure(login, "Everything is wrong");
    }
}

function main(login, password) {
    ask_password(login, password, function(log) {
        console.log(`Привет, ${login}!`);
        },
        
        function(log, msg) {
            console.log(`Кто-то пытался притвориться пользователем ${log}, но в пароле допустил ошибку: ${msg.toUpperCase()}`);
        });
} 

main("iqwery123", "iqwfgvjhbky");