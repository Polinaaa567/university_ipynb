/*1	Выведите имя, фамилию и дату начала работы всех сотрудников, 
работающих в одном отделе с “Magee”.*/

select e.first_name, e.last_name, to_date(e.start_date)
from s_emp e
where e.dept_id = (select e1.dept_id 
                    from s_emp e1 where e1.last_name = 'Magee')
and e.last_name not like 'Magee';


/*2. Выведите номер, имя, фамилию и имя пользователя для всех сотрудников,
заработная плата которых выше средней*/

select e.id, e.first_name, e.last_name
from s_emp e
WHERE e.SALARY > (SELECT AVG(SALARY) 
                    FROM s_emp);


/*3. Выведите фамилию, номер отдела и должность всех сотрудников, 
относящихся к регионам 1 или 2*/

SELECT e.last_name, e. dept_id, e.title
FROM S_EMP e 
WHERE e.DEPT_ID IN (SELECT ID 
                    FROM S_DEPT 
                    WHERE REGION_ID IN (1,2));


/*4. Выведите фамилию и заработную плату всех подчиненных “LaDoris Ngao”*/

select e.last_name, e.salary
from s_emp e
where manager_id = (Select id 
                    from s_emp e1 
                    where lower(e1.first_name) like 'ladoris'
                    and lower(e1.last_name) like 'ngao');


/*5. Выведите номер, имя и фамилию каждого сотрудника, 
который получает заработную плату выше средней и работает в одном отделе
с любым сотрудником, фамилия которого содержит букву “t”.*/

select e.id, e.first_name, e.last_name
from s_emp e
where e.salary >= (select avg(e1.salary)
                    from s_emp e1
                    where lower(e1.last_name) like '%t%'
                    and e1.dept_id = e.dept_id);


/*6. Выведите номер и наименование клиента, 
а также кредитный рейтинг и фамилию торгового представителя
для всех клиентов, которые расположены в Северной Америке
или чьим торговым представителем является “Nguyen”*/
select c.id, c.name, c.credit_rating, e.last_name
from s_customer c join s_emp e on c.sales_rep_id = e.id
where c.region_id in (select id 
                        from s_region r
                        where lower (r.name) like 's.america') 
or lower(e.last_name) like 'nguyen';


/*7. Выведите наименование и краткое описание каждого товара, 
который ни разу не был заказан в сентябре 1992 г.*/
select p.name, p.short_desc
from s_ord o join s_item i on o.id = i.ord_id
join s_product p on p.id = i.product_id
where p.id not in (select i1.product_id
                    from s_ord o1 join s_item i1 on o1.ID=i1.ORD_ID
                    where TO_NUMBER(TO_CHAR(o1.DATE_ORDERED,'yyyy'))=1992
                    AND TO_NUMBER(TO_CHAR(o1.DATE_ORDERED,'mm')) = 9);


/*8. Выведите наименование и кредитный рейтинг всех клиентов, 
чьим торговым представителем является “Andre Dumas”. 
Что получилось и почему?*/
select c.name, c.credit_rating
from s_customer c
where c.sales_rep_id = (select e.id
                        from s_emp e
                        where lower(e.last_name) like '%dumas%' 
                        and lower(e.first_name) like '%andre%');
-- такого сотрудника вообще нет

/*9.Выведите фамилию каждого торгового представителя в регионах 1 и 2,
 наименования их клиентов и итоговые суммы заказов каждого клиента.*/
select e.last_name, c.name, nvl(sum(total),0)
from s_emp e join s_ord o on  e.id = o.sales_rep_id
join s_customer c on o.customer_id = c.id
where e.dept_id in (select d.id
                    from s_dept d 
                    where d.region_id = 1 
                    or d.region_id = 2)
group by e.last_name, c.name;


/*10.	Определите наименование фирмы, 
которая сделала максимальное количество заказов 
(предполагается, что такая фирма одна)*/
select c.name, count(o.id)
from s_customer c join s_ord o on c.id = o.customer_id
group by c.name
having count(o.customer_id) in (select max(count(*))
                                from S_ORD
                                group by CUSTOMER_ID);
