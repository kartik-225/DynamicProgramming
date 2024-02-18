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
	if(j < 0) return 1;
	if(i < 0) return 0;

	if(s1[i] == s2[j])
		return Recursive(s1,s2, i-1 , j-1) + Recursive(s1,s2 , i-1 , j);
	else
		return Recursive(s1,s2,i-1,j);
}





int Memoization(string s1 , string s2 , int i , int j , vvi &dp){
	if(j < 0) return 1;
	if(i < 0) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(s1[i] == s2[j]){
		dp[i][j] = Memoization(s1,s2, i-1 , j-1 , dp) + Memoization(s1,s2 , i-1 , j , dp);
		return dp[i][j];
	}
	else{
		dp[i][j] = Memoization(s1,s2,i-1,j , dp);
		return dp[i][j];
	}
}





int Tabulation(string s1 , string s2 , int n , int m){
	vvi dp(n+1 , vi(m+1 , 0));

	fori(i , 0 , n) dp[i][0] = 1;
	fori(j , 1 , m) dp[0][j] = 0;

	fori(i , 1 , n){
		fori(j , 1 , m){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][m];

}



int TabulationOptitmised(string s1 , string s2 , int n , int m){
	vi prev(m+1 , 0) , current(m+1 , 0);

	prev[0] = current[0] = 1;

	fori(i , 1 , n){
		fori(j , 1 , m){
			if(s1[i-1] == s2[j-1])
				current[j] = prev[j-1] + prev[j];
			else
				current[j] = prev[j];
		}
		prev = current;
	}

	return prev[m];

}




int main(){

	cp_function();

	string s1 = "babgbag" , s2 = "bag";
	int n = s1.length() , m = s2.length();

	// cout << Recursive(s1,s2,n-1,m-1);

	// vvi dp(n , vi(m , -1));
	// cout << Memoization(s1,s2,n-1,m-1,dp);


	// cout << Tabulation(s1,s2,n,m);


	cout << TabulationOptitmised(s1,s2,n,m);



	return 0;
}