// window.onload = function() {   
//    console.log("Starting...");
//    test();  
// }


// async function act(title,root,path,payload) {
//     console.log(title);   
//     try {
//      let response = await fetch(root+path,payload);
//      let responseText = await response.text();
     
//      console.log('OK: ' + response.ok);   
//      console.log('Code: ' + response.status);        
//      console.log('Body: ' + responseText);
//     }
//     catch (error) {
//       console.log('Fatal error: ' + error);
//     }
// }



// async function test() {   
//    let root = 'http://localhost:9090/iks/api/v1';
    
//    await act('1. Ping:',  root, '/', {method: 'GET'});

//    await act('2. Hello:', root, '/calculation?filter=true&id=2', {method: 'GET'}); 

//    await act('3. Data:',  root, '/data', { method: 'GET'}
//    );   
// }


'use strict'
let log = false;
let username;


function loginMain() {
    let buttonNext = document.getElementById('next');
    let inputLogin = document.getElementById('login');
    let inputPassword = document.getElementById('password');

    FunkaddEventListener(inputLogin, buttonNext, inputPassword);
            
}

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

function MainWindow() {
    document.body.innerHTML = '';

            // let calcF = document.createElement('div');
            // calcF.setAttribute('id', 'calcF');
            // let calclabel = document.createElement('h1');
            // calclabel.innerHTML = 'Calculation';

            // let performButton = document.createElement('input');
            // performButton.setAttribute('type', 'button');
            // performButton.setAttribute('value', 'Результат');
            // performButton.setAttribute('id', 'perforbutton');
            
            // let calcH2 = document.createElement('h2');
            // calcF.append(calclabel, performButton, calcH2);
            // document.body.appendChild(calcF);
            
    document.body.appendChild(createTable());
}

        // function FuncCalcButton(performButton, calcH2) {
        //     performButton.addEventListener("click", async () => {
        //         performButton.setAttribute('disabled','');
                
        //         calcH2.innerHTML = await calc();
        //         performButton.removeAttribute('disabled');
        //     });
        // }
        //   function FuncCalcButton(buttonPerfom, labelResult) {
        //     buttonPerfom.addEventListener("click", async () => {
    
        //         buttonPerfom.setAttribute('disabled','');
        //         labelResult.innerHTML = await calc();
        //         buttonPerfom.removeAttribute('disabled');
        //     });
        // }
        
async function loginfetch(username, password) {
    let response = await fetch(`http://localhost:8080/example/api/authentication?username=${username}&password=${password}`, {method: 'GET'});
    let content = await response.text();
           
    return content === 'ok';
}

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
            buttonPerfom.setAttribute('disabled','');
            sum = await calc(inputA.value, inputB.value);
            buttonPerfom.removeAttribute('disabled');
            labelStatus.innerHTML = 'Выполняется';
            labelResult.innerHTML = '';
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
        