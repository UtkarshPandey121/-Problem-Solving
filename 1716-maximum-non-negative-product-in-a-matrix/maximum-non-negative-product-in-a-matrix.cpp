#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        long dpMax[m][n], dpMin[m][n];

        dpMax[0][0] = dpMin[0][0] = g[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                long mx = LONG_MIN, mn = LONG_MAX;

                if(i>0){
                    mx = max({mx, dpMax[i-1][j]*g[i][j], dpMin[i-1][j]*g[i][j]});
                    mn = min({mn, dpMax[i-1][j]*g[i][j], dpMin[i-1][j]*g[i][j]});
                }
                if(j>0){
                    mx = max({mx, dpMax[i][j-1]*g[i][j], dpMin[i][j-1]*g[i][j]});
                    mn = min({mn, dpMax[i][j-1]*g[i][j], dpMin[i][j-1]*g[i][j]});
                }

                dpMax[i][j] = mx;
                dpMin[i][j] = mn;
            }
        }

        long ans = dpMax[m-1][n-1];
        if(ans < 0) return -1;

        return ans % 1000000007;
    }
};