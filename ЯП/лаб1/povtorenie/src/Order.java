import java.io.Serializable;
import java.util.ArrayList;

public class Order implements Serializable {
    private Product product;
    public String data;
    public Integer cost;
    ArrayList<Product> list_products = new ArrayList<Product>();

    public Order(String data, Integer cost) {
        this.data = data;
        this.cost = cost;

    }
    void add_product(Product product){
        this.product = product;
        list_products.add(product);


    }

}
