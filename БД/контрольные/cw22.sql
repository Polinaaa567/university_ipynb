/*1.	Получить название и кредитный рейтинг всех клиентов, 
находящихся в одном регионе с клиентом, 
название которого содержит буквы “w” и “s”*/

select c.name, c.credit_rating
from s_customer c
where c.region_id in (select cu.region_id
                        from s_customer cu
                        where lower(cu.name) like '%w%'
                        and lower(cu.name) like '%s%');
                        
/*2.	Выдать названия заказчика и название региона, 
в котором он расположен, для всех заказчиков, 
сумма заказов которых больше средней суммы заказов за все время.*/

select c.name, r.name
from s_customer c full join s_region r on c.region_id = r.id
where c.id in (select o.customer_id
                from s_ord o
                where total > (select avg(total)
                                from s_ord));

/*3.	Выдать название отдела, ФИО сотрудников и количество продаж 
по каждому сотруднику для регионов, в которых есть заказчики 
с кредитный рейтингом EXELLENT.*/

select d.name, e.first_name, e.last_name, count(*)
from s_emp e join s_ord o on e.id = o.sales_rep_id
            join s_dept d on e.dept_id = d.id
where e.id in (select SALES_REP_ID
                from s_customer
                where upper(credit_rating) like 'EXELLENT')
group by d.name, e.first_name, e.last_name;

/*4.	Написать запрос, выводящий фамилии сотрудников, 
если они длиннее пяти символов и содержат буквы n и a 
вне зависимости от регистра. А также должен выводиться номер
менеджера или надпись 'NO', если менеджера у сотрудника нет.*/

select e.last_name, NVL(to_char(e.manager_id), 'NO')
from s_emp e
where length(e.last_name) > 5
and lower(e.last_name) like '%n%' 
and lower(e.last_name) like '%a%'
and e.manager_id in (select id
             from s_emp );
      
/*5.    (2 балла) Выдать название региона, название клиента и 
количество покупок по каждому клиенту, совершившему более 1 покупки, 
для регионов, в которых есть отделы в названии которых содержится 2 буквы s.*/

select r.name, c.name, count(*)
from s_region r join s_customer c on c.region_id = r.id
join s_ord o on o.customer_id = c.id
where r.id in (select region_id
                from s_dept
                where lower(name) like '%s%s%')
group by r.name, c.name
having count(*) > 1; 

/*6.	(2 балла) ФИО сотрудников и количество продаж каждого для самого многочисленного отдела.
Если таких отделов несколько, то выдать сотрудников для всех отделов.*/

select e.last_name, e.first_name, count(*)
from s_emp e join s_ord o on e.id = o.sales_rep_id --заказы
where e.dept_id in (select max(count(*))
                                from S_emp e
                                group by e.dept_id)
GROUP by e.last_name, e.first_name

