package infras.controller;

// import app.CalcService;
// import dom.Calc;

import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
// import java.io.OutputStream;
import java.lang.String;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
// import java.util.Map;
import java.util.Map;
import java.util.regex.Pattern;

public class MyHandler implements HttpHandler {

    String url;
    // private CalcService calcService;

    // public MyHandler() {
    //     Calc calc = new Calc();
    //     this.calcService = new CalcService(calc);
    // }
// public static Map<String, List<String>> splitQuery(String query) {
//    if (query == null || "".equals(query)) {
//        return Collections.emptyMap();
//    }

//    return Pattern.compile("&").splitAsStream(query)
//            .map(s -> Arrays.copyOf(s.split("="), 2))
//            .collect(groupingBy(s -> decode(s[0]), mapping(s -> decode(s[1]), Stream.toList())));
// }
    @Override
    public void handle(HttpExchange exchange) throws IOException {
        // int a = 2;
        // int b = 2;

        // int result = calcService.calcadd(a, b);

        // String response = a + " + " + b + " = " + result;
        exchange.getResponseHeaders().add("Access-Control-Allow-Headers", "Content-Type");
        // exchange.sendResponseHeaders(200, response.getBytes().length);
        this.url = exchange.getRequestURI().getPath();
        // Map<String, String> params = exchange.getRequestURI().

        // OutputStream os = exchange.getResponseBody();
        System.out.println("Отправилось значение 4");
        System.out.println(url);
        
//         Map<String, List<String>> params = splitQuery(exchange.getRequestURI().getRawQuery());
// System.out.println(params);
        
        String os = exchange.getResponseBody().toString();
        System.out.println(os);


        // Map<String, String> headers = exchange.getRequestHeaders() ;
        // os.write(response.getBytes());
        // os.close();
        
    }

    public String geturl() {
        return url;
    }
}