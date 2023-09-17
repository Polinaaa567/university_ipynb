/*countries = ["Россия", "Украина", "Турция", "Корея"]
population = ["Русские", "Украинцы",  "Турки", "Корейцы"]
function fjd() {
    let count = (countries.length + population.length)/2;
    for (var i = 0; i < count; i++) {
        console.log(countries[i]+ " " +population[i]);
    }
}
fjd();*/

countries = ["Россия", "Украина", "Турция", "Корея"]
population = ["Русские", "Украинцы",  "Турки", "Корейцы"]
function fjd() {
    for (let key in population || key in countries) {

        console.log(population[key] + " " + countries[key]);

    }
}
fjd();