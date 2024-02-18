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


int Recursive(vi arr , int n , int k){
	if(k == 0) return true;
	if(n == 0) return (arr[0] == k);

	bool notPick = Recursive(arr , n-1 , k);
	bool pick = false;
	if(arr[n] <= k)
		 pick = Recursive(arr , n-1 , k-arr[n]);

	return (pick or notPick);
}


int Memoization(vi arr , int n , int k , vvi &dp){
	if(k == 0) return true;
	if(n == 0) return (arr[0] == k);
	if(dp[n][k] != -1) return dp[n][k];

	bool notPick = Memoization(arr , n-1 , k , dp);
	bool pick = false;
	if(arr[n] <= k)
		 pick = Memoization(arr , n-1 , k-arr[n] , dp);

	dp[n][k] = (pick or notPick);

	return dp[n][k];
}


int Tabulation(vi arr , int n , int k){
	vvi dp(n , vi(k+1 , 0));

	fori(i , 0 , n-1) dp[i][0] = true;
	if(arr[0] <= k) dp[0][arr[0]] = true;

	fori(i , 1 , n-1){
		fori(target , 1 , k){
			bool notPick = dp[i-1][target];
			bool pick = false;
			if(arr[i] <= target)
				 pick = dp[i-1][target-arr[i]];
			dp[i][target] = (pick or notPick);
		}
	}

	return dp[n-1][k];

}



int Tabulation_Optimised(vi arr , int n , int k){
	vi prev(k+1 , 0) , current(k+1 , 0);
	prev[0] = current[0] = true;
	prev[arr[0]] = true;

	fori(i , 1 , n-1){
		fori(target , 1 , k){
			bool notPick = prev[target];
			bool pick = false;
			if(arr[i] <= target)
				 pick = prev[target-arr[i]];
			current[target] = (pick or notPick);
		}
		prev = current;
	}

	return prev[k];

}




int main(){

	cp_function();

	vi arr = {3,2,8,9,5};
	int n = arr.size();
	int target = 10;

	// cout << Recursive(arr , n-1 , target);

	// vvi dp(n , vi(target+1 , -1));
	// cout << Memoization(arr , n-1 , target , dp);


	// cout << Tabulation(arr , n , target);


	cout << Tabulation_Optimised(arr , n , target);


	return 0;
}