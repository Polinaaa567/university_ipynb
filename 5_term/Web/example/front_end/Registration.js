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

            let calcF = document.createElement('div');
            calcF.setAttribute('id', 'calcF');
            let calclabel = document.createElement('h1');
            calclabel.innerHTML = 'Calculation';

            let calcButton = document.createElement('input');
            calcButton.setAttribute('type', 'button');
            calcButton.setAttribute('value', 'Calculation');
            calcButton.setAttribute('id', 'calcButton');
            
            let calcH2 = document.createElement('h2');
            calcF.append(calclabel, calcButton, calcH2);
            document.body.appendChild(calcF);

            FuncCalcButton(calcButton,calcH2 );
        }

        function FuncCalcButton(calcButton, calcH2) {
            calcButton.addEventListener("click", async () => {
                calcButton.setAttribute('disabled','');
                console.log(calc());
                calcH2.innerHTML = await calc();
                calcButton.removeAttribute('disabled');
            });
        }
        
        async function loginfetch(username, password) {
            let response = await fetch(`http://localhost:90/registration?username=${username}&password=${password}`);
            let content = await response.text();
           
            return content === 'OK';
        }

        async function calc() {
            let response = await fetch(`http://localhost:90/calcGet?`);
            let content = await response.text();
           console.log(content);
            return content;
        }

        window.onload = loginMain;