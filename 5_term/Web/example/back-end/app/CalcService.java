package app;

import domain.Calc;

public class CalcService {
    private Calc calc = new Calc();

    public int calcadd(int a, int b) {
        return calc.add(a, b);
    }
}
