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


int Recursive(vi coins , int n , int k){
	if(n == 0){
		if(k % coins[0] == 0) return k / coins[0];
		else return 1e9;
	}

	int notPick = Recursive(coins , n-1 , k);
	int pick = 1e9;
	if(coins[n] <= k)
		pick = 1 + Recursive(coins , n , k-coins[n]);

	return min(pick,notPick);
}




int Memoization(vi coins , int n , int k , vvi &dp){
	if(n == 0){
		if(k % coins[0] == 0) return k / coins[0];
		else return 1e9;
	}

	if(dp[n][k] != -1) return dp[n][k];

	int notPick = Memoization(coins , n-1 , k , dp);
	int pick = 1e9;
	if(coins[n] <= k)
		pick = 1 + Memoization(coins , n , k-coins[n] , dp);

	dp[n][k] = min(pick,notPick);
	return dp[n][k];
}



int Tabulation(vi coins , int n , int k){
	vvi dp(n , vi(k+1 , 0));
	fori(i , 0 , k){
		if(i % coins[0] == 0) dp[0][i] = i/coins[0];
		else dp[0][i] = 1e9;
	}

	fori(i , 1 , n-1){
		fori(target , 0 , k){
			int notPick = dp[i-1][target];
			int pick = 1e9;
			if(coins[i] <= target)
				pick = 1 + dp[i][target-coins[i]];

			dp[i][target] = min(pick,notPick);
		}
	}

	return dp[n-1][k];
}





int Tabulation_Optimised(vi coins , int n , int k){
	vi prev(k+1 , 0) , current(k+1 , 0);
	fori(i , 0 , k){
		if(i % coins[0] == 0) prev[i] = i/coins[0];
		else prev[i] = 1e9;
	}

	fori(i , 1 , n-1){
		fori(target , 0 , k){
			int notPick = prev[target];
			int pick = 1e9;
			if(coins[i] <= target)
				pick = 1 + current[target-coins[i]];

			current[target] = min(pick,notPick);
		}
		prev = current;
	}

	return prev[k];
}




int main(){

	cp_function();

	vi coins = {9,5,6,1};
	int n = coins.size();
	int k = 21;

	// cout << Recursive(coins , n-1 , k);


	// vvi dp(n , vi(k+1 , -1));
	// cout << Memoization(coins , n-1 , k , dp);


	// cout << Tabulation(coins , n , k);


	cout << Tabulation_Optimised(coins , n , k);

	return 0;
}