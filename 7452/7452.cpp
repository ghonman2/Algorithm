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
	int n = 0 ; 
	cin >> n ;
	vi A,B,C,D;
	REP(i,0,n){
		int a,b,c,d;
		cin  >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	vi AB(n*n);
	vi CD(n*n);
	REP(i,0,n){
		REP(j,0,n){
			AB[n*i+j] = A[i] + B[j];
			CD[n*i+j] = C[i] + D[j];
		}
	}
	sort(AB.begin(),AB.end());
	sort(CD.begin(),CD.end());
	int answer = 0 ,l = 0 ,r = n*n-1;
	while(l < n*n && r >=0){
		int sum = AB[l] + CD[r];
		if (sum == 0){
			int lcnt = 0 ,rcnt = 0;
			int ab = AB[l], cd = CD[r];
			while(l < n*n && ab == AB[l]) l++,lcnt++;
			while(r >= 0 && cd == CD[r]) r--,rcnt ++;
			answer += lcnt*rcnt;
		}
		if (sum > 0) r --;
		else l++;
	}

	cout << answer << "\n" ;
	return 0;
}
