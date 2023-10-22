import template from './template.js';

import { UserFactory } from "../../../domain/user/index.js";

import { ApiServiceFactory } from '../../api/ApiServiceFactory.js';

import '../../component/custom-button/component.js';
import '../../component/custom-input/component.js';


class PredLogin extends HTMLElement {
    constructor() { 
        console.log('constructor custom-login...');  
        super();   
        this.attachShadow({ mode: 'open' });            
      }
     
      connectedCallback() {  
        console.log('connectedCallback custom-login...');  
        this._render();   
      }
     
      disconnectedCallback() {     
        console.log('disconnectedCallback custom-login...');    
      } 
     
      static get observedAttributes() {
        return []; 
     }                    
     
      attributeChangedCallback(attr, prev, next) {
        console.log('attributeChangedCallback custom-login...');     
      }
      
      //**********************************
      
      async _listener(event) {   
        console.log('custom-login clicked');                  
        event.stopPropagation();  

        let userName = (this.shadowRoot.childNodes[1].xValue);   
        let password = (this.shadowRoot.childNodes[3].xValue);     
        
        let log = ApiServiceFactory.createInstance();
        let ok = await log.loginfetch(userName, password);
        console.log(ok);
        console.log(this.shadowRoot.childNodes);
        
        if (ok) {
          // let router = RouterFactory.createInstance();    
          // router.go('calculation');

          let user = UserFactory.createInstance();
          user.fixUserName(userName);    

          alert('User ' + userName);

        }
        else {
          alert('Неправильный пароль или логин');

        }  
      }   
         
      _render() {
        console.log('_render custom-login...');      
        if(!this.ownerDocument.defaultView) return;    
        this.shadowRoot.innerHTML = template(this);
        this.shadowRoot.childNodes[5].addEventListener('click',this._listener.bind(this));   
      }
     }
     
     customElements.define('custom-login',PredLogin);
     console.log('Log:Defining custom-login');