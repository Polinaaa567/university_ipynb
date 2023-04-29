/*1*/
create or replace view EMP_VU_2
        (ID, EMPLOYEE, DEPT_ID)
as select w2.id, w2.last_name, w2.dept_id
    from worker_2 w2;
    
select uw.view_name, uw.text
from user_views uw
where lower(uw.view_name) like 'emp_vu_2';

select *
from emp_vu_2;

--2

insert into worker_2
    values(worker_id_seq_2.nextval, 'Smith', 'Sergey', 54);
    
insert into worker_2 
    values(worker_id_seq_2.nextval, 'Kolesnik', 'Polina', 54);

select us.sequence_name, us.cache_size, us.max_value, us.increment_by, us.last_number
from user_sequences us
where lower(us.sequence_name) like 'dept_id_seq_2'
    or lower(us.sequence_name) like 'worker_id_seq_2';


update emp_vu_2 
set dept_id = 37
where lower(employee) like 'smith';

select *
from emp_vu_2;

--3
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

select * 
from EMP_VU_2;

--5

create or replace view EMP_VU_2
    (ID, EMPLOYEE, DEPT_ID)
as select id, last_name, dept_id
from worker_2
where dept_id = 37
with read only;

select * 
from EMP_VU_2;

--6 
update EMP_VU_2 
set dept_id = 54
where lower(employee) like 'smith'; --не получилось, так как сделали запрет операций dml

--7
--create or replace view Tovar_2
--;



