package local.arch.domain;


import local.arch.domain.calculator.Calculator;


public class Factory {	
	public static ICalculator createCalculator() {
       return new Calculator();
	}
}