import {User} from "./User.js";

export class UserFactory {

    static _user = null;
  
    static _createInstance() {
      return new User();
    }
  
    static createInstance() {
      if (UserFactory._user === null) {
        UserFactory._user = UserFactory._createInstance();
      }
      return UserFactory._user;
    }
  }