import template from './template.js'

import { CounterFactory } from "../../../domain/counter";
import { UserFactory } from "../../../domain/user";

class CustomLabel extends HTMLElement {
    
 constructor() { 
   console.log('constructor Custom-label...');  
   super();
   
   let counter = CounterFactory.createInstance();

   let quantityTasksV = counter.getQuantityTasks();
   let doneTasksV = counter.getDoneTasks();
   let performTasksV = counter.getPerformTasks();
   let emptyTasksV = counter.getEmptyTasks();
   counter.subscribe(this._listenerCounter.bind(this));
   
   let user = UserFactory.createInstance();
   let u = user.getUserName();

   user.subscribe(this._listenerUser.bind(this));
      
   this._quantityTasks = quantityTasksV;
   this._doneTasks = doneTasksV;
   this._performTasks = performTasksV;
   this._emptyTasks = emptyTasksV;

   this._xUser = u;    
   this.attachShadow({ mode: 'open' });         
 }

 connectedCallback() {  
   console.log('connectedCallback custom-label...');  
   this._render();   
 }

 disconnectedCallback() {     
   console.log('disconnectedCallback custom-label...');    
 } 

 static get observedAttributes() {
   return ['x-user','quantity-value', 'done-value', 'perform-value', 'empty-value']; 
}                    

 attributeChangedCallback(name, oldValue, newValue) {
   console.log('attributeChangedCallback custom-label...');  
   if(oldValue !== newValue) {
     if (name==='x-user') {       
       this.userName = newValue;
     } 
     if (name==='quantity-value') {       
       this.quantityTasks = newValue;
     } 
     if (name==='done-value') {       
        this.doneTasks = newValue;
      }
      if (name==='perform-value') {       
        this.performTasks = newValue;
      }
      if (name==='empty-value') {       
        this.performTasks = newValue;
      }
   }
 }
 
 //**********************************
 
 set userName(user) {    
    this._userName = user;
    this._render(); 
 }
 get userName() {
    return this._userName;
 }
 

 set quantityTasks(value) {    
    this._quantityTasks = value;
    this._render(); 
 }
 get quantityTasks() {
    return this._quantityTasks;
 }   
  
 set doneTasks(value) {    
    this._doneTasks = value;
    this._render(); 
 }
 get doneTasks() {
    return this._doneTasks;
 } 

 set performTasks(value) {    
    this._performTasks = value;
    this._render(); 
 }
 get performTasks() {
    return this._performTasks;
 } 

 set emptyTasks (value) {    
    this._emptyTasks  = value;
    this._render(); 
 }
 get emptyTasks () {
    return this._emptyTasks ;
 } 
    
 _listenerQuantityTasks(state) {   
   this.quantityTasks = state;     
 } 
 
 _listenerDoneTasks(state) {   
    this.doneTasks = state;     
  }

  _listenerPerformTasks(state) {   
    this.performTasks = state;     
  }

  _listenerEmptyTasks(state) {   
    this.emptyTasks = state;     
  }

 _listenerUser(state) {   
   this.userName = state;     
 }
 

 _render() {
   console.log('_render custom-label...');      
   if(!this.ownerDocument.defaultView) return;    
   this.shadowRoot.innerHTML = template(this);
 }
}

customElements.define('custom-label',CustomLabel);
console.log('Log:Defining custom-label');