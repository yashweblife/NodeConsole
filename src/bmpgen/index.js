class Cell {
    selected = false;
    dom = document.createElement("div")
    constructor() {
        this.dom.addEventListener('click', () => {
            if (this.selected == true) {
                this.selected = false;
                this.dom.classList.remove("selected")
            } else {
                this.dom.classList.add("selected")
                this.selected = true;
            }
        })
    }
    reset() {
        this.selected = false;
        this.dom.classList.remove("selected")
    }
}

class Grid {
    divs = []
    constructor(parent = document.body) {
        for (var i = 0; i < 16; i++) {
            var col = []
            var coldom = document.createElement('section')
            for (var j = 0; j < 16; j++) {
                var div = new Cell();
                col.push(div)
                coldom.appendChild(div.dom)
            }
            parent.appendChild(coldom)
            this.divs.push(col)
        }
    }
    getBit() {
        var output = "{"
        for (var i = 0; i < this.divs.length; i++) {
            output += "\t0b"
            for (var j = 0; j < this.divs[i].length; j++) {
                var b = this.divs[i][j];
                if (j == 8) {
                    output += ", 0b";
                }
                if (b.selected == true) {
                    output += "1";
                } else {
                    output += "0"
                }
            }
            output += ",\n"
        }
        output += "};"
        return (output)
    }
    clear() {
        for (var i = 0; i < this.divs.length; i++) {
            for (var j = 0; j < this.divs[i].length; j++) {
                this.divs[i][j].reset();
            }

        }
    }
}

const grid = new Grid()

document.querySelector('#btn').addEventListener('click', (e) => {
    console.log(grid.getBit());
})
document.querySelector('#btn-1').addEventListener('click', (e) => {
    console.log(grid.clear());
})