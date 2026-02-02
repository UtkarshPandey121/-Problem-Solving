SELECT 
P.product_name,
    s.year,
    s.price
FROM Sales s
INNER JOIN Product P
ON s.product_id = P.product_id;
