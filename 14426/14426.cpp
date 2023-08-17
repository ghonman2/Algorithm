#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,m;
vector<string> preWords;
vector<string> words;

void init()
{
	cin >> n >> m;
	preWords = vector<string>(n);
	words = vector<string>(m);

	for (int i = 0 ; i < n ; i ++)
		cin >> preWords[i];
	for (int k = 0 ; k < m ; k ++)
		cin >> words[k];
}
void sol()
{
	int cnt = 0;
	for (auto w : words)
	{
		for (auto pw :preWords)
		{
			if (w == pw.substr(0,w.length()))
			{
				cnt ++;
				break ;
			}
		}
	}
	cout << cnt << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	sol();
	return (0);
}
