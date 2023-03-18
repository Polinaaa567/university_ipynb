'use strict';

function Browser(name, version ) {
    this.name = name;
    this.version = version;

    this.aboutBrowser = function() {
        console.log(this.name);
        console.log(this.version);
    }
}

let myBrowser = new Browser("Microsoft Internet Explorer", "9.0");

myBrowser.aboutBrowser();