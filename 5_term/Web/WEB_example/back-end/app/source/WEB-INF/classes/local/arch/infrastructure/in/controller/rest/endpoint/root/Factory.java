package local.arch.infrastructure.in.controller.rest.endpoint.root;


import local.arch.infrastructure.in.controller.rest.endpoint.IFactory;
import local.arch.infrastructure.in.controller.rest.endpoint.IController;


public class Factory implements IFactory {	
    @Override
	public IController createInstance() {
        return new Controller();
    }      
}