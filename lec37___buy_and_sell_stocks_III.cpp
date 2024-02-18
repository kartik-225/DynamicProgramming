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


int Recursive(vi price , int n , int buy , int i = 0 , int limit = 2){
	if(limit == 0) return 0;
	if(i == n) return 0;

	int profit = 0;

	if(buy)
		profit = max(-price[i] + Recursive(price , n , 0 , i+1 , limit) ,
					Recursive(price , n , 1 , i+1 , limit));
	else
		profit = max(price[i] + Recursive(price , n , 1 , i+1 , limit-1) , 
					Recursive(price , n , 0 , i+1 , limit));

	return profit;
}





int Memoization(vi price , int n , int buy , vector<vvi> &dp ,int limit = 2 , int i = 0){
	if(limit == 0) return 0;
	if(i == n) return 0;

	if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

	int profit = 0;

	if(buy)
		profit = max(-price[i] + Memoization(price , n , 0 , dp , limit , i+1) ,
					Memoization(price , n , 1 , dp , limit , i+1));
	else
		profit = max(price[i] + Memoization(price , n , 1 , dp , limit-1 , i+1) , 
					Memoization(price , n , 0 , dp , limit , i+1));

	dp[i][buy][limit] = profit;
	return dp[i][buy][limit];
}




int Tabulation(vi price , int n){
	vector<vector<vector<int> > > dp(n+1 , vector<vector<int> > (2 , vector <int> (3,-1)));

	fori(i , 0 , n-1){
		fori(buy , 0 , 1){
			dp[i][buy][0] = 0;
		}
	}

	fori(buy , 0 , 1){
		fori(limit , 0 , 2){
			dp[n][buy][limit] = 0;
		}
	}


	ford(i , n-1 , 0){
		fori(buy , 0 , 1){
			fori(limit , 1 , 2){
				int profit = 0;
				if(buy == 1)
					profit = max(-price[i] + dp[i+1][0][limit] , dp[i+1][1][limit]);
				else
					profit = max(price[i] + dp[i+1][1][limit-1] , dp[i+1][0][limit]);
				dp[i][buy][limit] = profit;
			}
		}
	}

	return dp[0][1][2];
}





int Tabulation_Optimised(vi price , int n){
	vvi next(2 , vi (3 , 0));
	vvi current(2 , vi (3 , 0));

	fori(i , 0 , n-1){
		fori(buy , 0 , 1){
			next[buy][0] = 0;
		}
	}

	fori(buy , 0 , 1){
		fori(limit , 0 , 2){
			next[buy][limit] = 0;
		}
	}


	ford(i , n-1 , 0){
		fori(buy , 0 , 1){
			fori(limit , 1 , 2){
				if(buy == 1)
					current[buy][limit] = max(-price[i] + next[0][limit] , next[1][limit]);
				else
					current[buy][limit] = max(price[i] + next[1][limit-1] , next[0][limit]);
			}
		}
		next = current;
	}

	return next[1][2];
}





int main(){

	cp_function();

	vi stocks = {3,3,5,0,0,3,1,4};
	int n = stocks.size();


	// cout << Recursive(stocks , n , 1);


	// vector<vector<vector<int> > > dp(n , vector<vector<int> > (2 , vector <int> (3,-1)));
	// cout << Memoization(stocks , n , 1 , dp);

	// cout << Tabulation(stocks,n);


	cout << Tabulation_Optimised(stocks,n);

	return 0;
}