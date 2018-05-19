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

int n,m;
const int mn = 1e4 + 10;
vector<int> g[mn];
int deg[mn];
priority_queue<int> q;
int main(){
    while(cin >> n >> m && n && m) {
        vector<int> ans;
        FOR(i,n) g[i].clear(), deg[i] = 0;
        FOR(i,m) {
            int u,v;
            cin >> u >> v;
            u--,v--;    
            g[u].push_back(v);
            deg[v]++;
        }
        FOR(i,n) if(!deg[i]) q.push(-i);
        while(!q.empty()) {
            int nod = -q.top();
            ans.push_back(nod);
            q.pop();
            FOR(i, g[nod].size()) {
                int nxt = g[nod][i];
                deg[nxt]--;
                if(!deg[nxt]) 
                    q.push(-nxt);
                 
            }
        }

        FOR(i, n) cout << ans[i] + 1 << " ";
        cout << endl;

    }


	return 0;
}
