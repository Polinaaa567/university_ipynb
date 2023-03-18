import java.util.ArrayList;

public class Employee extends Human {
    public Boolean job;
    public String subdivision;
    public String position;
    public Integer salary;

    public Employee(String subdivision, String position, Integer salary) {

        this.subdivision  = subdivision;
        this.position  = position;
        this.salary  = salary;
    }

    public static int count(ArrayList<Employee> listEmployees){

        return listEmployees.size();
    }
    public static int countSalary = 0;
    public static int totalSalary(ArrayList<Integer> listSalary){

        for (Integer integer : listSalary) {
            countSalary += integer;
        }
        return countSalary;
    }
    public static double averageSalary(ArrayList<Integer> listSalary){
        return countSalary/listSalary.size();
    }

    void hire(){
        job = true;
    }

    void dismissal(){
        job = false;
    }

}
