create sequence DEPT_ID_SEQ_2
    start with 76
    increment by 1
    maxvalue 80
    nocache
    nocycle;
    
    select * 
    from user_sequences us;
    
    
/*2*/
create sequence WORKER_ID_SEQ_2
    start with 204
    increment by 1
    maxvalue 9999999
    cache 5
    nocycle;
    
/*3*/

select us.sequence_name, us.cache_size, us.max_value, us.increment_by, us.last_number
from user_sequences us
where lower(us.sequence_name) like 'dept_id_seq_2'
    or lower(us.sequence_name) like 'worker_id_seq_2';

/*4*/
insert into department_2
    values (DEPT_ID_SEQ_2.NEXTVAL, 'Education');
insert into department_2
    values (DEPT_ID_SEQ_2.NEXTVAL, 'Administration');
    
select * 
from department_2;
    
select us.sequence_name, us.cache_size, us.max_value, us.increment_by, us.last_number
from user_sequences us
where lower(us.sequence_name) like 'dept_id_seq_2';

/*5*/
insert into worker_2
    values (worker_id_seq_2.nextval, 'Lira', 'Tomas', dept_id_seq_2.currval);
    
insert into department_2 
    values(dept_id_seq_2.nextval, 'Finance');
    
insert into worker_2
    values (worker_id_seq_2.nextval, 'Seigher', 'Anna', 
            (select id from department_2 where lower(name) = 'finance'));
            
delete from worker_2 
where lower(first_name) like 'anna';

select *
from worker_2;

select * 
from department_2;

/*6*/
create index worker_2_dept_id_idx
    on worker_2(dept_id); 
create index worker_2_last_name_idx
    on worker_2(last_name);

/*7*/
select ic.index_name, ic.column_name,
ic.column_position col_pos,ix.uniqueness
from user_indexes ix, user_ind_columns ic
where ic.index_name = ix.index_name
    and (lower(ic.table_name) = 'worker_2'
        or lower(ic.table_name) = 'department_2'); -- 900 из worker_2
        --002 department_2

/*8*/
alter table worker_2 
drop primary key cascade;

select ic.index_name, ic.column_name,
ic.column_position col_pos,ix.uniqueness
from user_indexes ix, user_ind_columns ic
where ic.index_name = ix.index_name
    and (lower(ic.table_name) = 'worker_2'
        or lower(ic.table_name) = 'department_2');

/*9*/

alter table worker_2
add constraint worker_2_id_pk primary key(ID);


select ic.index_name, ic.column_name,
ic.column_position col_pos,ix.uniqueness
from user_indexes ix, user_ind_columns ic
where ic.index_name = ix.index_name
    and (lower(ic.table_name) = 'worker_2');


/*10*/
drop index worker_2_last_name_idx;

select ic.index_name, ic.column_name,
ic.column_position col_pos,ix.uniqueness
from user_indexes ix, user_ind_columns ic
where ic.index_name = ix.index_name
    and (lower(ic.table_name) = 'worker_2');