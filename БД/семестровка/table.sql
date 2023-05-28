create table hotel_class (
    id                          number(7)
    constraint hotel_class_id_pk primary key,
    class_requirements          varchar2(25) not null
);

create table price_room (
    id                          number(7)
    constraint price_room_id_pk primary key,
    id_hotel_class              number(7) not null,
    foreign key(id_hotel_class) references hotel_class(id), 
    number_beds                 number(7) not null,
    price                       number(7) not null
);

create table building(
    id                          number(7)
    constraint building_id_pk primary key,
    number_floors               number(7) not null,
    total_number_rooms          number(7) not null,
    number_rooms_floor          number(7) not null,
    number_single_rooms         number(7) not null,
    number_double_rooms         number(7) not null,
    number_triple_rooms         number(7) not null,
    address                     varchar2(25) not null,
    id_hotel_class              number(7) not null,
    foreign key(id_hotel_class) references hotel_class(id)
 );

create table statistics(
    id                          number(7)
    constraint statistics_id_pk primary key,
    id_building                 number(7) not null,
    foreign key(id_building) references building(id),
    number_occupied_rooms       number(7) not null,
    number_available_rooms      number(7) not null
);

create table list_services (
    id                          number(7)
    constraint list_services_id_pk primary key,
    name_services               varchar2(25) not null, 
    price                       number(7) not null
);

create table building_service (
    id                          number(7)
    constraint building_services_id_pk primary key,
    id_services                 number(7) not null,
    foreign key(id_services) references list_services(id), 
    id_building                 number(7) not null,
    foreign key(id_building) references building(id),
    description                 varchar2(25)
);

create table company (
    id                          number(7)
    constraint company_id_pk primary key,
    name_company                varchar2(25) not null,
    fname_contact_person        varchar2(25) not null,
    contract_status             number(8) not null,
    discription_activity        varchar2(25) not null,
    sale                        number(7) not null
);

create table guest(
    id                          number(7)
    constraint guest_id_pk primary key,
    last_name                   varchar2(25) not null,
    first_name                  varchar2(25) not null,
    patronymic                  varchar2(25) null,
    date_birth                  date,
    gender                      varchar2(25) not null,
    contacts                    number(25) not null,
    amount_debt                 number(25) not null
);

create table application_settlement(
    id                          number(7)
    constraint application_settlement_id_pk primary key,
    order_company               number(7) not null,
    id_guest                    number(7) not null,
    foreign key(id_guest) references guest(id),
    id_company                  number(7) not null,
    foreign key(id_company) references company(id),
    hotel_class_stars           number(7) not null,
    booking_date                date,
    arrival_date                date,
    departure_date              date,
    number_people               number(7) not null,
    number_single_rooms         number(7) not null,
    number_double_rooms         number(7) not null,
    number_triple_rooms         number(7) not null,
    order_processing_status     number(7) not null,
    booking_status              number(7) not null,
    id_building                 number(7) not null,
    foreign key(id_building) references building(id),
    payment_status              number(7) not null
);

create table number_building (
    id                          number(7)
    constraint number_building_id_pk primary key,
    room_number                 number(7) not null,
    number_beds                 number(7) not null,
    id_building                 number(7) not null,
    foreign key(id_building) references building(id)
);

create table ordering_service (
    id                          number(7)
    constraint ordering_service_id_pk primary key,
    id_guest                    number(7) not null,
    foreign key(id_guest) references guest(id),
    id_services                 number(7) not null,
    foreign key(id_services) references list_services(id), 
    paid                        number(7) not null
);

create table booking_room (
    id                          number(7)
    constraint booking_room_id_pk primary key,
    id_guest                    number(7) not null,
    foreign key(id_guest) references guest(id),
    id_booking_hotel            number(7) not null, 
    foreign key(id_booking_hotel) references application_settlement(id),
    id_number                   number(7) not null,
    foreign key(id_number) references number_building(id)

);

create table complaints_suggestions(
    id                          number(7)
    constraint complaints_suggestions_id_pk primary key,
    id_booking                  number(7) not null, 
    foreign key(id_booking) references booking_room(id),
    description                 varchar2(25) not null,
    date_complaint              date
);

-- ------------------------------------------


create sequence seq_list_services_id
    increment by 1 
    start with 1
    maxvalue 99999
    nocache
    nocycle;

create sequence seq_building_service_id
    increment by 1 
    start with 1
    maxvalue 99999
    nocache
    nocycle;

create sequence seq_company_id
    increment by 1 
    start with 1
    maxvalue 999
    nocache
    nocycle;

create sequence seq_guest_id
    increment by 1 
    start with 1
    maxvalue 99999
    nocache
    nocycle;

create sequence seq_application_settlement_id
    increment by 1 
    start with 1
    maxvalue 999999
    nocache
    nocycle;

create sequence seq_number_building_id
    increment by 1 
    start with 1
    maxvalue 999999
    nocache
    nocycle;

create sequence seq_ordering_service_id
    increment by 1 
    start with 1
    maxvalue 999999
    nocache
    nocycle;

create sequence seq_booking_room_id
    increment by 1 
    start with 1
    maxvalue 999999
    nocache
    nocycle;

create sequence seq_complaints_suggestions_id
    increment by 1 
    start with 1
    maxvalue 999999
    nocache
    nocycle;
