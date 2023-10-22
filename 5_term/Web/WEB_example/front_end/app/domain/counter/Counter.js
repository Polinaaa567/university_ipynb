import { Store } from "../Store.js";

export class Counter extends Store {

    constructor() {
      super();
      this._quantityTasks = 0;
      this._doneTasks = 0;
      this._performTasks = 0;
      this._emptyTasks = 0;
    }
  
    getQuantityTasks() {
      return this._quantityTasks;
    }
  
    increaseQuantityTasks() {
      this._quantityTasks += 1;
      super._emit(this._quantityTasks);
    }

    decreaseQuantityTasks() {
        this._quantityTasks -= 1;
        super._emit(this._quantityTasks);
    }

    getDoneTasks() {
      return this._doneTasks;
    }
  
    increaseDoneTasks() {
        this._doneTasks += 1;
        super._emit(this._doneTasks);
    }

    decreaseDoneTasks() {
        this._doneTasks -= 1;
        super._emit(this._doneTasks);
    }    

    getPerformTasks() {
      return this._performTasks;
    }
  
    increasePerformTasks() {
        this._performTasks += 1;
        super._emit(this._performTasks);
    }

    decreasePerformTasks() {
        this._performTasks -= 1;
        super._emit(this._performTasks);
    }

    getEmptyTasks() {
      return this._emptyTasks;
    }

    increaseEmptyTasks() {
        this._emptyTasks += 1;
        super._emit(this._emptyTasks);
    }

    decreaseEmptyTasks() {
        this._emptyTasks -= 1;
        super._emit(this._emptyTasks);
    }
}