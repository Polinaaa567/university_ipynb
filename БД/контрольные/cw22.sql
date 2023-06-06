/*1.	�������� �������� � ��������� ������� ���� ��������, 
����������� � ����� ������� � ��������, 
�������� �������� �������� ����� �w� � �s�*/

select c.name, c.credit_rating
from s_customer c
where c.region_id in (select cu.region_id
                        from s_customer cu
                        where lower(cu.name) like '%w%'
                        and lower(cu.name) like '%s%');
                        
/*2.	������ �������� ��������� � �������� �������, 
� ������� �� ����������, ��� ���� ����������, 
����� ������� ������� ������ ������� ����� ������� �� ��� �����.*/

select c.name, r.name
from s_customer c full join s_region r on c.region_id = r.id
where c.id in (select o.customer_id
                from s_ord o
                where total > (select avg(total)
                                from s_ord));

/*3.	������ �������� ������, ��� ����������� � ���������� ������ 
�� ������� ���������� ��� ��������, � ������� ���� ��������� 
� ��������� ��������� EXELLENT.*/

select d.name, e.first_name, e.last_name, count(*)
from s_emp e join s_ord o on e.id = o.sales_rep_id
            join s_dept d on e.dept_id = d.id
where e.id in (select SALES_REP_ID
                from s_customer
                where upper(credit_rating) like 'EXELLENT')
group by d.name, e.first_name, e.last_name;

/*4.	�������� ������, ��������� ������� �����������, 
���� ��� ������� ���� �������� � �������� ����� n � a 
��� ����������� �� ��������. � ����� ������ ���������� �����
��������� ��� ������� 'NO', ���� ��������� � ���������� ���.*/

select e.last_name, NVL(to_char(e.manager_id), 'NO')
from s_emp e
where length(e.last_name) > 5
and lower(e.last_name) like '%n%' 
and lower(e.last_name) like '%a%'
and e.manager_id in (select id
             from s_emp );
      
/*5.    (2 �����) ������ �������� �������, �������� ������� � 
���������� ������� �� ������� �������, ������������ ����� 1 �������, 
��� ��������, � ������� ���� ������ � �������� ������� ���������� 2 ����� s.*/

select r.name, c.name, count(*)
from s_region r join s_customer c on c.region_id = r.id
join s_ord o on o.customer_id = c.id
where r.id in (select region_id
                from s_dept
                where lower(name) like '%s%s%')
group by r.name, c.name
having count(*) > 1; 

/*6.	(2 �����) ��� ����������� � ���������� ������ ������� ��� ������ ��������������� ������.
���� ����� ������� ���������, �� ������ ����������� ��� ���� �������.*/

select e.last_name, e.first_name, count(*)
from s_emp e join s_ord o on e.id = o.sales_rep_id --������
where e.dept_id in (select max(count(*))
                                from S_emp e
                                group by e.dept_id)
GROUP by e.last_name, e.first_name

