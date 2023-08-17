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
int n,m;
vl numbers;

void init()
{
	cin >> n >> m ;
	numbers = vl(n,0);
	REP(i,0,n) cin >> numbers[i];
}

void sol()
{
	ll answer = 0 ;
	int left = 0, right = 1;
	ll sum = numbers[left];
	while(right !=  n+1){
		if(sum == m) {
			answer += 1;
			sum += numbers[right ++];
		}
		if(sum < m )sum += numbers[right++];
		else if(sum > m ) sum -=numbers[left++];
	}
	cout <<  answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

