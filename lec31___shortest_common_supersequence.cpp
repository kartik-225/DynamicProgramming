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




int main(){

	cp_function();

	string s1 = "bleed" , s2 = "blue";
	int n = s1.length() , m = s2.length();

	vvi dp(n+1 , vi(m+1 , 0));

	fori(i , 1 , n){
		fori(j , 1 , m){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}

	int lcs = dp[n][m];

	int ans_length = n + m - lcs;
	int index = ans_length-1;

	// cout << ans_length;
	string ans = "";
	fori(i , 0 , ans_length-1) ans += "%";

	int i = n , j = m;

	while(i > 0 and j > 0){
		if(s1[i-1] == s2[j-1]){
			ans[index--] = s1[i-1];
			i-- ; j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				ans[index--] = s1[i-1];
				i--;
			}
			else{
				ans[index--] = s2[j-1];
				j--;
			}
		}
	}

	while(j > 0){
		ans[index--] = s2[j-1];
		j--;
	}
	while(i > 0){
		ans[index--] = s1[i-1];
		i--;	
	}

	cout << ans;

	return 0;
}