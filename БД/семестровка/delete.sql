drop table statistics;
drop table ordering_service; 
drop table complaints_suggestions;
drop table booking_room;
drop table booking_order;
drop table guest;
drop table company;
drop table building_service;
drop table list_services;
drop table building_room;
drop table building;
drop table price_room;
drop table hotel_class;

drop sequence seq_company_id;
drop sequence seq_guest_id;
drop sequence seq_booking_order_id;
drop sequence seq_building_room_id;
drop sequence seq_ordering_service_id;
drop sequence seq_booking_room_id;
drop sequence seq_complaints_suggestions_id;

drop view get_accepted_orders;
drop view current_b_ord_id;
drop view processing_filter_limits;
drop view free_rooms_order_dates;
drop view building_view_for_id;