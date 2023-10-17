package local.arch.infrastructure.in.controller.rest.endpoint.authentication;

import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;

import jakarta.ws.rs.Produces;

import jakarta.ws.rs.core.Response;
import jakarta.ws.rs.QueryParam;

import local.arch.infrastructure.builder.Builder;

import local.arch.application.IService;

@Path("/")
public class Controller {

	@GET
	@Path("/authentication")
	@Produces("text/plain")
	public Response service(@QueryParam("username") String login,
							@QueryParam("password") String password) 
	{
		IService service = Builder.buildService();
		System.out.println(String.format("%s + %s", login, password));
		String check = service.check(login, password);

		return Response.ok(check).build();
	}
}