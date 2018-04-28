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

char type;
int n,m,t;

int main(){

    cin >> t;
    FOR(i,t) {
        cin >> type >> m >> n;
        if( type == 'Q' ) {
            if( m > n ) swap(m, n); 
            if( n <= 2 ) cout << "1" << endl;
            else if( m == 3 && n == 3) cout << "2" << endl;
            else cout << min(n,m) << endl;
        } else if (type == 'K') {
            cout << ((n + 1) / 2) * ((m + 1) / 2) << endl;
        } else if (type == 'r') {
            cout << min(m, n) << endl; 
        } else {
            int white, blacks;
            white = blacks = 0;
            white = ((n + 1) / 2 ) * ((m + 1) / 2);
            white += (n / 2) * (m / 2);
            blacks = white + n / 2 - ( m & 1 ? (n + 1 ) / 2 : (n ) / 2 );
            cout << max(white, blacks) << endl;
        
        }

    }


	return 0;
}
