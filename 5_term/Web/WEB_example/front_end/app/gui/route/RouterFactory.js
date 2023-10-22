import { Router } from "./Router.js";

export class RouterFactory {
   
    static _router = null;
    
    static _createInstance() {
      return new Router();      
    }
       
    static createInstance() {
       if (RouterFactory._router === null) {
         RouterFactory._router = RouterFactory._createInstance();  
       }      
       return RouterFactory._router;
    }
 }