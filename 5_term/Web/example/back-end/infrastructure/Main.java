package infrastructure;


import com.sun.net.httpserver.HttpServer;

import infrastructure.controller.FrontController;

import java.io.IOException;
import java.net.InetSocketAddress;

public class Main {
    public static void main(String[] args) throws IOException {
        FrontController fc = new FrontController();
        HttpServer server = HttpServer.create(new InetSocketAddress(90), 0);
        server.createContext("/", fc);
        server.setExecutor(null);
        server.start();
        System.out.println("Сервер запущен на порту 90");
    }

}
