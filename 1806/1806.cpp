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
typedef vector<ll> vl;

vl numbers;
int n,s;


void init()
{
	cin >> n >> s ;
	numbers = vl(n,0);
	REP(i,0,n)cin >>numbers[i];
}


void sol()
{
	deque<ll>q;
	int left = 0 ,right = 0;
	ll sum = 0 ;
	int len = 0;
	int answer = INT_MAX;
	while(right < n){
		while(sum < s && right <n){sum += numbers[right++]; len ++;}
		while(sum>=s && left <= right){answer = min(answer,len); sum -= numbers[left++];len --;}
	}
	if(answer == INT_MAX) cout << 0 << "\n";
	else cout << answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

