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


int Recursive(vvi grid , int row , int col , int i , int j1 , int j2){
	if(j1 < 0 or j1 == col or j2 < 0 or j2 == col) return -1e8;
	if(i == row-1){
		if(j1 == j2) return grid[i][j1];
		else return grid[i][j1] + grid[i][j2];
	}

	int maxi = -1e9 ; 
	fori(dj1 , -1 , 1){
		fori(dj2 , -1 , 1){
			int point = 0;
			if(j1 == j2) point = grid[i][j1];
			else point = grid[i][j1] + grid[i][j2];
			point += Recursive(grid , row , col , i+1 , j1+dj1 , j2+dj2);
			maxi = max(maxi , point);
		}
	}
	return maxi;
}




int Memoization(vvi grid , int row , int col , int i , int j1 , int j2 , vector<vector<vector<int>>> &dp){
	if(j1 < 0 or j1 == col or j2 < 0 or j2 == col) return -1e8;
	if(i == row-1){
		if(j1 == j2) return grid[i][j1];
		else return grid[i][j1] + grid[i][j2];
	}

	if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

	int maxi = -1e9 ; 
	fori(dj1 , -1 , 1){
		fori(dj2 , -1 , 1){
			int point = 0;
			if(j1 == j2) point = grid[i][j1];
			else point = grid[i][j1] + grid[i][j2];
			point += Memoization(grid , row , col , i+1 , j1+dj1 , j2+dj2 , dp);
			maxi = max(maxi , point);
		}
	}

	dp[i][j1][j2] = maxi;

	return dp[i][j1][j2];

}




int Tabulation(vvi grid , int row , int col){
	vector<vector<vector<int>>> dp(row , vector<vector<int> > (col , vector <int> (col,0)));
	// int dp[row][col][col] = {0};
	fori(j1 , 0 , col-1){
		fori(j2 , 0 , col-1){
			if(j1 == j2) dp[row-1][j1][j2] = grid[row-1][j1];
			else 		 dp[row-1][j1][j2] = grid[row-1][j1] + grid[row-1][j2];
		}
	}



	ford(i , row-2 , 0){
		fori(j1 , 0 , col-1){
			fori(j2 , 0 , col-1){
				int maxi = -1e9 ; 
				fori(dj1 , -1 , 1){
					fori(dj2 , -1 , 1){
						int point = 0;
						if(j1 == j2) point = grid[i][j1];
						else point = grid[i][j1] + grid[i][j2];
						if(j1+dj1 >= 0 and j1+dj1 < col and j2+dj2 >= 0 and j2+dj2 < col) 
							point += dp[i+1][j1+dj1][j2+dj2]; 
						else point += -1e8;
						maxi = max(maxi , point);
					}
				}
				dp[i][j1][j2] = maxi;
			}
		}
	}

	return dp[0][0][col-1];

}




int main(){

	cp_function();

	vvi grid = {{2 , 3 , 1 , 2},
				{3 , 4 , 2 , 2},
				{5 , 6 , 3 , 5}};

	int n = grid.size();
	int m = grid[0].size();

	// cout << Recursive(grid , n , m , 0 , 0 , m-1);


	// vector<vector<vector<int> > > dp(n+1 , vector<vector<int> > (m+1 , vector <int> (m+1,-1)));
	// cout << Memoization(grid , n , m , 0 , 0 , m-1 , dp);


	cout << Tabulation(grid , n , m);


	return 0;
}