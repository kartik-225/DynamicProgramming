def solve(s1 , s2 , i , j):
	if i < 0 or j < 0 : return 0

	if(s1[i] == s2[j]) : return 1 + solve(s1 , s2 , i-1 , j-1)

	return max(solve(s1 , s2 , i-1 , j) , solve(s1 , s2 , i , j-1))


s1 = "aefksn"
s2 = "ak"
print(solve(s1 , s2 , len(s1)-1 , len(s2)-1))