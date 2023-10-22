// console.log('Log:Starting');

(async () => { await true;

    console.log('Importing...');
    let routerModule = await import('./gui/route/RouterFactory.js');
    let router = routerModule.RouterFactory.createInstance();
    
    router.add('authentication', 'x-authentication');
    // router.add('calculation', 'calculation');

    router.default('authentication');

    router.go();
})();

// 'use strict'
// let log = false;
// let username;


// // Авторизация 
// function loginMain() {
//     let buttonNext = document.getElementById('next');
//     let inputLogin = document.getElementById('login');
//     let inputPassword = document.getElementById('password');

//     FunkaddEventListener(inputLogin, buttonNext, inputPassword);     
// }

// // Авторизация 
// async function FunkaddEventListener(inputLogin, buttonNext, inputPassword) {
//     buttonNext.addEventListener('click', async() =>{
//         let login = inputLogin.value;
//         let password = inputPassword.value;
                
//         if(!login) {
//             alert('Login is empty');
//         }

//         if(!password) {
//             alert('Password is empty');
//         }
        
//         buttonNext.setAttribute('disabled','');
//         log = await loginfetch(login, password);
//         buttonNext.removeAttribute('disabled');

//         if(log) {
//             username = login;
//             MainWindow();
//         } else {
//             alert('Login/Password is wrong');
//         }
//     });
// }

// // Список задач
// function MainWindow() {
//     document.body.innerHTML = '';
//     document.body.appendChild(createTable());
// }
 
// // Авторизация 
// async function loginfetch(username, password) {
//     let response = await fetch(`http://localhost:8080/example/api/authentication?username=${username}&password=${password}`, {method: 'GET'});
//     let content = await response.text();
           
//     return content === 'ok';
// }

// // Список задач
// async function calc(A, B) {            
//     let response = await fetch(`http://localhost:8080/example/api/calculation?a=${A}&b=${B}`, {method: 'GET'});
//     let content = await response.text();
    
//     return content;
// }

// window.onload = loginMain;

// 'use strict';

// class LoginApp extends HTNLElement {
//     constructor() {
//         super();
//         this.attachShadow({ mode: 'open' });
//         this.log = false;
//         this.username = '';
//     }
// }

// console.log('Log:Starting');

// (async ()=> { await true;
    
// console.log('Log:Importing');    
//     await import('./gui/component/x-input/component.js');
//     await import('./gui/component/x-label/component.js');

//     let LabelReg = document.createElement('x-label');
//     // LabelReg.appendChild(document.createTextNode('vbn'));

//     // let LabelReg = document.createElement('h1');
//     // LabelReg.textContent = 'REGISTRATION'

//     let loginInput = document.createElement('x-input');
//     loginInput.appendChild(document.createTextNode('login'));

//     let passwordInput = document.createElement('x-input');
//     passwordInput.appendChild(document.createTextNode('password'));

//     let nodeApp = document.getElementById('app');
//     nodeApp.appendChild(LabelReg);
//     nodeApp.appendChild(loginInput);
//     nodeApp.appendChild(passwordInput);
// })();