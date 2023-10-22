import { Store } from "../Store.js";

export class User extends Store {

    constructor() {
      super();
      this._user = '';
    }
  
    fixUserName(userName) {
      this._user = userName;
      console.log('User::fixUserName: ' + this._user);
      super._emit(this._user);
    }
  
    getUserName() {
      console.log('User::getUserName: ' + this._user);
      return this._user;
    }
  
  }