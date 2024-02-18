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


int Recursive(vi price , int n , int buy , int i = 0){
	if(i == n) return 0;

	int profit = 0;

	if(buy)
		profit = max(-price[i] + Recursive(price , n , 0 , i+1) ,
					Recursive(price , n , 1 , i+1));
	else
		profit = max(price[i] + Recursive(price , n , 1 , i+1) , 
					Recursive(price , n , 0 , i+1));

	return profit;
}





int Memoization(vi price , int n , int buy , vvi &dp , int i = 0){
	if(i == n) return 0;

	if(dp[i][buy] != -1) return dp[i][buy];

	int profit = 0;

	if(buy)
		profit = max(-price[i] + Memoization(price , n , 0 , dp , i+1) ,
					Memoization(price , n , 1 , dp , i+1));
	else
		profit = max(price[i] + Memoization(price , n , 1 , dp , i+1) , 
					Memoization(price , n , 0 , dp , i+1));

	dp[i][buy] = profit;
	return dp[i][buy];
}




int Tabulation(vi price , int n){
	vvi dp(n+1 , vi(2 , 0));

	dp[n][0] = dp[n][1] = 0;


	ford(i , n-1 , 0){
		fori(buy , 0 , 1){
			int profit = 0;
			if(buy == 1)
				profit = max(-price[i] + dp[i+1][0] , dp[i+1][1]);
			else
				profit = max(price[i] + dp[i+1][1] , dp[i+1][0]);
			dp[i][buy] = profit;
		}
	}

	return dp[0][1];
}





int Tabulation_Optimised(vi price , int n){
	vi next(2 , 0) , current(2 , 0);

	next[0] = next[1] = 0;


	ford(i , n-1 , 0){
		fori(buy , 0 , 1){
			int profit = 0;
			if(buy == 1)
				profit = max(-price[i] + next[0] , next[1]);
			else
				profit = max(price[i] + next[1] , next[0]);
			current[buy] = profit;
		}
		next = current;
	}

	return next[1];
}





int main(){

	cp_function();

	vi stocks = {7,1,5,3,6,4};
	int n = stocks.size();


	// cout << Recursive(stocks , n , 1);


	// vvi dp(n , vi(2 , -1));
	// cout << Memoization(stocks , n , 1 , dp);

	// cout << Tabulation(stocks,n);


	cout << Tabulation_Optimised(stocks,n);

	return 0;
}