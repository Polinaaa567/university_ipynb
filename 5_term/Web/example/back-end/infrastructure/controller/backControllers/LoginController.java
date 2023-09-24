package infrastructure.controller.backControllers;

public class LoginController {
    String login = "qwerty";
    String password = "12345678";

    public boolean check(String login, String password) { // String password
        System.out.println("Обработка метода check, должен проверять логин и отправлять ок, если правильный");
        System.out.println(login);
        System.out.println(password);
        if (login.equals(this.login ) && password.equals(this.password)) { // && password == this.password
            //// проверка логина и отправка ок
            return true;
        }

        return false;

    }
}
