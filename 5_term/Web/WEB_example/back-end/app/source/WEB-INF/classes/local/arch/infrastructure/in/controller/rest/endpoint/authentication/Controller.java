package local.arch.infrastructure.in.controller.rest.endpoint.authentication;

import java.util.HashMap;
import java.util.Map;

import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;

import jakarta.ws.rs.Produces;
import jakarta.ws.rs.Consumes;

import jakarta.ws.rs.core.Response;
import jakarta.ws.rs.QueryParam;

import javax.annotation.processing.Generated;

import local.arch.infrastructure.in.controller.rest.endpoint.IController;

import local.arch.infrastructure.builder.Builder;

import local.arch.application.IService;

@Path("/")
public class Controller implements IController {

	@GET
	@Path("/authentication")
	@Produces("text/plain")
	public Response service(@QueryParam("username") String login, @QueryParam("password") String password) {
		// @QueryParam("username")
		// String login;
		// @QueryParam("password")
		// String password;

		// Map<String, String> requestParams = request.Params;
		// String login = requestParams.get("username").toString();
		// String password = requestParams.get("password").toString();
		IService service = Builder.buildService();
		System.out.println(String.format("%s + %s", login, password));
		String check = service.check(login, password);

		// response.Code = 200;
		// response.Headers = new HashMap<>();
		// response.Headers.put("Content-Type", "text/plain; charset=UTF-8");
		// response.Body = check;
		// System.out.println(check);
		// System.out.println("check");
		return Response.ok(check).build();
	}
}