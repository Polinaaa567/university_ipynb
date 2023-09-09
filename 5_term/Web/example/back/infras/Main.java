package infras;

import app.*;
import dom.*;

public class Main {
    public static void main(String[] args) {
        Calc calc = new Calc();
        CalcService calcService = new CalcService(calc);

        int result = calcService.calcadd(2, 2);
        System.out.println(result);
    }
}
