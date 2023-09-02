/*1) Получить перечень и общее число фирм, забронировавших места в объеме, не менее указанного, 
за весь период сотрудничества, либо за некоторый период*/
-- Взяла период с 01-06 по 15-06-2023
select bo.id,c.name_company, sum(bo.number_rooms)
from booking_order bo join company c on bo.company_id = c.id
where bo.booking_date between to_date('01-06-2023', 'dd-mm-yyyy') 
and to_date('15-06-2023', 'dd-mm-yyyy')
and bo.company_id is not null
group by bo.id,c.name_company
having sum(bo.number_rooms) > 4;

--2.Получить перечень и общее число постояльцев, 
-- заселявшихся в номера с указанными характеристиками за некоторый период. 

select bo.building_id,bo.hotel_class_stars, sum(bo.number_people)
from booking_order bo 
where bo.arrival_date >= to_date('01-06-2023', 'dd-mm-yyyy')
and bo.departure_date <= to_date('30-06-2023', 'dd-mm-yyyy')
and bo.order_processing_status like 'принят'
group by bo.building_id, bo.hotel_class_stars;

-- 8.	Получить сведения о фирмах, с которыми заключены договора о брони 
--      на указанный период
select c.id, c.name_company, c.fname_contact_person, c.contract_status, c.discription_activity, c.sale
from company c join booking_order bo 
                on c.id = bo.company_id
where bo.arrival_date >= to_date('01-06-2023', 'dd-mm-yyyy')
and bo.departure_date <= to_date('30-06-2023', 'dd-mm-yyyy')
and bo.order_processing_status like 'принят';