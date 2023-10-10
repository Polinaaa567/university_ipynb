package local.arch.infrastructure.in.controller.rest.endpoint.root;

import java.util.HashMap;

import local.arch.infrastructure.in.controller.rest.endpoint.IController;

import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;

import jakarta.ws.rs.Produces;

import jakarta.ws.rs.core.Response;
import jakarta.ws.rs.QueryParam;

import javax.annotation.processing.Generated;

import local.arch.infrastructure.in.controller.rest.endpoint.IController;

import local.arch.infrastructure.builder.Builder;

import local.arch.application.IService;

@Path("/")
public class Controller implements IController {

	// @Override
	// public boolean supports(String path, Method method) {
	// return ( (path.equals("/")) && (method == Method.GET) );
	// }

	@GET
	@Path("/")
	@Produces("text/plain")
	public Response service(@QueryParam("username") String login, @QueryParam("password") String password) {
		// Response response = new Response();
		// response.Code = 200;
		// response.Headers = new HashMap<>();
		// response.Headers.put("Content-Type","text/plain; charset=UTF-8");
		// Response.Body = "OK";
		// System.out.println(response);
		String reString = "OK";
		return Response.ok(reString).build();
	}
}