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

create sequence seq_booking_order_id
    increment by 1 
    start with 1
    maxvalue 999999
    nocache
    nocycle;
    
create sequence seq_building_room_id
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
    
-- ----------------------------
-- хранение данных
-- класс отеля
create table hotel_class (
    id                          number(7)
    constraint hotel_class_id_pk primary key,
    class_requirements          varchar2(255) not null
);

--цена за номер
create table price_room (
    id                          number(7)
    constraint price_room_id_pk primary key,
    hotel_class_id              number(7) not null,
    foreign key(hotel_class_id) references hotel_class(id), 
    number_beds                 number(7) not null,
    price                       number(7) not null
);

--корпус
create table building(
    id                          number(7)
    constraint building_id_pk primary key,
    hotel_class_id              number(7) not null,
    foreign key(hotel_class_id) references hotel_class(id),
    number_floors               number(7) not null,
    total_number_rooms          number(7) not null,
    number_rooms_floor          number(7) not null,
    number_beds_in_rooms        number(7) not null,
    address_hotel               varchar2(255) not null
 );

--номер в корпусе
create table building_room (
    id                          number(7)
    constraint number_building_id_pk primary key,
    room_number                 number(7) not null,
    building_id                 number(7) not null,
    foreign key(building_id) references building(id)
);

--список услуг
create table list_services (
    id                          number(7)
    constraint list_services_id_pk primary key,
    name_services               varchar2(255) not null, 
    price                       number(7) not null
);

--услуга корпус
create table building_service (
    id                          number(7)
    constraint building_services_id_pk primary key,
    services_id                 number(7) not null,
    foreign key(services_id) references list_services(id), 
    building_id                 number(7) not null,
    foreign key(building_id) references building(id),
    description                 varchar2(255)
);

--фирма
create table company (
    id                          number(7)
    constraint company_id_pk primary key,
    name_company                varchar2(255) not null,
    fname_contact_person        varchar2(255) not null,
    contract_status             number(8) not null,
    discription_activity        varchar2(255) not null,
    sale                        number(7) null
);

--постоялец
create table guest(
    id                          number(7)
    constraint guest_id_pk primary key,
    last_name                   varchar2(255) not null,
    first_name                  varchar2(255) not null,
    date_birth                  date not null,
    gender                      varchar2(255) not null,
    contacts                    varchar2(255) not null,
    amount_debt                 number(7) null
);

--заявка на заселение
create table booking_order(
    id                          number(7)
    constraint booking_order_id_pk primary key,
    guest_id                    number(7),
    foreign key(guest_id) references guest(id),
    company_id                  number(7),
    foreign key(company_id) references company(id),
    hotel_class_stars           number(7) not null,
    booking_date                date not null,
    arrival_date                date not null,
    departure_date              date not null,
    number_people               number(7) not null, 
    number_rooms         		number(7),
    order_processing_status     varchar2(255) null,
    building_id                 number(7) null,
    foreign key(building_id) references building(id),
    payment_status              varchar2(255) null
);

--бронь номера
create table booking_room (
    id                          number(7)
    constraint booking_room_id_pk primary key,
    booking_order_id            number(7) not null, 
    foreign key(booking_order_id) references booking_order(id),
    guest_id                    number(7) not null,
    foreign key(guest_id) references guest(id),
    room_id                     number(7) not null,
    foreign key(room_id) references building_room(id)
);

--запись жалоб и предложений
create table complaints_suggestions(
    id                          number(7)
    constraint complaints_suggestions_id_pk primary key,
    booking_room_id             number(7) not null, 
    foreign key(booking_room_id) references booking_room(id),
    description                 varchar2(255) not null,
    on_date                     date not null
);

--заказ услуги 
create table ordering_service (
    id                          number(7)
    constraint ordering_service_id_pk primary key,
    on_date                     date not null, 
    guest_id                    number(7) not null,
    foreign key(guest_id) references guest(id),
    services_id                 number(7) not null,
    foreign key(services_id) references list_services(id), 
    payment_status              varchar2(255) null
);

--статистика
create table statistics(
    id                          number(7)
    constraint statistics_id_pk primary key,
    building_id                 number(7) not null,
    foreign key(building_id) references building(id),
    number_occupied_rooms       number(7) not null,
    number_available_rooms      number(7) not null
);
