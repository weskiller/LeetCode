#https://leetcode.com/problems/word-frequency
cat words.txt|tr -s ' ' '\n'|awk '{++S[$1]}END{for (i in S) print i,S[i]}'|sort -k2 -rn 
