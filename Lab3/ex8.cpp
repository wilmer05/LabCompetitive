#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>

#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;
int u,v;
int N, E, T;

vector<int> g[110];
int d1[110],d2[110], r1, r2;
queue<int> q;
void bfs( int root, int *d) {
    d[root] = 0;
    q.push(root);
    while(!q.empty()) {
        int nod = q.front(); q.pop();
        FOR(i, g[nod].size()) {
            int nx = g[nod][i];
            if(d[nx] == -1) {
                d[nx] = 1 + d[nod];
                q.push(g[nod][i]);
            }
        }
    }
}

int main(){
    cin >> T;
    FOR(t, T) {
        cin >> N >> E;
        FOR(i,N) g[i].clear(), d1[i] = d2[i] = -1;

        FOR(i, E) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        } 

        cin >> r1 >> r2;
        bfs(r1, d1); bfs(r2, d2);

        int min_dist = -1;
        FOR(i,N) min_dist = max(min_dist, d1[i] + d2[i]);
        cout << "Case " << t + 1 << ": " << min_dist << endl;
    }

	return 0;
}
