# Write your MySQL query statement below
select name as Customers from Customers 
where ID not in (select CustomerID from Orders)