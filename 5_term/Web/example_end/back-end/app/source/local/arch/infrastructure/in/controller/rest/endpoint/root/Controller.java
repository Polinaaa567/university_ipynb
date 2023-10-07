package local.arch.infrastructure.in.controller.rest.endpoint.root;

import java.util.HashMap;

import local.arch.infrastructure.in.controller.rest.endpoint.Method;
import local.arch.infrastructure.in.controller.rest.endpoint.Request;
import local.arch.infrastructure.in.controller.rest.endpoint.Response;
import local.arch.infrastructure.in.controller.rest.endpoint.IController;


public class Controller implements IController {	
    
	@Override
	public boolean supports(String path, Method method) {	   
       return (  (path.equals("/")) && (method == Method.GET) ); 	
    }

    @Override
	public Response service(Request request) {       	
       Response response  = new Response();
	   response.Code = 200;
	   response.Headers = new HashMap<>();
	   response.Headers.put("Content-Type","text/plain; charset=UTF-8");
	   response.Body = "OK";
	   System.out.println(response);
	   return response;	   
    }      
}