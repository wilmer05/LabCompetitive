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

long long n, l, a, d;
long long person_price;
long long available;
const long long oo = 1e18 + 10;

int main(){
    while(cin >> n >> l >> a >> d){
        long long best_solution = oo;
        FOR(i, a){
            cin >> person_price;
            FOR(j,d){
                cin >> available;
                int current_total = person_price * n; 
                if(available >= n && current_total <= l && (current_total < best_solution))
                    best_solution = current_total;
            }
        }        
        if(best_solution < oo) cout << best_solution << "\n";
        else cout << "impossible" << endl;
    }

	return 0;
}
