import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Product implements Serializable {
    public String name;
    public String data_of_manufacture;
    public Integer cost_product;

    Product(String name, String data_of_manufacture, Integer cost_product) {
        this.name = name;
        this.data_of_manufacture = data_of_manufacture;
        this.cost_product = cost_product;
    }
//***********
    public static String getPopularProduct(ArrayList<Order> listOrders)
    {
        Map<String, Integer> mapProducts = new HashMap<>();

        for (Order order : listOrders){
            for (Product product : order.list_products){
                if (mapProducts.containsKey(product.name)){
                    Integer count = mapProducts.get(product.name);
                    mapProducts.put(product.name, count+1);
                } else {
                    mapProducts.put(product.name, 1);
                }
            }
        }
        String popularProduct = "";
        Integer max = -1;

        for(String key: mapProducts.keySet()){
            Integer count = mapProducts.get(key);
            if (count > max){
                max = count;
                popularProduct = key;
            }
        }
        return popularProduct;
    }

}
