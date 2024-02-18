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



int Recursive(vi arr , int n){
	if(n == 0) return arr[0];
	if(n < 0) return 0;

	int pickSum = arr[n] + Recursive(arr , n-2);
	int notPickSum = Recursive(arr,n-1);

	return max(pickSum , notPickSum);
}




int Memoization(vi arr , int n , vi &dp){
	if(n == 0) return arr[0];
	if(n < 0) return 0;
	if(dp[n] != -1) return dp[n];

	int pickSum = arr[n] + Memoization(arr , n-2 , dp);
	int notPickSum = Memoization(arr,n-1 , dp);

	dp[n] = max(pickSum , notPickSum);

	return dp[n];

}


int Tabulation(vi arr , int n){
	vi dp(n+1 , 0);

	dp[0] = arr[0];

	int pickSum = 0 , notPickSum = 0;
	fori(i , 1 , n){
		pickSum = arr[i];
		if(i-2 >= 0)
			pickSum += dp[i-2];;
		notPickSum = dp[i-1];
		dp[i] = max(pickSum , notPickSum);
	}

	return dp[n];

}


int Tabulation_Optimised(vi arr , int n){
	int prev2 = 0 , prev1 = 0;	
	prev2 = arr[0];
	prev1 = max(arr[0] , arr[1]);

	int pickSum = 0 , notPickSum = 0 , current = 0;
	fori(i , 2 , n){
		if(i-2 >= 0)
			pickSum = arr[i] + prev2;
		if(i-1 >= 0)
			notPickSum = prev1;
		current = max(pickSum , notPickSum);
		prev2 = prev1;
		prev1 = current;
	}

	return prev1;

}


int main(){

	cp_function();

	vi arr = {115,7,9,3,6,50};
	int n = arr.size();

	vi left , right;
	fori(i , 0 , n-1){
		if(i != 0)
			left.pb(arr[i]);
		if(i != n-1)
			right.pb(arr[i]);
	}


	// Recursion
	int leftSum = Recursive(left,n-2);
	int rightSum = Recursive(right,n-2);
	cout << max(leftSum , rightSum);


	// Memoization
	/*vi dp(n , -1);
	cout(Memoization(arr , n-1 , dp));*/


	// Tabulation
	/*cout(Tabulation(arr , n-1));*/


	// Tabulation Optimised
	/*cout(Tabulation_Optimised(arr,n-1));*/

	return 0;
}