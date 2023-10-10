package local.arch.infrastructure.in.controller.rest.endpoint.calculation;

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
	@Path("/calculation")
	@Produces("text/plain")

	@Override
	public Response service(@QueryParam("a") String a1, @QueryParam("b") String b2) {
		// Map<String,String> requestParams = request.Params;

		// int helloVariantNumber = 0;
		// String paramFilter = requestParams.get("filter");
		// if ( (paramFilter != "null") && (paramFilter.equals("true")) ) {
		// String paramID = requestParams.get("id");
		// if (paramID != "null") {
		// try {
		// helloVariantNumber = Integer.parseInt(paramID);
		// } catch (Exception e) {}
		// }
		// }
		double a = Double.parseDouble(a1);
		double b = Double.parseDouble(b2);
		IService service = Builder.buildService();
		String calculation = service.calculation(a, b);
		// System.out.println(calculation);
		// helloVariantNumber

		// Response response = new Response();
		// response.Code = 200;
		// response.Headers = new HashMap<>();
		// response.Headers.put("Content-Type", "text/plain; charset=UTF-8");
		// response.Body = calculation;
		// System.out.println(response);
		// return response;
		return Response.ok(calculation).build();
	}
}