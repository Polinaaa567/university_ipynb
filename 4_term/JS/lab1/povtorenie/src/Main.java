import java.util.ArrayList;
import java.io.*;


public class Main
{
    public static void main(String[] args) {
        Client client1 = new Client("Петров", "Петр", "Петрович", "01.01.2001", "Мужской");

        Order order1Client1 = new Order("02.02.2022", 20000);

        Product product1Order1Client1 = new Product("Стул", "14.10.21", 8000);
        order1Client1.add_product(product1Order1Client1);
        
        Product product2Order1Client1 = new Product("Стол", "19.11.21", 12000);
        order1Client1.add_product(product2Order1Client1);

        client1.new_order(order1Client1);

        Client client2 = new Client("Иванов", "Иван", "Иванович", "02.02.2002", "Мужской");


        Order order1Client2 = new Order("19.02.2022", 13000);


        Product product1Order1Client2 = new Product("Стул", "14.10.21", 8000);
        order1Client2.add_product(product1Order1Client2);

        Product product2Order1Client2 = new Product("Ковёр", "14.12.21", 5000);
        order1Client2.add_product(product2Order1Client2);

        client2.new_order(order1Client2);



        ArrayList<Order> listOrders = new ArrayList<>();
        listOrders.add(order1Client1);
        listOrders.add(order1Client2);

        System.out.println(Product.getPopularProduct(listOrders));

        try {
            FileOutputStream fos = new FileOutputStream(new File("C:\\Users\\ACER\\Desktop\\test.txt"));
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            // Запись объектов в файл
            oos.writeObject(client1);
            oos.writeObject(order1Client1);
            oos.writeObject(client2);
            oos.writeObject(order1Client2);
            oos.close();
            fos.close();
        }
        catch (IOException e){
            e.printStackTrace();
        }

        ArrayList<Employee> listEmployees = new ArrayList<>();

        Employee employee1 = new Employee("Отдел безопасности", "Системный администратор", 500000);
        Employee employee2 = new Employee("Отдел безопасности", "Ассистент системного администратора", 50000);

        listEmployees.add(employee1);
        listEmployees.add(employee2);

        System.out.println(Employee.count(listEmployees));

        ArrayList<Integer> listSalary = new ArrayList<>();

        listSalary.add(employee1.salary);
        listSalary.add(employee2.salary);

        System.out.println(Employee.totalSalary(listSalary));
        System.out.println(Employee.averageSalary(listSalary));


    }
}


