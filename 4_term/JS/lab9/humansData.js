let human1 = {
    id: 1,
    name: 'Marilyn',
    last_name: 'Kerro',
    age: '35',
    sex: 'woman',
    address: 'Estonia, Tallinn',
    phone: '+372 523-4567'
};

let human2 = {
    id: 2,
    name: 'Oleg',
    last_name: 'Sheps',
    age: '25',
    sex: 'men',
    address: 'Samara, Russia',
    phone: '8 916 413 02 02'
};

let human3 = {
    id: 3,
    name: 'Vlad',
    last_name: 'Cherevaty',
    age: '26',
    sex: 'men',
    address: 'Luhansk region, Ukraine',
    phone: '8 800 555 35 35'
};

let human4 = {
    id: 4,
    name: 'Vanellope',
    last_name: 'von Schweetz',
    age: '9',
    sex: 'woman',
    address: 'Sweet Fast and Furious game',
    phone: '8 983 220 18 97'
};

let human5 = {
    id: 5,
    name: 'Anatoly',
    last_name: 'Kashpirovsky',
    age: '83',
    sex: 'men',
    address: 'Warsaw, Poland',
    phone: '+48 (22) 123 45 67'
};

let mass_person = [human1, human2, human3, human4, human5];

export async function getData() {
    return mass_person.slice(0, Math.round((Math.random()* (mass_person.length - 1)+1)));
}

export function deletePerson(id) {
    let index = mass_person.findIndex(person => person.id === id)
    if(index > -1) {
        mass_person.splice(index, 1)
    } 
}

export async function AddPerson() {
    let id = prompt('Id: ')
    let name = prompt('Name: ');
    let last_name = prompt('Last name: ');
    let age = prompt('Age: ');
    let sex = prompt('Sex: ');
    let address = prompt('Address: ');
    let phone = prompt('Phone: ');

    let newPerson = {
        id: id, 
        name: name,
        last_name: last_name,
        age: age,
        sex: sex,
        address: address,
        phone: phone
    };
    mass_person.push(newPerson);
}
    