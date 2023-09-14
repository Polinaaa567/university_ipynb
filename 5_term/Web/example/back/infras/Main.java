package infras;


import com.sun.net.httpserver.HttpServer;

import infras.controller.MyHandler;

import java.io.IOException;
import java.net.InetSocketAddress;

public class Main {
    public static void main(String[] args) throws IOException {
        MyHandler mh = new MyHandler();
        HttpServer server = HttpServer.create(new InetSocketAddress(90), 0);
        server.createContext("/", mh);
        server.setExecutor(null);
        server.start();
        System.out.println("Сервер запущен на порту 90");
    }

}
