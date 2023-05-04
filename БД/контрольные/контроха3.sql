create table my_departments (
    ID Number(7)
    constraint my_departments_pk primary key,
    NAME char(25) not null
);

create table groups_Vuza (
    ID Number(7)
    constraint my_groups_vuza_pk primary key,
    NAME char(25) not null,
    ID_department number(7) Not null,
    constraint my_groups_vuza_id_fk foreign key (ID_department) references my_departments(ID)
);

create table my_university (
    ID number(7)
    constraint my_university_pk primary key, 
    ID_department number(7) not null,
    constraint my_university_id_fk foreign key(ID_department) references my_departments(ID)
);

create table my_teacher (
    ID number(7)
    constraint my_teacher_pk primary key, 
    LAST_NAME char(25) not null, 
    FIRST_NAME char(25) not null, 
    PATRONYMIC char(25),
    SCIENTIFIC_TITLE char(25) not null,
    SCIENTIFIC_DEGREE char(25) not null,
    ID_UNIVERSITY number(7) not null, 
    constraint my_teacher_id_fk foreign key(ID_UNIVERSITY) references my_university(ID),
    position char(25) not null
);

create table my_discipline(
    ID number(7)
    constraint my_discipline_pk primary key, 
    NAME_RUS char(25) not null,
    NAME_ENG char(25) not null,
    VIEW_DISCIPLINE char(25) not null,
    ID_TEACHER number(7) not null,
    constraint my_discipline_id_fk foreign key(ID_TEACHER) references my_teacher(ID)
);

create table my_AUDITORIUM(
    ID number(7)
    constraint my_AUDITORIUM_pk primary key, 
    Number_corpus number(7) not null,
    TYPE_AUDITORIUM char(25) not null,
    Number_of_seats number(7) not null
);

create table my_schedule(
    ID number(7)
    constraint my_schedule_pk primary key, 
    day_of_the_week char(25) not null, 
    ID_discipline number(7) not null,
    constraint my_schedule_id_fk foreign key(ID_discipline) references discipline(ID),
    ID_group number(7) not null,
    constraint my_schedule_id_fk foreign key(ID_group) references groups_Vuza(ID)

);