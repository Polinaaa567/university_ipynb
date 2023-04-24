/*1*/
create or replace view EMP_VU_2
        (ID, EMPLOYEE, DEPT_ID)
as select w2.id, w2.last_name, w2.dept_id
    from worker_2 w2;
    
select uw.view_name, uw.text
from user_views uw;
--where lower(uw.view_name) like 'emp_vu_2';

select *
from emp_vu_2;

--2

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
    
    select *
    from emp_VU1;
    
    
    

