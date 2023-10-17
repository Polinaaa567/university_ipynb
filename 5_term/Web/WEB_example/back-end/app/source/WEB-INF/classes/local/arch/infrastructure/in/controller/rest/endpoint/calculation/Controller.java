package local.arch.infrastructure.in.controller.rest.endpoint.calculation;

import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;

import jakarta.ws.rs.Produces;

import jakarta.ws.rs.core.Response;
import jakarta.ws.rs.QueryParam;

import javax.annotation.processing.Generated;

import local.arch.infrastructure.builder.Builder;

import local.arch.application.IService;

@Path("/")
public class Controller {

	@GET
	@Path("/calculation")
	@Produces("text/plain")

	public Response service(@QueryParam("a") String a1, 
							@QueryParam("b") String b2) 
	{
		double a = Double.parseDouble(a1);
		double b = Double.parseDouble(b2);
		IService service = Builder.buildService();
		String calculation = service.calculation(a, b);

		return Response.ok(calculation).build();
	}
}