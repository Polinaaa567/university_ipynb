package local.arch.infrastructure.in.controller.rest.endpoint.authentication;

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
		return ((path.equals("/authentication")) && (method == Method.GET));

	}

	@Override
	public Response service(Request request) {
		// String requestBody = request.Body;

		// String[] argsString = requestBody.split("&");
		// double[] args = new double[argsString.length];
		// int i = 0;
		// for (String argString : argsString) {
		// args[i] = 0;
		// try {
		// args[i] = Double.parseDouble(argString);
		// } catch (Exception e) {}
		// i = i+1;
		// }
		Map<String, String> requestParams = request.Params;
		String login = requestParams.get("username").toString();
		String password = requestParams.get("password").toString();
		IService service = Builder.buildService();
		System.out.println(String.format("%s + %s", login, password));
		String check = service.check(login, password);

		// int dataCountUpdated = ts.updateData(args);

		Response response = new Response();
		response.Code = 200;
		response.Headers = new HashMap<>();
		response.Headers.put("Content-Type", "text/plain; charset=UTF-8");
		response.Body = check;
		System.out.println(check);
		System.out.println("check");
		return response;
	}
}