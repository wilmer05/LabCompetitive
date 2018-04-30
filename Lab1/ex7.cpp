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

int U,V,W, T;
const int mn = 115;


int main(){

    cin >> T;
    FOR(t,T) {
        cin >> U >> V >> W;
        int x,y,z;
        bool found = false;
        for(int i = -mn; i < mn && !found; i++) {
            for(int j = i + 1; j < mn && i* i+ j * j <= W && !found; j++){
                for(int k = j + 1; k < mn && i * i + j * j + k * k <= W && !found; k++){
                      if(i * i +  j * j + k * k == W && i * j * k == V && i + j + k == U ) 
                            x = i , y = j, z = k, found = true;
                }
            }
        }
        if(!found) cout << "empty set" << endl;
        else cout << x <<" " << y << " " << z << endl;

    }

	return 0;
}
