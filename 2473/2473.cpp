#include <bits/stdc++.h>

using namespace std;


#define REP(i,a,b) for(int i = a ; i < b ; i ++)

typedef long long ll ;
typedef vector<ll> vi;


int main(){
	int n ;
	cin >> n;
	ll water[n];
	REP(i,0,n){
		cin >> water[i];
	}
	sort(water,water+n);
	REP(i,0,n){
		cout <<  water[i] << " ";
	}
	cout << "\n";
	ll l = water[0], r = water[1], m = water[2];
	ll left = 0 ,right = n-1;
	int mid = (left+right)/2;
	
	ll standard = abs(water[0] + water[1] + water[2]);
	
	while(left <= right){
		mid = lower_bound(water+left,water+right,0-(water[left]+water[right])) - water + left;
		cout << water[left] << " " << water[mid] << " " << water[right] << "\n";
		ll sums = abs(water[left]  + water[right] + water[mid]);
		if (sums > standard){
			int tmpLeft = left;
			int tmpRight = right;
			ll stl = water[left];
			ll str = water[right];
			while(left < right && water[tmpLeft] == stl) tmpLeft ++;
			while(left < right && water[tmpRight] == str) tmpRight++;
			if(abs(water[tmpLeft]-stl) > abs(water[tmpRight]-str)){
				right = tmpRight;
			}else {
				left = tmpLeft;
			}
		}
		else {
			l = water[left], m = water[mid], r = water[right];
			left ++;
		}
	}
	cout << l << " " << m << " " << r << "\n";


	return 0; 
}
