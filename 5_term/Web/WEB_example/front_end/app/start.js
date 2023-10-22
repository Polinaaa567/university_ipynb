'use strict'
let log = false;
let username;


// Авторизация 
function loginMain() {
    let buttonNext = document.getElementById('next');
    let inputLogin = document.getElementById('login');
    let inputPassword = document.getElementById('password');

    FunkaddEventListener(inputLogin, buttonNext, inputPassword);     
}

// Авторизация 
async function FunkaddEventListener(inputLogin, buttonNext, inputPassword) {
    buttonNext.addEventListener('click', async() =>{
        let login = inputLogin.value;
        let password = inputPassword.value;
                
        if(!login) {
            alert('Login is empty');
        }

        if(!password) {
            alert('Password is empty');
        }
        
        buttonNext.setAttribute('disabled','');
        log = await loginfetch(login, password);
        buttonNext.removeAttribute('disabled');

        if(log) {
            username = login;
            MainWindow();
        } else {
            alert('Login/Password is wrong');
        }
    });
}

// Список задач
function MainWindow() {
    document.body.innerHTML = '';
    document.body.appendChild(createTable());
}
 
// Авторизация 
async function loginfetch(username, password) {
    let response = await fetch(`http://localhost:8080/example/api/authentication?username=${username}&password=${password}`, {method: 'GET'});
    let content = await response.text();
           
    return content === 'ok';
}

// Список задач
async function calc(A, B) {            
    let response = await fetch(`http://localhost:8080/example/api/calculation?a=${A}&b=${B}`, {method: 'GET'});
    let content = await response.text();
    
    return content;
}

window.onload = loginMain;
        // создание таблицы задач
const createTable = () => {
    const table = document.createElement('table');
    table.className = "tableCalc";
            // Работа с заголовками
    const headers_tr = document.createElement('tr');
    const headers = ['Введите 2 числа', 'Выполнить', 'Результат', 'Удалить', 'Статус', '']
    headers.forEach(header => {const th = document.createElement('th');
        th.textContent = header;
        headers_tr.appendChild(th);
    });

    table.appendChild(headers_tr);

    const appendButton = document.createElement('button');
    appendButton.className = "appendButton";
    appendButton.textContent = 'Добавить';
    appendButton.setAttribute = ('id','appendButton');
    appendButton.addEventListener("click", async () => {
        const tr = document.createElement('tr');
            
        // 1ый столбец
        const td1 = document.createElement('td');
            
        const inputA = document.createElement('input');
        inputA.setAttribute('id', 'inputA');
            
        const labelPlus = document.createElement('label');
        labelPlus.innerHTML = "+";
            
        const inputB = document.createElement('input');
        inputB.setAttribute('id', 'inputB');
        td1.append(inputA, labelPlus, inputB);

        // 2ой столбец
        const td2 = document.createElement('td');
            
        const buttonPerfom = document.createElement('button');
        buttonPerfom.textContent = "▶";
        buttonPerfom.setAttribute('id', 'buttonPerfom');
        td2.append(buttonPerfom);
                    
        // 3ий столбец
        const td3 = document.createElement('td');
        const labelResult = document.createElement('label');
        td3.append(labelResult);

        // 4ый столбец    
        const td4 = document.createElement('td');    
            
        const buttonDelete = document.createElement('button');
        buttonDelete.textContent = "🚯♻️"; 
        td4.append(buttonDelete);

        buttonDelete.addEventListener("click", () => {
            table.removeChild(tr);
        });
        
        // 5ый столбец
        const td5 = document.createElement('td');
        const labelStatus = document.createElement('label');
        td5.append(labelStatus);

        // 6ой столбец    
        const td6 = document.createElement('td');

        const refreshButton = document.createElement('button');
        refreshButton.textContent = "🔄";
        td6.append(refreshButton);
    
        tr.append(td1, td2, td3, td4, td5, td6);
        table.appendChild(tr);

        let sum;

        buttonPerfom.addEventListener("click", async () => {
            if(!inputA.value || !inputB.value || isNaN(inputA.value) || isNaN(inputB.value)){
                alert("Please enter a number");
            }
            else{
                buttonPerfom.setAttribute('disabled','');
                sum = await calc(inputA.value, inputB.value);
                buttonPerfom.removeAttribute('disabled');
                labelStatus.innerHTML = 'Выполняется';
                labelResult.innerHTML = '';
            }
        });

        refreshButton.addEventListener('click', async() => {
            if (labelStatus.innerHTML === 'Выполняется') {
                labelStatus.innerHTML = 'Готово';
                labelResult.innerHTML = sum;
            }
        });
    });

    document.body.appendChild(appendButton);
    return table;
}
        