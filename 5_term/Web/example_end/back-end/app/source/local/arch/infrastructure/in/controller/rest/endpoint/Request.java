package local.arch.infrastructure.in.controller.rest.endpoint;


import java.util.Map;


public class Request {
   public Method Method;
   public String Path;
   public Map<String,String> Params;
   public Map<String,String> Headers;
   public String Body;
}