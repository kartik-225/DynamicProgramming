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



int Recursive(vi arr , int n , int last , int i = 0){
	if(i == n) return 0;

	// Take
	int len = 0;
	if(last == -1 or arr[last] < arr[i])
		len = max(len , 1 + Recursive(arr , n , i , i+1));

	// Not Take
	len = max(len , Recursive(arr , n , last , i+1));

	return len;
}



int Memoization(vi arr , int n , int last , vvi &dp , int i = 0){
	if(i == n) return 0;

	if(dp[i][last+1] != -1) return dp[i][last+1];

	// Take
	int len = 0;
	if(last == -1 or arr[last] < arr[i])
		len = max(len , 1 + Memoization(arr , n , i , dp , i+1));

	// Not Take
	len = max(len , Memoization(arr , n , last , dp , i+1));

	dp[i][last+1] = len;

	return dp[i][last+1];
}




int Tabulation(vi arr , int n){
	vvi dp(n+1 , vi(n+1 , 0));
	// fori(a , 0 , n) dp[n][a] = 0;

	ford(i , n-1 , 0){
		ford(last , i-1 , -1){
			int len = 0;
			if(last == -1 or arr[last] < arr[i])
				len = max(len , 1 + dp[i+1][i+1]);
			len = max(len , dp[i+1][last+1]);
			
			dp[i][last+1] = len;
		}
	}

	return dp[0][-1+1];

}






int main(){

	cp_function();

	vi arr = {10,9,2,5,3,7,101,18};
	int n = arr.size();

	// cout << Recursive(arr , n , -1);


	// vvi dp(n , vi(n+1 , -1));
	// cout << Memoization(arr , n , -1 , dp);


	cout << Tabulation(arr , n);

	return 0;
}