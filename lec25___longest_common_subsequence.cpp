#include <bits/stdc++.h>
using namespace std;

#define cout(a) cout << a;

// Shorthand Values and Functions Names
#define max_int INT_MAX
#define min_int INT_MIN
#define INF 1e8
#define endl "\n"
#define pb push_back
#define pop pop_back

// Shorthand for-loop 
#define fori(a,b,n) for(int a = b ; a <= (n) ; a++)
#define ford(a,b,n) for(int a = b ; a >= (n) ; a--)

// Shorthand Array Methods
#define lbArray(arr , n , k) lower_bound(arr , arr + n , k) - arr.begin()
#define ubArray(arr , n , k) upper_bound(arr , arr + n , k) - arr.begin()
#define sortArray(arr , n) sort(arr , arr + n)
#define sumArray(arr , n) accumulate(arr , arr + n , 0)
#define maxArray(arr , n) *max_element(arr , arr + n)
#define minArray(arr , n) *min_element(arr , arr + n)


// Shorthand Vector Methods
#define lbVector(arr , k) lower_bound(arr.begin() , arr.end() , k) - arr.begin()
#define ubVector(arr , k) upper_bound(arr.begin() , arr.end() , k) - arr.begin()
#define sortVector(arr) sort(arr.begin(), arr.end())
#define sumVector(arr) accumulate(arr.begin() , arr.end() , 0)
#define maxVector(arr) *max_element(arr.begin() , arr.end())
#define minVector(arr) *min_element(arr.begin() , arr.end())


// Shorthand Containers and Datatypes
typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef unordered_set<int> ust;
typedef set<int> st;


// For taking input from external file and showing output in external file
void cp_function(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.in" , "r" , stdin);
		freopen("output.in" , "w" , stdout);
	#endif
}


int Recursive(string s1 , string s2 , int i , int j){
	if(i < 0 or j < 0) return 0;

	if(s1[i] == s2[j]) return 1 + Recursive(s1 , s2 , i-1 , j-1);

	// Going left on s1
	int left_s1 = Recursive(s1 , s2 , i-1 , j);

	// Going left in s2
	int left_s2 = Recursive(s1 , s2 , i , j-1);

	return max(left_s1 , left_s2);
}




int Recursive_shifting_indices(string s1 , string s2 , int i , int j){
	if(i == 0 or j == 0) return 0;

	if(s1[i-1] == s2[j-1]) return 1 + Recursive_shifting_indices(s1 , s2 , i-1 , j-1);

	// Going left on s1
	int left_s1 = Recursive_shifting_indices(s1 , s2 , i-1 , j);

	// Going left in s2
	int left_s2 = Recursive_shifting_indices(s1 , s2 , i , j-1);

	return max(left_s1 , left_s2);
}







int Memoization(string s1 , string s2 , int i , int j , vvi &dp){
	if(i < 0 or j < 0) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(s1[i] == s2[j]){
		dp[i][j] = 1 + Memoization(s1 , s2 , i-1 , j-1 , dp);
		return dp[i][j];
	}

	int left = Memoization(s1 , s2 , i-1 , j , dp);
	int right = Memoization(s1 , s2 , i , j-1 , dp);

	dp[i][j] = max(left , right);	

	return dp[i][j];
}







int Memoization_shifting_indices(string s1 , string s2 , int i , int j , vvi &dp){
	if(i == 0 or j == 0) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(s1[i-1] == s2[j-1]){
		dp[i][j] = 1 + Memoization_shifting_indices(s1 , s2 , i-1 , j-1 , dp);
		return dp[i][j];
	}

	int left = Memoization_shifting_indices(s1 , s2 , i-1 , j , dp);
	int right = Memoization_shifting_indices(s1 , s2 , i , j-1 , dp);

	dp[i][j] = max(left , right);	

	return dp[i][j];
}





int Tabulation(string s1 , string s2 , int n , int m){
	vvi dp(n+1 , vi(m+1 , 0));

	fori(i , 0 , m) dp[0][i] = 0;
	fori(i , 0 , n) dp[i][0] = 0;

	fori(i , 1 , n){
		fori(j , 1 , m){
			if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}

	return dp[n][m];
}






int Tabulation_Optimised(string s1 , string s2 , int n , int m){
	vi prev(m+1 , 0) , current(m+1 , 0);

	fori(i , 1 , n){
		fori(j , 1 , m){
			if(s1[i-1] == s2[j-1]) current[j] = 1 + prev[j-1];
			else current[j] = max(prev[j] , current[j-1]);
		}
		prev = current;
	}

	return prev[m];
	
}





int main(){

	cp_function();

	string s1 = "abvjbvfjk";
	string s2 = "akjdbvk";
	int n = s1.length();
	int m = s2.length();

	// cout << Recursive(s1 , s2 , n-1 , m-1);


	// cout << Recursive_shifting_indices(s1 , s2 , n , m);


	// vvi dp(n , vi(m , -1));
	// cout << Memoization(s1 , s2 , n-1 , m-1 , dp);



	// vvi dp(n+1 , vi(m+1 , -1));
	// cout << Memoization_shifting_indices(s1 , s2 , n , m , dp);



	cout << Tabulation(s1 , s2 , n , m);



	// cout << Tabulation_Optimised(s1 , s2 , n , m);

	return 0;
}