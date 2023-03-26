/*1*/
select e.first_name, e.last_name, to_date(e.start_date)
from s_emp e
where e.dept_id = (select e1.dept_id 
from s_emp e1 where e1.last_name = 'Magee')
and e.last_name not like 'Magee';
/*2*/
select e.id, e.first_name, e.last_name
from s_emp e
WHERE e.SALARY > (SELECT AVG(SALARY) FROM s_emp);
/*3*/
SELECT e.last_name, e. dept_id, e.title
FROM S_EMP e 
WHERE e.DEPT_ID IN (SELECT ID FROM S_DEPT WHERE REGION_ID IN (1,2));
/*4*/
select e.last_name, e.salary
from s_emp e
where manager_id = (Select id from s_emp e1 where lower(e1.first_name) like 'ladoris'
and lower(e1.last_name) like 'ngao');

/*5*/
select e.id, e.first_name, e.last_name
from s_emp e
where e.salary >= (select avg(e1.salary)
                    from s_emp e1
                    where lower(e1.last_name) like '%t%'
                    and e1.dept_id = e.dept_id);

/*6*/
select c.id, c.name, c.credit_rating, e.last_name
from s_customer c join s_emp e on c.sales_rep_id = e.id
where c.region_id in (select id 
                        from s_region r
                        where lower (r.name) like 's.america') 
or lower(e.last_name) like 'nguyen';

/*7*/
select p.name, p.short_desc
from s_ord o join s_item i on o.id = i.ord_id
join s_product p on p.id = i.product_id
where p.id not in (select i1.product_id
                    from s_ord o1 join s_item i1 on o1.ID=i1.ORD_ID
                    where TO_NUMBER(TO_CHAR(o1.DATE_ORDERED,'yyyy'))=1992
                    AND TO_NUMBER(TO_CHAR(o1.DATE_ORDERED,'mm')) = 9);
/*8*/



