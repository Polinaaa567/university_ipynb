import java.io.Serializable;
import java.util.ArrayList;

public class Client extends Human implements Serializable {
    private Order order;
    ArrayList<Order> listOrders;


    public Client(String lastname, String firstname, String secondname, String date_of_birth, String gender) {
        super();
        this.listOrders = new ArrayList<Order>();
    }

    void new_order(Order order){
        this.listOrders.add(order);
    }
}
