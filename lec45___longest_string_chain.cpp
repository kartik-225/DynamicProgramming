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


bool checkPossible(string s1 , string s2){
	if(s1.length() != s2.length() + 1) return false;

	int i = 0 , j = 0;
	while(i < s1.length()){
		if(j < s2.length() and s1[i] == s2[j]){
			i++;j++;
		}
		else
			i++;
	}

	return (i == s1.length() and j == s2.length());

}


bool comp(string &s1 , string &s2){
	return s1.length() < s2.length();
}


int main(){

	cp_function();

	vector<string> arr = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
	int n = arr.size();
	int maxi = 1;

	vi dp(n , 1);

	sort(arr.begin(), arr.end() , comp);

	fori(i , 0 , n-1){
		fori(last , 0 , i-1){
			if(checkPossible(arr[i],arr[last]) and 1+dp[last] > dp[i]){
				dp[i] = 1 + dp[last];
			}
		}
		if(dp[i] > maxi)
			maxi = dp[i];
	}

	cout << maxi;

	return 0;
}