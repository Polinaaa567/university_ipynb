package local.arch.infrastructure.out.storage;


import local.arch.application.IStorage;


public class Mock implements IStorage {	

	//private String[] greetings = {"Good morming","Good afternoon","Good evening"};	
	private double[] numbers = {0, 0};
	

	// @Override
	// public String[] reStoreGreetings() {
    //    return this.greetings;
	// }


    @Override
	public void storeNumbers(double[] numbers) {
        this.numbers = numbers;
	}
	
	@Override
	public double[] reStoreNumbers() {
		System.out.println(this.numbers);
        return this.numbers;
	}
}