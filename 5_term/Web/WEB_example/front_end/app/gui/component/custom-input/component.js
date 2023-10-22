import template from "./template.js";

class CustomInput extends HTMLElement {
    constructor() {
        console.log('constructor custom-input...');  
        super();   
        this._xValue = '';
        this.attachShadow({ mode: 'open' });  
        this.shadowRoot.addEventListener('change',(event) => {
            event.stopPropagation();       
            this._xValue = event.target.value;        
        });
    }

    connectedCallback() {  
        console.log('connectedCallback custom-input...');  
        this._render();   
    }

    disconnectedCallback() {
        console.log('disconnectedCallback custom-input...');    
    }

    static get observedAttributes() {
        return ['x-value']; 
    }   
    
    attributeChangedCallback(name, oldValue, newValue) {
        console.log('attributeChangedCallback custom-input...'); 
        if(oldValue !== newValue) {
            if (name==='x-value') {       
              this.xValue = newValue;
            }     
          }    
    }

    //**********************************

    set xValue(value) {    
        this._xValue = value;
        this._render(); 
     }
     get xValue() {
        return this._xValue;
     }
     
    _render() {
        console.log('_render custom-input...');      
        if(!this.ownerDocument.defaultView) return;    
        this.shadowRoot.innerHTML = template(this);          
    }
}

customElements.define('custom-input',CustomInput);
console.log('Log:Defining custom-input');