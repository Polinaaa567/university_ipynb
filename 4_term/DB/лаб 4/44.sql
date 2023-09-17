select c.name, e.last_name, e.first_name
from s_customer c Left Join s_emp e
on e.id = c.sales_rep_id;

/*2*/
select c.name, e.last_name, e.first_name
from s_customer c RIGHT Join s_emp e
on e.id = c.sales_rep_id;

/*3*/
select r.name , c.name 
from s_region r Full join s_customer c
on r.id = c.region_id 
where r.id is Null
or c.region_id is Null;

/*4*/
select ec.first_name, ec.last_name, t.title
from  s_emp_copy ec Join s_title t 
on ec.title like t.title;

/*5. Для каждого заказчика, общая сумма заказа которого превышает 100 000,
выведите наименование заказчика, заказанные им товары, их количество. 
Для соединения таблиц используйте JOIN.*/

select c.name, i.quantity, p.name
from s_customer c join s_ord o on c.id = o.CUSTOMER_ID 
join s_item i on o.id = i.ord_id 
join s_product p on  p.id = i.product_id
where o.total > 100000;

/*6. Получите список номеров и названий всех регионов,
наименований отделов в регионе с указанием количества сотрудников 
в каждом отделе. Для соединения таблиц используйте JOIN*/

select r.id, r.name, d.name, count(e.dept_id)
from s_dept d join s_region r on d.region_id = r.id
join s_emp e on e.dept_id = d.id
GROUP by r.name, r.id, d.name
order by r.name;

/*7. Выведите наименование каждого клиента, номер заказа 
и количество позиций в заказе. Для соединения таблиц используйте JOIN.*/

select c.name, o.id, count(i.quantity )
from s_customer c join s_ord o on c.id = o.customer_id 
join s_item i on i.ord_id = o.id
group by c.name, o.id
order by o.id;

/*8. Выведите наименования товаров и количество заказчиков данного товара.
Для соединения таблиц используйте JOIN.*/

select p.name, count(c.id)
from s_product p join s_item i on p.id = i.product_id
join s_ord o on i.ord_id = o.id 
join s_customer c on c.id = o.customer_id
group by i.product_id, p.name;

/*9.(2 балла) Составить таблицу умножения чисел от 1 до 10. 
Подсказка: создайте таблицу NUMBERS для хранения чисел от 1 до 10, 
используйте JOIN. */

select n.numb || ' * ' || nu.numb ,n.numb * nu.numb
from numbers n cross join numbers nu;

