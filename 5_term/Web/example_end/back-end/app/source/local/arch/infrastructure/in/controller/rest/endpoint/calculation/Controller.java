package local.arch.infrastructure.in.controller.rest.endpoint.calculation;

import java.util.HashMap;
import java.util.Map;

import local.arch.infrastructure.in.controller.rest.endpoint.Method;
import local.arch.infrastructure.in.controller.rest.endpoint.Request;
import local.arch.infrastructure.in.controller.rest.endpoint.Response;
import local.arch.infrastructure.in.controller.rest.endpoint.IController;

import local.arch.infrastructure.builder.Builder;

import local.arch.application.IService;

public class Controller implements IController {

	@Override
	public boolean supports(String path, Method method) {
		System.out.println(path);
		return ((path.equals("/calculation")) && (method == Method.GET));
	}

	@Override
	public Response service(Request request) {
		Map<String,String> requestParams = request.Params;

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
		double a = Double.parseDouble(requestParams.get("a"));
		double b = Double.parseDouble(requestParams.get("b"));
		IService service = Builder.buildService();
		String calculation = service.calculation(a, b);
		System.out.println(calculation);
		// helloVariantNumber

		Response response = new Response();
		response.Code = 200;
		response.Headers = new HashMap<>();
		response.Headers.put("Content-Type", "text/plain; charset=UTF-8");
		response.Body = calculation;
		System.out.println(response);
		return response;
	}
}