# Write your MySQL query statement below
SELECT Prices.product_id, ROUND(SUM(Prices.price * UnitsSold.units)/SUM(UnitsSold.units),2) as average_price from Prices Join UnitsSold on 
Prices.product_id = UnitsSold.product_id AND UnitsSold.purchase_date BETWEEN Prices.start_date AND Prices.end_date GROUP BY product_id;