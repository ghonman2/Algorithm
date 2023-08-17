#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;





void solution()
{
	int x1,y1,x2,y2 ;
	int n = 0 ;
	int answer = 0;
	cin >> x1 >> y1>> x2 >> y2;
	cin >> n;
	for(int i = 0; i < n ; i++){
		int pc,py,pr;
		cin >> pc >> py >> pr ;
		int frm = (pc-x1)*(pc-x1) + (py-y1)*(py-y1);
		int dst = (pc-x2)*(pc-x2) + (py-y2)*(py-y2);
		int spr = pr*pr;
		if (frm < spr != dst < spr)
			answer += 1;
	}
	cout <<  answer << endl;
}


int main()
{
	int T = 0 ; 
	int  t =0;
	cin >> T;
	
	while(t++ < T){
		solution();
	}
	return 0;
}
