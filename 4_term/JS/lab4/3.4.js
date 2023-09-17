class Stock {
    constructor() {
        this.listW = [];
        this.listV = [];
    }
    add(w, v) {
        this.listW.push(w);
        this.listV.push(v);
    }

    getByW(min_w) {
        let setW = new Set();
        for (let index = 0; index < this.listW.length; index++) {
            if (this.listW[index] < min_w) {
                setW.add(this.listW[index]);
            }
        }
        let min = Math.min( ...setW );
        return this.listW.indexOf(min); 
        
    }

    getByV(min_v) {
        let setV = new Set();
        for (let index = 0; index < this.listV.length; index++) {
            if (this.listV[index] < min_v) {
                setV.add(this.listV[index]);
            }
        }
        let min = Math.min( ...setV );
        return this.listV.indexOf(min); 
    }

}


let stock1 = new Stock();
stock1.add(5, 7);
stock1.add(4, 8);
stock1.add(1, 8);
console.log(stock1.getByV(2));
console.log(stock1.getByW(6)); 
