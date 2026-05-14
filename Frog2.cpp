#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    vector<long long> dp(n,LLONG_MAX);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        for(int j=1; j<=k && i-j>=0; j++){
            if(dp[i-j] != LLONG_MAX)
                dp[i] = min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout<<dp[n-1]<<endl;
}