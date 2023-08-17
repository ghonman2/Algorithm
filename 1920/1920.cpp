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
vector<int>nums,checks;
int cmp(int a, int b){ return a< b;}
void init()
{
	cin >> n;
	nums = vi(n,0);
	REP(i,0,n) cin >> nums[i];
	cin >> m;
	checks = vi(m,0);
	REP(i,0,m) cin >> checks[i];
	sort(nums.begin(),nums.end(),cmp);
}


void sol()
{
	REP(i,0,n) cout << nums[i] << " ";
	cout << "\n";
	for(int check : checks){
		int x = -1 ;
		for(int h = n/2 ; h > 0; h /= 2){
			while(nums[x+h] < check && x+h < n-1) x = x + h;
		}
		if(nums[x+1] == check) {cout << "1\n";}
		else cout << "0\n";
	}
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}

