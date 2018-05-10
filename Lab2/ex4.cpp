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

char act;
int n, ev, T;
vector<int> par;

int parent(int u) {
    if (u == par[u]) return u;
    return par[u] = parent(par[u]);
}


bool ask(int u, int v) {
   int p1 = parent(u);
   int p2 = parent(v);
   return p1 == p2;
}


void join(int u, int v) {
    int p1 = parent(u);
    int p2 = parent(v);
    par[p1] = p2;
}

int main(){
    cin >> T;
    FOR(t,T) {
        cin >> n >> ev;
        int succ, fail;
        succ = fail = 0;
        
        par = vector<int>(n);
        FOR(i,n) par[i] = i;

        int n1,n2;
        FOR(i, ev) {
            cin >> act >> n1 >> n2; 
            n1--, n2--;
            if ( act == 'q' ) {
                bool valid = ask(n1, n2);
                succ += valid;
                fail += !valid;
            } 
            else join(n1, n2);
        }

        cout << succ << " " << fail << endl;

    }

	return 0;
}
