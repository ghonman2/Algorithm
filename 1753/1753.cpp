#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int>pi;
typedef vector<pi> vp;
int v,e,s;
vector<vp> graph;

void input()
{
    cin>> v >>e >>s;
    graph = vector<vp>(v + 1);
    for (int i = 0 ;i < e; i ++)
    {
        int frm, dst, w;
        cin >> frm >>dst >>w;
        graph[frm].push_back(make_pair(dst,w));
    }
}

void sol()
{
    vector<int> distances(v+1, INT_MAX);
    distances[s] = 0;
    priority_queue<pi> q;
    q.push(make_pair(distances[s], s));
    
    while (!q.empty())
    {
        pi info = q.top(); q.pop();
        int dist = info.first, dest = info.second;

        if (distances[s] < dist) continue;

        for (auto nodeInfo : graph[dest])
        {
			int node = nodeInfo.first, weight = nodeInfo.second;
            int nDist = dist + weight;
            if (nDist < distances[node])
            {
                q.push(make_pair(nDist, node));
                distances[node] = nDist;
            }
        }
    }

    for (int i = 1; i <= v; i ++)
    {
        if (distances[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << distances[i] << endl;
    }
}

int main()
{
    input();
    sol();
    return (0);
}
