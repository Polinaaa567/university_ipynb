/*1 Получить название и кредитный рейтинг всех клиентов,
находящихся в одном регионе с клиентом, 
название которого содержит буквы “w” и “s”*/
select c.name, c.credit_rating
from s_customer c
where c.region_id in (select cu.region_id
                        from s_customer cu
                        where lower(cu.name) like '%w%'
                        and lower(cu.name) like '%s%');
                        

/*2.1 Выдать названия заказчика и название региона, 
в котором он расположен, для всех заказчиков, 
сумма заказов которых больше средней суммы заказов за все время.*/
select c.name, r.name
from s_customer c join s_region r on c.region_id = r.id
where c.id in (select o.customer_id
                from s_ord o
                where total > (select avg(total)
                                from s_ord));

/*2.2 Выдать фамилии и названия отделов всех сотрубников,
которые оформляли заказы на суммы большие средней 
суммы заказов за все время.*/
select e.last_name, d.name
from s_emp e join s_dept d on e.dept_id = d.id
where e.id in (select o.sales_rep_id
                from s_ord o
                where o.total >(select avg(total)
                                from s_ord));
                                
/*3.1 Выдать название отдела, ФИО сотрудников и количество продаж
по каждому сотруднику для регионов, в которых есть заказчики с 
кредитный рейтингом EXCELLENT.*/
select d.name, e.first_name, e.last_name, count(*)
from s_emp e join s_ord o on e.id = o.sales_rep_id
    join s_dept d on e.dept_id = d.id
where e.id in (select SALES_REP_ID
            from s_customer
            where upper(credit_rating) like 'EXELLENT')
group by d.name, e.first_name, e.last_name;
--where c.id in (


/*3.2*/

select r.name, d.name, count(*)
from s_emp e, s_region r, s_dept d
where e.dept_id = d.id and r.id = d.region_id
and e.id in (select SALES_REP_ID
            from s_customer
            where lower(credit_rating) like 'GOOD')
group by r.name, d.name;

/*4*/

select e.last_name, manager_id
from s_emp e
where length(e.last_name) > 5
    and lower(e.last_name) like '%n%' 
      and lower(e.last_name) like '%a%'
      and e.id in (select worker.id
                    from s_emp worker, s_emp manager
                    where worker.manager_id = manager.id()

      );
      

/*5*/
select e.id, e.salary,e.start_date, count(*)
from s_emp e join s_ord o on e.id = o.sales_rep_id
where e.id in (select id
from s_emp 
where salary  Not between 2000 and 3000 
and salary not between 500 and 1000
and start_date between to_date('01.03.1990', 'dd.mm.yyyy') and to_date('31.05.1990', 'dd.mm.yyyy'))
group by e.id, e.salary,e.start_date
having count(*) > 1

