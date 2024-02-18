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


int Recursive(vi price , int length , int n){
	if(n == 0) return (int)(length * price[0]);

	int notPick = Recursive(price , length , n-1);
	int pick = -1e9;
	if(n+1 <= length)
		pick = price[n] + Recursive(price , length-(n+1) , n);

	return max(pick , notPick);
}




int Memoization(vi price , int length , int n , vvi &dp){
	if(n == 0) return (int)(length * price[0]);

	if(dp[n][length] != -1) return dp[n][length];

	int notPick = Memoization(price , length , n-1 , dp);
	int pick = -1e9;
	if(n+1 <= length)
		pick = price[n] + Memoization(price , length-(n+1) , n , dp);

	return dp[n][length] = max(pick , notPick);
}



int Tabulation(vi price , int length , int n){
	vvi dp(n , vi(length+1 , 0));

	fori(i , 0 , length) dp[0][i] = (int)(i * price[0]);

	fori(i , 1 , n-1){
		fori(l , 0 , length){
			int notPick = dp[i-1][l];
			int pick = 0;
			if(i+1 <= l)
				pick = price[i] + dp[i][l-(i+1)];
			dp[i][l] = max(pick , notPick);
		}
	}

	return dp[n-1][length];
}





int Tabulation_Optimised(vi price , int length , int n){
	vi prev(length+1 , 0) , current(length+1 , 0);

	fori(i , 0 , length) prev[i] = (int)(i * price[0]);

	fori(i , 1 , n-1){
		fori(l , 0 , length){
			int notPick = prev[l];
			int pick = 0;
			if(i+1 <= l)
				pick = price[i] + current[l-(i+1)];
			current[l] = max(pick , notPick);
		}
		prev = current;
	}

	return prev[length];
}




int Tabulation_Optimised_2(vi price , int length , int n){
	vi current(length+1 , 0);

	fori(i , 0 , length) current[i] = (int)(i * price[0]);

	fori(i , 1 , n-1){
		fori(l , 0 , length){
			int notPick = current[l];
			int pick = 0;
			if(i+1 <= l)
				pick = price[i] + current[l-(i+1)];
			current[l] = max(pick , notPick);
		}
	}

	return current[length];
}






int main(){

	cp_function();

	vi price = {2,5,7,8,10};
	int rodLength = 5;
	int n = price.size();

	// cout << Recursive(price , rodLength , n-1);


	// vvi dp(n , vi(rodLength+1 , -1));
	// cout << Memoization(price , rodLength , n-1 , dp);


	// cout << Tabulation(price , rodLength , n);


	// cout << Tabulation_Optimised(price , rodLength , n);


	cout << Tabulation_Optimised_2(price , rodLength , n);

	return 0;
}