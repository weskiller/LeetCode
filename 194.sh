#https://leetcode.com/problems/transpose-file
cat file.txt |awk 'BEGIN{MAX=0}{if (NF>MAX) MAX=NF ;for (i=1;i<=NF;i++) word[i]=word[i] " " $i }END{for (i=1;i<=MAX;i++) print word[i]}'|sed 's/^ //g'
