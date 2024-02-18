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

int Recursive(vi energy , int n , int k){
	if(n == 0) return 0;
	int jump = max_int , minJump = max_int;

	fori(index , 1 , k){
		if(n - index >= 0)
			jump = abs(energy[n] - energy[n - index]) + Recursive(energy , n-index , k);
		minJump = min(jump , minJump);
	}

	return minJump;
}



int Memoization(vi energy , int n , int k , vi &dp){
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];
	int jump = max_int , minJump = max_int;

	fori(index , 1 , k){
		if(n - index >= 0)
			jump = abs(energy[n] - energy[n - index]) + Memoization(energy , n-index , k , dp);
		minJump = min(jump , minJump);
		dp[n] = minJump;
	}

	return dp[n];
}



int Tabulation(vi energy , int n , int k){
	vi dp(n+1 , 0);
	dp[0] = 0;

	fori(i , 1 , n){
		int jump = max_int , minJump = max_int;
		fori(index , 1 , k){
			if(i - index >= 0)
				jump = abs(energy[i] - energy[i - index]) + dp[i - index];
			minJump = min(jump , minJump);
			dp[i] = minJump;
		}
	}
	

	return dp[n];
}



int main(){

	cp_function();

	vi energy = {10,20,30,10,40,30,60,50};
	int n = energy.size();
	int k = 2;

	// cout << Recursive(energy , n-1 , k);

	// vi dp(n+1 , -1);
	// cout << Memoization(energy , n-1 , k , dp);

	// cout << Tabulation(energy , n-1 , k);


	return 0;
} 