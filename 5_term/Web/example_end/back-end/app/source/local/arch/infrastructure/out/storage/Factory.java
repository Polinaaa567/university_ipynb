package local.arch.infrastructure.out.storage;


import local.arch.application.IStorage;


public class Factory{	
    private static IStorage instance = null;

	public static IStorage createStorage() {
        if (instance == null) {
          instance = new Mock();
        }          
        return instance;
    }
}    