package local.arch.infrastructure.in.controller.rest;


import local.arch.infrastructure.in.controller.rest.endpoint.IFactory;

public class Locator {	
   public static IFactory[] locate() {
       IFactory[] factories = {
                                 new local.arch.infrastructure.in.controller.rest.endpoint.root.Factory()
                                 ,
                                 new local.arch.infrastructure.in.controller.rest.endpoint.calculation.Factory()
                                 ,
                                 new local.arch.infrastructure.in.controller.rest.endpoint.authentication.Factory()
                              };              
       return factories;                    
   }
}
