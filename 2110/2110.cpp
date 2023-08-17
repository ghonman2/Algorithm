#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;


int main(){
	FAST;
	int n,c ;
	cin >> n >> c ;
	vi house(n);
	REP(i,0,n){
		cin >> house[i];
	}
	sort(house.begin(),house.end());
	int left = 0 , right = house[n-1];
	int mid ;
	while(left <= right){
		mid = (left+right)/ 2;
		int cnt = 1 ;
		int pre_idx = 0;
		REP(i,1,n){
			if(house[i] - house[pre_idx] >= mid){
				pre_idx = i;
				cnt += 1;
			}
		}
		if (cnt >= c){
			left = mid + 1;
		}
		else right = mid-1;
	}
	cout << right << "\n";
	return 0;
}
