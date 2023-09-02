'use strict'

let div = document.getElementById('div');

let schedule = [{time: '8.00 - 9.35', subject: ' ', teacher: ' ', auditorium: ''},
                {time: '9.45 - 11.20', subject: ' ', teacher: ' ', auditorium: ''},
                {time: '11.45 - 13.20', subject: ' ', teacher: ' ', auditorium: ''},
                {time: '13.30 - 15.05', subject: 'чет. Структуры и алгоритмы обработки данных (л)', teacher: 'доц. Зимин А.И', auditorium: '2226'},
                {time: '13.30 - 15.05', subject: 'неч. Современные средства и методы front-end разработки (л)', teacher: 'доц. Иванов К.С', auditorium: '2130б'},
                {time: '15.30 - 17.05', subject: 'Современные средства и методы front-end разработки (лаб)', teacher: 'доц. Иванов К.С', auditorium: '2130б'},
                {time: '17.15 - 18.50', subject: 'Структуры и алгоритмы обработки данных (лаб)', teacher: 'доц. Зимин А.И', auditorium: '2130а'}];

let table = document.createElement('table');

let header = document.createElement('tr');

let headerTime = document.createElement('th');
headerTime.innerHTML = 'Время';

let headerSubject = document.createElement('th');
headerSubject.innerHTML = 'Дисциплина';

let headerTeacher = document.createElement('th');
headerTeacher.innerHTML = 'Преподаватель';

let headerAuditorium = document.createElement('th');
headerAuditorium.innerHTML = 'Аудитория';

header.append(headerTime, headerSubject, headerTeacher, headerAuditorium);

table.appendChild(header);

for (let i = 0; i < schedule.length; i++) {
    let rows = document.createElement('tr');
    
    let cellTime = document.createElement('td');
    cellTime.innerHTML = schedule[i].time;

    let cellSubject = document.createElement('td');
    cellSubject.innerHTML = schedule[i].subject;

    let cellTeacher = document.createElement('td');
    cellTeacher.innerHTML = schedule[i].teacher;

    let cellAuditorium = document.createElement('td');
    cellAuditorium.innerHTML = schedule[i].auditorium;

    rows.append(cellTime, cellSubject, cellTeacher, cellAuditorium);
    table.appendChild(rows);
}

div.appendChild(table);
