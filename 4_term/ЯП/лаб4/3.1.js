class Clock {
    constructor(hour, minute, second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    update() {
        console.log(this.hour +"."+ this.minute +"."+ this.second)
    }
}

let cl = new Clock(12, 15, 45);
cl.update();