package local;

import java.util.HashMap;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;

import java.net.InetSocketAddress;
import java.net.URI;

import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.Headers;

import local.arch.infrastructure.in.controller.rest.Locator;

import local.arch.infrastructure.in.controller.rest.endpoint.Method;
import local.arch.infrastructure.in.controller.rest.endpoint.Request;
import local.arch.infrastructure.in.controller.rest.endpoint.Response;
import local.arch.infrastructure.in.controller.rest.endpoint.IFactory;
import local.arch.infrastructure.in.controller.rest.endpoint.IController;

//Starter (Begin)
public class Server {
	public static void main(String args[]) {
		System.out.println("Starting server...");

		try {
			HttpServer server = HttpServer.create(new InetSocketAddress("localhost", 90), 0);
			String rootContext = "/api"; // /iks/api/v1
			server.createContext(rootContext, new Handler(rootContext));
			System.out.println("cool1");
			server.start();
		} catch (Exception ex) {
			System.out.println("Error while starting server");
		}

		System.out.println("Server is working!");
	}
}
// Starter (End)

// Front Controller (Begin)
class Handler implements HttpHandler {
	private String rootContext;

	public Handler(String rootContext) {
		this.rootContext = rootContext;
		Router.registerRoutes();
	}

	@Override
	public void handle(HttpExchange httpExchange) throws IOException {
		OutputStream responseStream = httpExchange.getResponseBody();
		httpExchange.getResponseHeaders().add("Access-Control-Allow-Headers", "Content-Type");

		Headers responseHeaders = httpExchange.getResponseHeaders();
		String responseBody = "";
		System.out.println("cool3 handle");
		try {
			InputStream requestBodyStream = httpExchange.getRequestBody();
			String requestBody = new String(requestBodyStream.readAllBytes());
			Headers requestHeaders = httpExchange.getRequestHeaders();
			String requestMethod = httpExchange.getRequestMethod();
			URI requestURI = httpExchange.getRequestURI();

			Request request = new Request();
			Method method = Method.valueOf(requestMethod.toUpperCase());
			request.Method = method;
			if (method == null) {
				throw new Exception("Unknowm method");
			}
			String path = requestURI.getPath();
			System.out.println(path);

			if (path.equals(rootContext)) {
			path = path + "/";
			}
			request.Path = path.split(rootContext)[1];
			request.Params = new HashMap<>();
			String query = requestURI.getQuery();
			if (query != null) {
				for (String param : query.split("&")) {
					String[] kv = param.split("=");
					request.Params.put(kv[0], kv[1]);
				}
			}
			request.Headers = new HashMap<>();
			if (requestHeaders != null) {
				if (requestHeaders.isEmpty() == false) {
					for (String key : requestHeaders.keySet()) {
						request.Headers.put(key, requestHeaders.getFirst(key));
					}
				}
			}
			request.Body = requestBody;

			Response response = Router.route(request);
			if (response.Headers != null) {
				if (response.Headers.isEmpty() == false) {
					for (String key : response.Headers.keySet()) {
						responseHeaders.set(key, response.Headers.get(key));
					}
				}
			}
			responseBody = response.Body;
			httpExchange.sendResponseHeaders(response.Code, responseBody.getBytes().length);
		} catch (Exception ex) {
			responseBody = "Fatal error: " + ex.getMessage();
			responseHeaders.clear();
			httpExchange.sendResponseHeaders(500, responseBody.getBytes().length);
		}

		responseStream.write(responseBody.getBytes());
		responseStream.flush();
		responseStream.close();
	}
}
// Front Controller (End)

// Router (Begin)
class Router {

	private static IFactory[] controllerFactories;

	public static void registerRoutes() {
		System.out.println("cool registerRoutes");
		controllerFactories = Locator.locate();
	}

	public static Response route(Request request) {
		IController controller = null;
		boolean controllerFound = false;
		for (IFactory controllerFactory : controllerFactories) {
			controller = controllerFactory.createInstance();
			System.out.println("cool controllerFactory");
			if (controller.supports(request.Path, request.Method)) {
				controllerFound = true;
				System.out.println(controllerFound);

				break;
			}
		}

		Response response = null;
		if (controllerFound) {
			response = controller.service(request);
			System.out.println(response);

		} else {
			response = new Response();
			response.Code = 400;
			response.Headers = new HashMap<>();
			response.Body = "No implementation for path or method";

		}
		return response;
	}
}
// Router (End)