#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<ll> vi;


int main(){
	FAST;
	ll n = 0 ;
	cin >> n ;
	vi number(n);
	vi sumNumber(n*n);
	ll answer = -1;
	REP(i,0,n){
		cin >> number[i];
	}
	
	sort(number.begin(),number.end());
	REP(i,0,n){
		REP(j,0,n){
			sumNumber[i*n+j] = number[i] + number[j];
		}
	}

	sort(sumNumber.begin(),sumNumber.end());

	REP(i,0,n){
		REP(j,0,n){
			if(binary_search(sumNumber.begin(),sumNumber.end(),number[i]-number[j])){
				answer = max(answer,number[i]);
			}
		}
	}
	
	cout << answer  << "\n";
	return 0;
}
