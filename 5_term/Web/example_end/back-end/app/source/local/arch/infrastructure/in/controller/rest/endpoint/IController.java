package local.arch.infrastructure.in.controller.rest.endpoint;


public interface IController {	
	boolean supports(String path, Method method);
	Response service(Request request);
}
