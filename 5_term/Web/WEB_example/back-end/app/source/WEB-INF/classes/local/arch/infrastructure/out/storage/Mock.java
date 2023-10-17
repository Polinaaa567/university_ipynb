package local.arch.infrastructure.out.storage;


import local.arch.application.IStorage;


public class Mock implements IStorage {	

	private double[] numbers = {0, 0};


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