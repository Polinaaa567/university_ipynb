CREATE TABLE DEPARTMENT_2
   (	ID NUMBER(7,0) NOT NULL PRIMARY KEY, 
        NAME VARCHAR(25)
    );


CREATE TABLE EMPLOYEE_2
   (	ID              NUMBER(7,0) NOT NULL PRIMARY KEY, 
        LAST_NAME       VARCHAR(25),
        FIRST_NAME      VARCHAR(25),
        DEPT_ID         NUMBER(7,0) NOT NULL,
        FOREIGN KEY(DEPT_ID) REFERENCES DEPARTMENT_2 (ID)
    );
    
describe DEPARTMENT_2;
select object_name, created, timestamp
from user_objects
where lower(object_name) = 'department_2'
or lower(object_name) = 'employee_2';
-------------------------------------
/*2*/
SELECT *
FROM user_objects
WHERE UPPER(object_type) LIKE 'TABLE';

/*3*/

select *
from user_objects
where lower(object_name) = 'department_2'
or lower(object_name) = 'employee_2';
 
/*4*/
select table_name, constraint_name, constraint_type, search_condition, r_constraint_name
 from user_constraints
 where lower(table_name) = 'department_2'
 or lower(table_name) = 'employee_2';
 
 /*5*/
Create table WORKER_2 
   AS 
    select *
    from employee_2;
    
describe worker_2;    
    
SELECT table_name, constraint_name, constraint_type, search_condition, r_constraint_name
 FROM user_constraints
 WHERE lower(table_name) = 'worker_2'
 or lower(table_name) = 'employee_2'
 order by table_name, constraint_type;

 select *
from user_objects
where object_name = 'WORKER_2'
or lower(object_name) = 'employee_2';

/*6*/

ALTER TABLE worker_2
add PRIMARY key (id)

/*7*/
alter table worker_2
add foreign key (dept_id)
references DEPARTMENT_2 (id);

/*8*/
select uo.object_name, uo.object_type
from user_objects uo
where lower(uo.object_type) LIKE 'table'
and (lower(uo.object_name) = 'employee_2'
or lower(uo.object_name) = 'worker_2'
or lower(uo.object_name) = 'department_2'
);

/* 9. работа с department_2 and employee_2 */
insert into department_2
values (37, 'Marketing');

insert into department_2
values (54, 'Sales');

insert into department_2
values (75, 'Personnel');

select *
from department_2;

savepoint update_done;

delete department_2;

select *
from department_2;

ROLLBACK to update_done;

select *
from department_2;

commit;