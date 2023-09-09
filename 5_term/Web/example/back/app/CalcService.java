package app;

import dom.*;

public class CalcService{
    private Calc calc;

    public CalcService(Calc calc) {
        this.calc = calc;
    }

    public int calcadd(int a, int b) {
        return calc.add(a, b);
    }
}
