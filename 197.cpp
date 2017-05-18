//Subject:  https://leetcode.com/problems/rising-temperature
//Example 1
SELECT w1.Id FROM Weather w1, Weather w2
WHERE subdate(w1.Date, 1)=w2.Date AND w1.Temperature>w2.Temperature
//Example 2
SELECT wt1.Id 
FROM Weather wt1, Weather wt2
WHERE wt1.Temperature > wt2.Temperature AND 
      TO_DAYS(wt1.DATE)-TO_DAYS(wt2.DATE)=1;