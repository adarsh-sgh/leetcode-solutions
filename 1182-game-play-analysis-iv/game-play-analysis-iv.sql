
SELECT 
ROUND(count(t2.player_id)/count(t1.player_id),2) as fraction 
from 
(SELECT player_id, min(event_date) as md from Activity group by player_id) as t1 LEFT Join Activity as t2 
on t1.player_id = t2.player_id AND DATEDIFF(t2.event_date,t1.md) = 1;