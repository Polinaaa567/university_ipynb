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

insert into building (id, number_floors, total_number_rooms, 
                    number_rooms_floor, number_single_rooms, 
                    number_double_rooms, number_triple_rooms, 
                    address, id_hotel_class)
values (1, 3, 9, 3, 6, 3, 0, 'ВанПисовский переулок 1а', 2);

insert into building (id, number_floors, total_number_rooms, 
                    number_rooms_floor, number_single_rooms, 
                    number_double_rooms, number_triple_rooms, 
                    address, id_hotel_class)
values (2, 3, 9, 3, 5, 4, 0, 'улица Стального Алхимика 3б', 3);

insert into building (id, number_floors, total_number_rooms, 
                    number_rooms_floor, number_single_rooms, 
                    number_double_rooms, number_triple_rooms, 
                    address, id_hotel_class)
values (3, 3, 9, 3, 4, 3, 2, 'улица Великолепного Усуи Такуми', 4);

insert into table (column)
values (values)
