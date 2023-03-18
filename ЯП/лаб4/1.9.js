function Employee(name, division, phone, salary) {
    this.name = name
    this.division = division
    this.phone = phone
    this.salary = salary

    this.aboutEmp = function() {
        console.log(this.name + ", " + this.division + ", " + this.phone + ", " + this.salary)
    }
}

let emp = new Employee("Петров", "Лаборант", "8-800-555-35-35", "8950")
emp.aboutEmp()