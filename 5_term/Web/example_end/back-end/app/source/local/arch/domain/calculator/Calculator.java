package local.arch.domain.calculator;


import local.arch.domain.ICalculator;


public class Calculator implements ICalculator {
    
	@Override
	public double sum(double a, double b) {
        System.out.println(String.format("%s + %s",a, b));
       return a + b;  
    }    
}