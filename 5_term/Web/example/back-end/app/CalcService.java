package app;

import domain.*;

public class CalcService{
    private Calc calc;

    public int calcadd(int a, int b) {
        return calc.add(a, b);
    }
}
