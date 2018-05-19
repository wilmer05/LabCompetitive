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

double d(int x1, int y1, int x2, int y2) {
    return hypot(x1-x2, y1-y2);
}

double d(pair<double, double> p1, pair<double, double> p2) {
    return d(p1.first, p1.second, p2.first, p2.second);
}

vector<pair<double, double> > pts;
vector<int> par;
priority_queue<pair<double, pair<int, int> > > q;

int parent(int nod) {

    if(nod == par[nod]) return nod;

    return par[nod] = parent(par[nod]);

}

bool same_comp(int u, int v){
    return parent(u) == parent(v);
}

void join(int u, int v) {
    int p1 = parent(u);
    int p2 = parent(v);
    par[p1] = p2;
}

int main(){

    cin >> n >> m;
    double ans = 1e18;
    par.resize(n);
    int u,v;
    FOR(i,n) {
        par[i] = i;
        cin >> u >> v;
        pts.push_back(make_pair(u,v));
    }
    FOR(i, m) {
      cin >> u >> v; u--,v--;
      join(u, v);
      //ans = min(ans, d(pts[u], pts[v]));
    }
    FOR(i,n) 
        for(int j = i + 1; j < n; j++) 
            q.push(make_pair(-d(pts[i], pts[j]), make_pair(i, j))); 
        
    while(!q.empty()) {
        pair<double, pair<int, int> > p = q.top(); q.pop();
        double dd = -p.first;
        u = p.second.first;
        v = p.second.second;
        if(!same_comp(u,v)) {
           ans = min(dd, ans);
           break;
        }
    }

    printf("%.3lf\n", ans); 

	return 0;
}
