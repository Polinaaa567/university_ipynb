package infrastructure.controller;

import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
import java.io.OutputStream;
import java.lang.String;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FrontController implements HttpHandler {

    @Override
    public void handle(HttpExchange exchange) throws IOException {

        exchange.getResponseHeaders().add("Access-Control-Allow-Headers", "Content-Type");

        System.out.println("Проверка");
        String body = exchange.getResponseBody().toString();

        System.out.println(body);

        String url = exchange.getRequestURI().getPath().toString();
        System.out.println(url);

        Map<String, List<String>> headers = exchange.getRequestHeaders();
        System.out.println(headers);

        Map<String, String> requestParams = queryToMap(exchange.getRequestURI().getQuery());
        System.out.println(requestParams);

        Router router = new Router();
        String result = router.selectURL(url, headers, requestParams, body);

        exchange.sendResponseHeaders(200, result.getBytes().length);
        OutputStream os = exchange.getResponseBody();
        os.write(result.getBytes());

        System.out.println("Отправили Routery: url, headers, requestParams, body ");
        System.out.println("Как слышно, Алло");
        os.close();

    }

    public Map<String, String> queryToMap(String query) {
        if (query == null) {
            return null;
        }
        Map<String, String> result = new HashMap<>();
        for (String param : query.split("&")) {
            String[] entry = param.split("=");
            if (entry.length > 1) {
                result.put(entry[0], entry[1]);
            } else {
                result.put(entry[0], "");
            }
        }
        return result;
    }

}