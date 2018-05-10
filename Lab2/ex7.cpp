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

int es[40], bs[40], V, T, k;
const int oo = 1e9 + 10;
const int mn = 1e5 + 10;
int memo[mn];

int main(){

    cin >> T;
    FOR(t,T) {
        cin >> k >> V;
        V*=V;
        memo[V] = oo;
        FOR(i,k) cin >> bs[i]  >> es[i];

        memo[0] = 0;
        for (int i = 1;  i < V + 1; i++) {
            memo[i] = oo;   
            FOR(j,k) {
                 int tmp = i - bs[j] * bs[j] - es[j] * es[j];
                 if(tmp >=0)
                     memo[i] = min(memo[i], 1 + memo[tmp]);
            }
        }

        if(memo[V] != oo) cout << memo[V] << endl;
        else cout << "impossible\n";
        
    }
    

	return 0;
}
