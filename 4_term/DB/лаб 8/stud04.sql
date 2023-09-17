/*1*/
create or replace view EMP_VU_2
        (ID, EMPLOYEE, DEPT_ID)
as select w2.id, w2.last_name, w2.dept_id
    from worker_2 w2;
    
select uw.view_name, uw.text
from user_views uw
where lower(uw.view_name) like 'emp_vu_2';

select *
from worker_2;

--2

insert into worker_2
    values(worker_id_seq_2.nextval, 'Smith', 'Sergey', 54);

update emp_vu_2 
set dept_id = 37
where lower(employee) like 'smith';

select *
from emp_vu_2;

--3
insert into worker_2 
    values(worker_id_seq_2.nextval, 'Kolesnik', 'Polina', 54);

create or replace view MNS_VU_2
as select w2.id, w2.last_name, w2.first_name, w2.dept_id 
from department_2 d2, worker_2 w2
where d2.id = w2.dept_id 
and (lower(d2.name) like 'marketing' 
    or lower(d2.name) like 'sales');
    
select uw.view_name, uw.text
from user_views uw
where lower(uw.view_name) like 'mns_vu_2';    
    
select *
from mns_vu_2;
    
--4
select dept_id, count(*)
from MNS_VU_2
group by dept_id;

--5

create or replace view EMP_VU_2
    (ID, EMPLOYEE, DEPT_ID)
as select id, last_name, dept_id
from worker_2
where dept_id = 37
with read only;

select * 
from emp_vu_2;

--6 
update EMP_VU_2 
set dept_id = 54
where lower(employee) like 'smith'; --не получилось, так как сделали запрет операций dml

--7
create or replace view PRODUCT_VU2
as select p.id, p.name, o.date_ordered
from s_ord o join s_item i on o.id = i.ord_id
full join s_product p on p.id = i.product_id
where p.id not in (select i1.product_id
                    from s_ord o1 join s_item i1 on o1.id = i1.ord_id
                    where to_number(to_char(o1.date_ordered,'yyyy')) = 1992);

select *
from product_vu2;

--8
create or replace view SHOP_VU2
as select c.name "customer name", p.name "product name", i.quantity, p.suggested_whlsl_price * i.quantity "price" 
from s_customer c  join s_ord o on o.customer_id = c.id
    join s_item i on i.ord_id = o.id
    join s_product p on i.product_id = p.id
where c.region_id = 1
order by c.name;

select *
from shop_vu2;

