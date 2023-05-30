insert into hotel_class (id, class_requirements)
values (1, 'Ванная комната: не менее 2х на этаж; Туалет: 1 на 5 комнат;
            Смена постельного белья: 1раз в 5 дней; Смена полотенец: 1раз в 3 дня;
            Уборка: ежедненвно');

insert into hotel_class (id, class_requirements)
values (2, 'Телефон: в номере; Ванная комната: не менее 2х на этаж; Туалет: 1 на 5 комнат;
            Смена постельного белья: 1раз в 3 дня; Смена полотенец: 1раз в 3 дня;
            Уборка: ежедненвно');

insert into hotel_class (id, class_requirements)
values (3, 'Телевизор: в номере; Холодильник: в номере; Телефон: в номере; 
            Ванная комната: в комнате; Туалет: в номере; 
            Смена постельного белья: 1раз в 3 дня; Смена полотенец: ежедненвно; 
            Уборка: ежедненвно');

insert into hotel_class (id, class_requirements)
values (4, 'Телевизор: в номере; Холодильник: в номере; Телефон: в номере; 
            Ванная комната: в комнате; Туалет: в номере; 
            Смена постельного белья: ежедненвно; Смена полотенец: ежедненвно; 
            Уборка: ежедненвно; Фен: в номере; Шампунь и мыло: в номере');


insert into hotel_class (id, class_requirements)
values (5, 'Телевизор: в номере; Холодильник: в номере; Телефон: в номере; 
            Ванная комната: в комнате; Туалет: в номере; 
            Смена постельного белья: ежедненвно; Смена полотенец: ежедненвно; 
            Уборка: ежедненвно; Фен: в номере; Шампунь и мыло: в номере');

insert into price_room (id, id_hotel_class, number_beds, price)
values (1, 1, 1, 750);

insert into price_room (id, id_hotel_class, number_beds, price)
values (2, 1, 2, 1050);

insert into price_room (id, id_hotel_class, number_beds, price)
values (3, 1, 3, 1350);

insert into price_room (id, id_hotel_class, number_beds, price)
values (4, 2, 1, 1250);

insert into price_room (id, id_hotel_class, number_beds, price)
values (5, 2, 2, 1550);

insert into price_room (id, id_hotel_class, number_beds, price)
values (6, 2, 3, 1850);

insert into price_room (id, id_hotel_class, number_beds, price)
values (7, 3, 1, 1750);

insert into price_room (id, id_hotel_class, number_beds, price)
values (8, 3, 2, 2050);

insert into price_room (id, id_hotel_class, number_beds, price)
values (9, 3, 3, 2350);

insert into price_room (id, id_hotel_class, number_beds, price)
values (10, 4, 1, 2250);

insert into price_room (id, id_hotel_class, number_beds, price)
values (11, 4, 2, 2550);

insert into price_room (id, id_hotel_class, number_beds, price)
values (12, 4, 3, 2850);

insert into price_room (id, id_hotel_class, number_beds, price)
values (13, 5, 1, 2750);

insert into price_room (id, id_hotel_class, number_beds, price)
values (14, 5, 2, 3050);

insert into price_room (id, id_hotel_class, number_beds, price)
values (15, 5, 3, 3350);

insert into building
values (1, 3, 9, 3, 6, 3, 0, 'ВанПисовский переулок 1а', 2);

insert into building
values (2, 3, 9, 3, 5, 4, 0, 'улица Стального Алхимика 3б', 3);

insert into building 
values (3, 3, 9, 3, 4, 3, 2, 'улица Великолепного Усуи Такуми', 4);

-- СТАТИСТИКИ ПОКА НЕТ

insert into list_services (id, name_services, price)
values (1, 'ежедневная уборка', 150);

insert into list_services (id, name_services, price)
values (2, 'прачечная', 200);

insert into list_services (id, name_services, price)
values (3, 'химчистка', 250);

insert into list_services (id, name_services, price)
values (4, 'бассейн', 500);

insert into list_services (id, name_services, price)
values (5, 'сауна', 300);

insert into list_services (id, name_services, price)
values (6, 'бильярд', 500);

insert into list_services (id, name_services, price)
values (7, 'ресторан', 300);

insert into list_services (id, name_services, price)
values (8, 'бар', 450);

insert into building_service (id, id_services, id_building, description)
values (1, 1, 1, 'Уборка номеров проводится каждый день с 11.00-12.00');

insert into building_service (id, id_services, id_building, description)
values (2, 1, 2, 'Уборка номеров проводится каждый день с 11.00-12.00');

insert into building_service (id, id_services, id_building, description)
values (3, 1, 3, 'Уборка номеров проводится каждый день с 11.00-12.00');

insert into building_service (id, id_services, id_building, description)
values (4, 2, 2, 'Прачечная работает с 9.00-11.00 и с 15.00-17.00');

insert into building_service (id, id_services, id_building, description)
values (5, 2, 3, 'Прачечная работает с 9.00-11.00 и с 15.00-17.00');

insert into building_service (id, id_services, id_building, description)
values (6, 3, 2, 'Химчистка работает с 9.00-11.00 и с 15.00-17.00');

insert into building_service (id, id_services, id_building, description)
values (7, 3, 3, 'Химчистка работает с 9.00-11.00 и с 15.00-17.00');

insert into building_service (id, id_services, id_building, description)
values (8, 4, 3, 'Бассейн работает с 9.00-11.00');

insert into building_service (id, id_services, id_building, description)
values (9, 5, 3, 'Сауна работает 16.00-23.00');

insert into building_service (id, id_services, id_building, description)
values (10, 6, 3, 'Бильярд работает с 18.00-00.00');

insert into building_service (id, id_services, id_building, description)
values (11, 7, 2, 'Ресторан работает с 8.00-10.00, и с 12.00-14.00, и с 17.00-19.00');

insert into building_service (id, id_services, id_building, description)
values (12, 7, 3, 'Ресторан работает с 8.00-10.00, и с 12.00-14.00, и с 17.00-19.00');

insert into building_service (id, id_services, id_building, description)
values (13, 8, 1, 'Бар работает с 18.00-20.00');

insert into building_service (id, id_services, id_building, description)
values (14, 8, 2, 'Бар работает с 18.00-20.00');

insert into building_service (id, id_services, id_building, description)
values (15, 8, 3, 'Бар работает с 18.00-20.00');

insert into company (id, name_company, fname_contact_person, contract_status, discription_activity, sale)
values (seq_company_id.nextval, 'Чебурашка', 'Крокодил Геннадий', 1, 'Проводят международные симпозиумы', 5);

insert into company (id, name_company, fname_contact_person, contract_status, discription_activity, sale)
values (seq_company_id.nextval, 'Крыска-Лариска', 'Шапокляк', 0, 'Проведение карнавалов', 10);

insert into company (id, name_company, fname_contact_person, contract_status, discription_activity, sale)
values (seq_company_id.nextval, 'Знайка', 'Незнайка', 1, 'Туристическая фирма', 10);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Череватый', "Владислав",to_date('28-07-1996', 'dd-mm-yyyy') ,"М", '89546742345', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Шепс', "Олег",to_date('29-04-1998', 'dd-mm-yyyy') ,"М", '89164130202', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Джебисашвили', "Лина",to_date('14-08-1985', 'dd-mm-yyyy') ,"Ж", '84953241897', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Шепс', "Александр",to_date('26-11-1986', 'dd-mm-yyyy') ,"М", '89546026745', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Шевченко', "Надежда",to_date('25-02-1964', 'dd-mm-yyyy') ,"Ж", '89832201890', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Райдос', "Виктория",to_date('27-12-1976', 'dd-mm-yyyy') ,"Ж", '84956669860', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Романова', "Марьяна",to_date('31-08-1979', 'dd-mm-yyyy') ,"Ж", '895467426709', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Гецати', "Константин",to_date('10-07-1987', 'dd-mm-yyyy') ,"М", '84957766610', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Матвеев', "Дмитрий",to_date('15-07-1997', 'dd-mm-yyyy') ,"М", '895467426745', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Башаров', "Марат",to_date('22-07-1974', 'dd-mm-yyyy') ,"М", '89657843254', 0);

insert into guest (id, last_name, first_name,date_birth, gender, contacts, amount_debt)
values (seq_guest_id.nextval, 'Ларионов', "Илья",to_date('28-10-1983', 'dd-mm-yyyy') ,"М", '84956784321', 0);


insert into application_settlement 
values (seq_app_settlement_id.nextval, null, (select id from guest where lower(last_name) like 'шевченко'), null, 3, 
        to_date('27-05-2023', 'dd-mm-yyyy'), to_date('28-05-2023', 'dd-mm-yyyy'), 
        to_date('02-06-2023', 'dd-mm-yyyy'), 1, 1, 0, 0, 'принято', 1, 1, 'оплачено');

insert into application_settlement 
values (seq_app_settlement_id.nextval, 1, null, 1, 4, to_date('28-05-2023', 'dd-mm-yyyy'), to_date('27-06-2023', 'dd-mm-yyyy'), 
        to_date('29-06-2023', 'dd-mm-yyyy'), 7, 0, 2, 1, 'принято', 0, 3, 'оплачено');

insert into application_settlement 
values (seq_app_settlement_id.nextval, 1, null, 3, 3, to_date('29-05-2023', 'dd-mm-yyyy'), to_date('19-06-2023', 'dd-mm-yyyy'), 
        to_date('25-06-2023', 'dd-mm-yyyy'), 3, 1, 1, 0, 'принято', 0, 2, 'не оплачено');

insert into number_building 
values (seq_number_building_id.nextval, 1101, 1, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1102, 1, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1103, 2, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1201, 1, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1202, 1, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1203, 1, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1301, 1, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1302, 2, 1);

insert into number_building 
values (seq_number_building_id.nextval, 1303, 2, 1);

insert into number_building 
values (seq_number_building_id.nextval, 2101, 2, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2102, 1, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2103, 1, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2201, 2, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2202, 2, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2203, 2, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2301, 1, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2302, 1, 2);

insert into number_building 
values (seq_number_building_id.nextval, 2303, 1, 2);

insert into number_building 
values (seq_number_building_id.nextval, 3101, 1, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3102, 1, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3103, 3, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3201, 1, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3202, 1, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3203, 2, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3301, 2, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3302, 2, 3);

insert into number_building 
values (seq_number_building_id.nextval, 3303, 3, 3);

insert into ordering_service
values (seq_ordering_service_id.nextval, (select id from guest where lower(last_name) like 'шевченко'), 
        (select id from list_services where lower(name_services) like 'бильярд'), 'не оплачено');
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'шевченко'),
        1, (select id from number_building where room_number = 1101));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'шепс' and lower(first_name) like 'олег'),
        2, (select id from number_building where room_number = 3303));

insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'шепс' and lower(first_name) like 'александр'),
        2, (select id from number_building where room_number = 3303));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'матвеев'),
        2, (select id from number_building where room_number = 3303));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'романова'),
        2, (select id from number_building where room_number = 3301));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'гецати'),
        2, (select id from number_building where room_number = 3301));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'райдос'),
        2, (select id from number_building where room_number = 3302));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'башаров'),
        3, (select id from number_building where room_number = 3302));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'джебисашвили'),
        3, (select id from number_building where room_number = 2101));
        
insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'череватый'),
        3, (select id from number_building where room_number = 2101));

insert into booking_room 
values (seq_booking_room_id.nextval, (select id from guest where lower(last_name) like 'ларионов'),
        3, (select id from number_building where room_number = 2102));

insert into complaints_suggestions
values (seq_complaints_suggestions_id.nextval, 1, 'В номере не было подачи холодной воды', to_date('31-05-2023', 'dd-mm-yyyy'));

-- что то нужно сделать со статистикой !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
