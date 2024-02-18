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
	if(k == 0) return 1;
	if(n == 0) return (arr[0] == k);

	int notPick = Recursive(arr , n-1 , k);
	int pick = 0;
	if(arr[n] <= k)
		pick = Recursive(arr , n-1 , k-arr[n]);

	return pick + notPick;

}



int Memoization(vi arr , int n , int k , vvi &dp){
	if(k == 0) return 1;
	if(n == 0) return (arr[0] == k);
	if(dp[n][k] != -1) return dp[n][k];

	int notPick = Memoization(arr , n-1 , k , dp);
	int pick = 0;
	if(arr[n] <= k)
		pick = Memoization(arr , n-1 , k-arr[n] , dp);

	dp[n][k] = pick + notPick;

	return dp[n][k];

}



int Tabulation(vi arr , int n , int k){
	vvi dp(n , vi(k+1 , 0));
	fori(i , 0 , n-1) dp[i][0] = 1;
	if(arr[0] <= k) dp[0][arr[0]] = 1;

	fori(i , 1 , n-1){
		fori(sum , 1 , k){
			int notPick = dp[i-1][sum];
			int pick = 0;
			if(arr[i] <= sum)
				pick = dp[i-1][sum - arr[i]];
		
			dp[i][sum] = pick + notPick;
		}
	}

	return dp[n-1][k];
}


int Recursive_if_there_are_zeroes_in_array(vi arr , int n , int k){
	if(n == 0){
		if(sum == 0 and arr[0] == 0) return 2;
		if(sum == 0 or arr[0] == sum) return 1;
		else return 0;
	}

	int notPick = Recursive(arr , n-1 , k);
	int pick = 0;
	if(arr[n] <= k)
		pick = Recursive(arr , n-1 , k-arr[n]);

	return pick + notPick;

}





int main(){

	cp_function();

	vi arr = {1,4,2,3,5};
	int n = arr.size();
	int target = 8;

	// cout << Recursive(arr , n-1 , target);


	// vvi dp(n , vi(target+1 , -1));
	// cout << Memoization(arr , n-1 , target , dp);


	cout << Tabulation(arr , n , target);

	return 0;
}