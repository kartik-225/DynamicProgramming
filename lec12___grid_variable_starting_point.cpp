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


int Recursive(vvi grid , int row , int col){
	if(col < 0 or col >= grid[0].size()) return -1e8;
	if(row == 0) return grid[row][col];

	// Moves - Up , Up left , Up right
	int up = 	  grid[row][col] + Recursive(grid , row-1 , col);
	int upLeft =  grid[row][col] + Recursive(grid , row-1 , col-1);
	int upRight = grid[row][col] + Recursive(grid , row-1 , col+1);

	return max(up , max(upLeft , upRight));
}



int Memoization(vvi grid , vvi &dp , int row , int col){
	if(col < 0 or col >= grid[0].size()) return -1e8;
	if(row == 0) return grid[row][col];
	if(dp[row][col] != -1) return dp[row][col];

	// Moves - Up , Up left , Up right
	int up = 	  grid[row][col] + Memoization(grid , dp , row-1 , col);
	int upLeft =  grid[row][col] + Memoization(grid , dp , row-1 , col-1);
	int upRight = grid[row][col] + Memoization(grid , dp , row-1 , col+1);

	dp[row][col] = max(up , max(upLeft , upRight));

	return dp[row][col];
}




int Tabulation(vvi grid , int row , int col){
	vvi dp(row+1 , vi(col+1 , 0));
	fori(i , 0 , col) dp[0][i] = grid[0][i];

	fori(i , 1 , row){
		fori(j , 0 , col){
			int upLeft = -1e8 , upRight = -1e8;
			int up = grid[i][j] + dp[i-1][j];
			if(j+1 <= col) upRight = grid[i][j] + dp[i-1][j+1];
			if(j-1 >= 0) upLeft = grid[i][j] + dp[i-1][j-1];
			dp[i][j] = max(up , max(upLeft , upRight));
		}
	}

	int ans = min_int;
	fori(i , 0 , col) ans = max(ans , dp[row][i]);
	return ans;

}



int Tabulation_Optimised(vvi grid , int row , int col){
	vvi dp(row+1 , vi(col+1 , 0));
	vi prev(col+1 , 0) , current(col+1 , 0);
	fori(i , 0 , col) prev[i] = grid[0][i];

	fori(i , 1 , row){
		fori(j , 0 , col){
			int upLeft = -1e8 , upRight = -1e8;
			int up = grid[i][j] + prev[j];
			if(j+1 <= col) upRight = grid[i][j] + prev[j+1];
			if(j-1 >= 0) upLeft = grid[i][j] + prev[j-1];
			current[j] = max(up , max(upLeft , upRight));
		}
		prev = current;
	}

	int ans = min_int;
	fori(i , 0 , col) ans = max(ans , prev[i]);
	return ans;

}



int main(){

	cp_function();

	vvi grid = {{ 1 , 2 , 10 , 4},
				{100, 3 , 2  , 5},
				{ 1 , 1 , 20000 , 2},
				{ 1 , 2 , 40  , 3}};

	int n = grid.size();
	int m = grid[0].size();
	int ans = min_int;

	// Recursive
	// fori(i , 0 , m-1) ans = max(ans , Recursive(grid , n-1 , i));
	// cout << ans;
	
	// Memoization
	// vvi dp(n,vi(m , -1));
	// fori(i , 0 , m-1) ans = max(ans , Memoization(grid , dp , n-1 , i));
	// cout << ans;


	// Tabulation
	// cout << Tabulation(grid , n-1 , m-1);


	cout << Tabulation_Optimised(grid , n-1 , m-1);



	return 0;
}	