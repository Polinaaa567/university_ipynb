package infras;

import com.sun.net.httpserver.HttpServer;

import java.io.IOException;
import java.net.InetSocketAddress;

// import app.*;
// import dom.*;

public class Main {
    public static void main(String[] args) throws IOException {
        MyHandler mh = new MyHandler();

        HttpServer server = HttpServer.create(new InetSocketAddress(90), 0);
        server.createContext("/", mh);
        server.setExecutor(null);
        server.start();
        System.out.println("Сервер запущен на порту 90");

        // Calc calc = new Calc();
        // CalcService calcService = new CalcService(calc);

        // int result = calcService.calcadd(2, 2);
        // System.out.println(result);
    }

}
