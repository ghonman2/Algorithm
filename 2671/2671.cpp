#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

int n,m;
vector<ll>nums;

int cmp(int a, int b){
	return a < b;
}
void init()
{
	cin >> n >> m;
	nums = vector<ll>(n,0);
	REP(i,0,n) cin >> nums[i];
}

void sol()
{
	int answer = 0 ;
	int left = 0, right = 0;
	ll sum = nums[left];
	while(right <= n){
		if(sum == m){
			answer ++;
			sum += nums[right++];
		}
		if (sum > m) sum -= nums[left++];
		else if(sum < m) sum += nums[right++];
	}

	cout << answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

