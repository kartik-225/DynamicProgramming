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

int Recursive(vi energy , int n){
	if(n == 0) return 0;
	int jump1 = max_int , jump2 = max_int;

	if(n-1 >= 0)
		jump1= Recursive(energy , n-1) + abs(energy[n] - energy[n-1]);
	if(n-2 >= 0)
		jump2 = Recursive(energy , n-2) + abs(energy[n] - energy[n-2]);

	return min(jump1 , jump2);
}



int Memoization(vi energy , int n , vi &dp){
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];
	int jump1 = max_int , jump2 = max_int;

	if(n-1 >= 0)
		jump1= Memoization(energy , n-1 , dp) + abs(energy[n] - energy[n-1]);
	if(n-2 >= 0)
		jump2 = Memoization(energy , n-2 , dp) + abs(energy[n] - energy[n-2]);

	dp[n] =  min(jump1 , jump2);

	return dp[n];
}




int Tabulation(vi energy , int n){
	vi dp(n+1 , -1);

	dp[0] = 0;

		int jump1 = max_int , jump2 = max_int;
	fori(i , 1 , n){
		if(i-1 >= 0)
			jump1 = dp[i-1] + abs(energy[i-1] - energy[i]);
		if(i-2 >= 0)
			jump2 = dp[i-2] + abs(energy[i-2] - energy[i]);

		dp[i] = min(jump1 , jump2);

	}

	return dp[n];

}



int Tabulation_Optimised(vi energy , int n){
	int prev1 = 0 , prev2 = 0 , current;

	fori(i , 1 , n){
		int jump1 = max_int , jump2 = max_int;
		if(i-1 >= 0)
			jump1 = prev1 + abs(energy[i-1] - energy[i]);
		if(i-2 >= 0)
			jump2 = prev2 + abs(energy[i-2] - energy[i]);

		current = min(jump1 , jump2);

		prev2 = prev1;
		prev1 = current;

	}

	return prev1;

}





int main(){

	cp_function();

	vi energy = {10,20,30,10};
	int n = energy.size();

	// cout << Recursive(energy , n-1);

	// vi dp(n+1 , -1);
	// cout << Memoization(energy , n-1 , dp);

	cout << Tabulation(energy , n-1);

	// cout << Tabulation_Optimised(energy , n-1);

	return 0;
} 