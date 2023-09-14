package infras.controller;

public class Router {
    public void selectURL(){
        MyHandler myHandler = new MyHandler();
        myHandler.geturl();

        switch (myHandler.geturl()) {
            case "/1.html":
                
                ;
        
            default:
                break;
        }
    }
    


}


