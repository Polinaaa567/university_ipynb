package infras;

import app.CalcService;
import dom.Calc;

import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
import java.io.OutputStream;

class MyHandler implements HttpHandler {
    private CalcService calcService;

    public MyHandler() {
        Calc calc = new Calc();
        this.calcService = new CalcService(calc);
    }

    @Override
    public void handle(HttpExchange exchange) throws IOException {
        int a = 2;
        int b = 2;

        int result = calcService.calcadd(a, b);

        String response = a + " + " + b + " = " + result;
        exchange.sendResponseHeaders(200, response.getBytes().length);
        OutputStream os = exchange.getResponseBody();
        System.out.println("Отправилось значение 4");
        os.write(response.getBytes());
        os.close();
    }
}