package local.arch.infrastructure.in.controller.rest.endpoint;

import jakarta.ws.rs.core.Response;
import jakarta.ws.rs.QueryParam;

public interface IController {	
	// boolean supports(String path, Method method);
	Response service(@QueryParam("username") String login, @QueryParam("password") String password);
}
