export class ApiService {
    // Авторизация 
    async loginfetch(username, password) {
        let response = await fetch(`http://localhost:8080/example/api/authentication?username=${username}&password=${password}`, {method: 'GET'});
        let content = await response.text();
            
        return content === 'ok';
    }

    // Список задач
    async calc(A, B) {            
        let response = await fetch(`http://localhost:8080/example/api/calculation?a=${A}&b=${B}`, {method: 'GET'});
        let content = await response.text();

        return content;
    }
}