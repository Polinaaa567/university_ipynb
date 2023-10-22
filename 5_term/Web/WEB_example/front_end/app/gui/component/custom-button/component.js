import template from "./template.js";

class CustomButton extends HTMLElement {
    constructor() {
        console.log('constructor custom-button...');  
        super();   
        this.attachShadow({ mode: 'open' });  
        this.addEventListener('click', (event) => {
            console.log('custom-button click');
            event.stopPropagation();   

        })
    }

    connectedCallback() {  
        console.log('connectedCallback custom-button...');  
        this._render();   
    }

    disconnectedCallback() {
        console.log('disconnectedCallback custom-button...');    
    }

    static get observedAttributes() {
        return []; 
    }   
    
    attributeChangedCallback(attr, prev, next) {
        console.log('attributeChangedCallback custom-button...');     
    }

    //**********************************

    _render() {
        console.log('_render custom-button...');      
        if(!this.ownerDocument.defaultView) return;    
        this.shadowRoot.innerHTML = template(this);          
    }
}

customElements.define('custom-button',CustomButton);
console.log('Log:Defining custom-button');