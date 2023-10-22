import template from './template.js'


import '../../composition/custom-login/component.js'

class XAuthentication extends HTMLElement {
    
 constructor() { 
   console.log('constructor authentication...');  
   super();   
   this.attachShadow({ mode: 'open' });               
 }

 connectedCallback() {  
   console.log('connectedCallback authentication...');  
   this._render();   
 }

 disconnectedCallback() {     
   console.log('disconnectedCallback authentication...');    
 } 

 static get observedAttributes() {
   return []; 
}                    

 attributeChangedCallback(attr, prev, next) {
   console.log('attributeChangedCallback authentication...');     
 }
 
 //**********************************
 
 _render() {
   console.log('_render authentication...');      
   if(!this.ownerDocument.defaultView) return;    
   this.shadowRoot.innerHTML = template(this);      
 }
}

customElements.define('x-authentication',XAuthentication);
console.log('Log:Defining web-authentication');