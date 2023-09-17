let obj = {
   // name: "mbkv"
}

function isEmpty(obj) {
    for (let i in obj) {
        if (obj.hasOwnProperty(i)) {
            return false
        }
    }
    return true
}

console.log(isEmpty(obj))
