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
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if(i > 1){
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}