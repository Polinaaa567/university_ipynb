import { Counter } from "./Counter.js";

export class CounterFactory {

    static _createInstance() {
      return new Counter();
    }
  
    static createInstance() {
      if (CounterFactory._counter === null) {
        CounterFactory._createInstance();
      }
      return CounterFactory._counter;
    }
  }