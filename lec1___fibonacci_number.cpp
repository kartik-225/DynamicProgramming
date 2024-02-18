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


int fib_recursion(int n){
	if(n <= 1)
		return n;

	int fib1 = fib_recursion(n-1);
	int fib2 = fib_recursion(n-2);

 	return fib1 + fib2;
}


int fib_memoization(int n , vi &dp){
	if(n <= 1)
		return n;

	if(dp[n] != -1)
		return dp[n];

	int fib1 = fib_memoization(n-1 , dp);
	int fib2 = fib_memoization(n-2 , dp);

	dp[n] = fib1 + fib2;

 	return dp[n];
}

int fib_tabulation(int n){
	vi dp(n+1 , 0);
	dp[0] = 0 , dp[1] = 1;
	fori(i , 2 , n){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int fib_tabulation_optimised(int n){
	int prev = 1 , second_prev = 0 , current;

	fori(i , 2 , n){
		current = prev + second_prev;
		second_prev = prev;
		prev = current;
	}

	return prev;

}




int main(){

	cp_function();

	// Recursion
	int n = 6;
	cout(fib_recursion(n));


	// Memoization
	// int n = 6;
	vi dp(n+10 , -1);
	cout(fib_memoization(n , dp));


	// Tabulation
	// int n = 6;
	cout(fib_tabulation(n));


	// Tabulation Optimised
	// int n = 6;
	cout(fib_tabulation_optimised(n));


	return 0;
}