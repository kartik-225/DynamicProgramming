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


int Recursive(int row , int col){
	if(row == 0 and col == 0) return 1;
	if(row < 0 or col < 0) return 0;

	// Right
	int left = Recursive(row , col-1);

	// Down
	int up = Recursive(row-1 , col);

	return left + up;

}



int Memoization(int row , int col , vvi &dp){
	if(row == 0 and col == 0) return 1;
	if(row < 0 or col < 0) return 0;
	if(dp[row][col] != -1) return dp[row][col];

	// Right
	int left = Memoization(row , col-1 , dp);

	// Down
	int up = Memoization(row-1 , col , dp);

	dp[row][col] = left + up;

	return dp[row][col];

}



int Tabulation(int row , int col){
	vvi dp(row+1 , vi (col+1 , 0));
	dp[0][0] = 1;

	int left = 0 , up = 0;
	fori(i , 0 , row){
		fori(j , 0 , col){
			left = 0 , up = 0;
			if(i > 0 or j > 0){
				if(j > 0)
					left = dp[i][j-1];
				if(i > 0)
					up = dp[i-1][j];
				dp[i][j] = left+up;
			}
		}
	}

	return dp[row][col];

}


int Tabulation_Optimised(int row , int col){
	vi prev(col+1 , 0) , current(col+1 , 0);

	int left = 0 , up = 0;
	fori(i , 0 , row){
		fori(j , 0 , col){
			if(i == 0 and j == 0) current[j] = 1;
			else{
				left = 0 , up = 0;
				if(j > 0)
					left = current[j-1];
				if(i > 0)
					up = prev[j];
				current[j] = left+up;
			}
		}
		prev = current;
	}

	return prev[col];
}




int main(){

	cp_function();

	int n = 3;
	int m = 10;
	// cout << Recursive(n-1,m-1);

	// vvi dp(n , vi (m , -1));
	// cout << Memoization(n-1 , m-1 , dp);

	cout << Tabulation(n-1,m-1);

	// cout << Tabulation_Optimised(n-1,m-1);
	

	return 0;
}