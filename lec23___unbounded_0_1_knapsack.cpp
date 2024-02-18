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




int Recursive(vi weights , vi values , int n , int maxWeight){
	if(n == 0) return (maxWeight / weights[0]) * values[0];

	int notPick = Recursive(weights , values , n-1 , maxWeight);
	int pick = -1e9;
	if(weights[n] <= maxWeight)
		pick = values[n] + Recursive(weights , values , n , maxWeight-weights[n]);

	return max(pick , notPick);
}





int Memoization(vi weights , vi values , int n , int maxWeight , vvi &dp){
	if(n == 0) return (maxWeight / weights[0]) * values[0];

	if(dp[n][maxWeight] != -1) return dp[n][maxWeight];

	int notPick = Memoization(weights , values , n-1 , maxWeight , dp);
	int pick = -1e9;
	if(weights[n] <= maxWeight)
		pick = values[n] + Memoization(weights , values , n , maxWeight-weights[n] , dp);

	return dp[n][maxWeight] = max(pick , notPick);
}




int Tabulation(vi weights , vi values , int n , int maxWeight){
	vvi dp(n , vi(maxWeight+1 , -1));
	fori(i , 0 , maxWeight) dp[0][i] = (i/weights[0])*values[0];

	fori(i , 1 , n-1){
		fori(wt , 0 , maxWeight){
			int notPick = dp[i-1][wt];
			int pick = -1e9;
			if(weights[i] <= wt)
				pick = values[i] + dp[i][wt-weights[i]];

			dp[i][wt] = max(pick , notPick);
		}
	}

	return dp[n-1][maxWeight];

}





int Tabulation_Optimised(vi weights , vi values , int n , int maxWeight){
	vi prev(maxWeight+1 , 0) , current(maxWeight+1 , 0);
	fori(i , 0 , maxWeight) prev[i] = (i/weights[0])*values[0];

	fori(i , 1 , n-1){
		fori(wt , 0 , maxWeight){
			int notPick = prev[wt];
			int pick = -1e9;
			if(weights[i] <= wt)
				pick = values[i] + current[wt-weights[i]];

			current[wt] = max(pick , notPick);
		}
		prev = current;
	}

	return prev[maxWeight];

}




// Using single vector
int Tabulation_Optimised_2(vi weights , vi values , int n , int maxWeight){
	vi current(maxWeight+1 , 0);
	fori(i , 0 , maxWeight) current[i] = (i / weights[0]) * values[0];

	fori(i , 1 , n-1){
		fori(wt , 0 , maxWeight){
			int notPick = current[wt];
			int pick = -1e9;
			if(weights[i] <= wt)
				pick = values[i] + current[wt-weights[i]];
			current[wt] = max(pick , notPick);
		}
	}

	return current[maxWeight];

}





int main(){

	cp_function();

	vi weights = {2,4,6};
	vi values  = {5,11,13};
	int n = weights.size();
	int maxWeight = 10;

	// cout << Recursive(weights , values , n-1 , maxWeight);


	// vvi dp(n , vi(maxWeight+1 , -1));
	// cout << Memoization(weights , values , n-1 , maxWeight , dp);


	// cout << Tabulation(weights , values , n , maxWeight);


	// cout << Tabulation_Optimised(weights , values , n , maxWeight);


	cout << Tabulation_Optimised_2(weights , values , n , maxWeight);


	return 0;
} 