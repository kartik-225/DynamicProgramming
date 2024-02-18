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

int Recursive(int arr[][3] , int day , int lastTask){
	if(day == 0){
		int maxPoint = min_int;
		fori(i , 0 , 2){
			if(i != lastTask)
				maxPoint = max(maxPoint , arr[0][i]);
		}
		return maxPoint;
	}

	int maxPoint = min_int , ans = 0;
	fori(task , 0 , 2){
		if(task != lastTask){
			ans = arr[day][task] + Recursive(arr , day-1 , task);
			maxPoint = max(maxPoint , ans);
		}
	}

	return maxPoint;
}



int Memoization(int arr[][3] , int day , int lastTask , vvi &dp){
	if(day == 0){
		int maxPoint = min_int;
		fori(i , 0 , 2){
			if(i != lastTask)
				maxPoint = max(maxPoint , arr[0][i]);
		}
		return maxPoint;
	}

	if(dp[day][lastTask] != -1) return dp[day][lastTask];

	int maxPoint = min_int , ans = 0;
	fori(task , 0 , 2){
		if(task != lastTask){
			ans = arr[day][task] + Memoization(arr , day-1 , task , dp);
			maxPoint = max(maxPoint , ans);
		}
	}

	dp[day][lastTask] = maxPoint;

	return dp[day][lastTask];
}



int Tabulation(int arr[][3] , int n){
	vvi dp(n+1 , vi(3 , -1));

	// Base Cases
	dp[0][0] = max(arr[0][1] , arr[0][2]);
	dp[0][1] = max(arr[0][0] , arr[0][2]);
	dp[0][2] = max(arr[0][0] , arr[0][1]);
	// Base Case if any activity can be chosen
	dp[0][3] = max(arr[0][0] , max(arr[0][1] , arr[0][2]));

	int ans = min_int , point = min_int;

	fori(day , 1 , n){
		fori(lastTask , 0 , 3){
			fori(task , 0 , 2){
				if(task != lastTask){
					point = arr[day][task] + dp[day-1][task];
					dp[day][lastTask] = max(point , dp[day][lastTask]);
				}
			}
		}
	}

	return dp[n][3];

}



int Tabulation_Optimised(int arr[][3] , int n){
	// vvi dp(n+1 , vi(3 , -1));
	vi prev(4,0) , current(4,0);

	// Base Cases
	prev[0] = max(arr[0][1] , arr[0][2]);
	prev[1] = max(arr[0][0] , arr[0][2]);
	prev[2] = max(arr[0][0] , arr[0][1]);
	// Base Case if any activity can be chosen
	prev[3] = max(arr[0][0] , max(arr[0][1] , arr[0][2]));

	int ans = min_int , point = min_int;

	fori(day , 1 , n){
		fori(lastTask , 0 , 3){
			fori(task , 0 , 2){
				if(task != lastTask){
					point = arr[day][task] + prev[task];
					current[lastTask] = max(point , current[lastTask]);
				}
			}
		}
		prev = current;
	}

	return prev[3];

}


int main(){

	cp_function();

	int activity[][3] = {{10 , 40 , 20},
					  	 {50 , 60 , 30},
					  	 {70 , 20 , 40},
					  	 {40 , 20 , 10},
					  	 {50 , 20 , 10}};

	int n = sizeof(activity)/sizeof(activity[0]);

	int lastActivity = 3;
	
	// cout(Recursive(activity , n-1 , lastActivity));	
	// vvi dp(n , vi(5,-1));
	// cout << Memoization(activity , n-1 , lastActivity , dp);

	cout << Tabulation_Optimised(activity,n-1);
	return 0;
} 