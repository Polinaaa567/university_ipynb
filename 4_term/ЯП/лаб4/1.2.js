function Object() {
    let MyBrowser = {
        name: "Microsoft Internet Explorer",
        version: "9.0"
    }
    for(let i in MyBrowser) {
        console.log(MyBrowser[i])
    }
}

Object()