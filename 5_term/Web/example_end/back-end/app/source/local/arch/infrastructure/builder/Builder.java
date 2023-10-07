package local.arch.infrastructure.builder;


import local.arch.application.IStorage;
import local.arch.application.IService;
import local.arch.application.IStorageUsing;


public class Builder{	
    	
	public static IService buildService() {	  

       IStorage storage = local.arch.infrastructure.out.storage.Factory.createStorage();
	    
       IService service = local.arch.application.Factory.createService();
       ((IStorageUsing)service).useStorage(storage);	   

	   return service;
    }     
}