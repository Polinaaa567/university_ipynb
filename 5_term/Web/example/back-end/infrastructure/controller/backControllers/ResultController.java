package infrastructure.controller.backControllers;

import app.CalcService;

public class ResultController {
    private CalcService calcService = new CalcService();

    int a = 2, b = 2;

    public String send() {
        System.out.println("Обработка метода send, должен отправлять результат вычислений");
        int result = calcService.calcadd(a, b);
        System.out.println(result);
        String response = a + " + " + b + " = " + result;
        System.out.println(response);
        return response;

    }
}
