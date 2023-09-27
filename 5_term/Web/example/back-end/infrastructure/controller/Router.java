package infrastructure.controller;

import java.util.List;
import java.util.Map;

import infrastructure.controller.backControllers.LoginController;
import infrastructure.controller.backControllers.ResultController;

public class Router {
    public String selectURL(String url, Map<String, List<String>> headers, Map<String, String> requestParams,
            String body) {
        System.out.println("Начало работы методы selectURL");
        if (url.equals("/registration")) {
                System.out.println("Если url = /registration");
                System.out.println("Вызывается метод из 1-го backController = loginControl.check()");
                String login = requestParams.get("username").toString();
                String password = requestParams.get("password").toString();
                LoginController isTrue = new LoginController();
                if (isTrue.check(login, password)) {
                    return "OK";
                }
        }
        else if (url.equals("/calcGet")) {
                System.out.println("Если url = /calcGet");
                ResultController resultController = new ResultController();
                String calculation = resultController.send();
                System.out.println("Вызывается метод из 2-го backController = resultController.send()");

                return calculation;
            }
        return " ";
        }
    }

