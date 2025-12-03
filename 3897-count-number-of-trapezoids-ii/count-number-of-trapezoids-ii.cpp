#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    int c2(int n){
        return 1ll * n * (n-1) / 2;
    }

    ll gcdll(ll a, ll b){
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        return std::gcd(a, b);
    }

    // Reduce fraction (num/den), keep den >= 0, and reduce by gcd.
    pair<ll,ll> normFrac(ll num, ll den){
        if(den == 0) {
            // represents infinity slope, keep canonical as (1,0)
            return {1, 0};
        }
        if(num == 0) {
            return {0, 1};
        }
        ll g = gcdll(num, den);
        num /= g; den /= g;
        if(den < 0){ num = -num; den = -den; }
        return {num, den};
    }

    int countTrapezoids(vector<vector<int>>& points) {
        // mp[slope][intercept] = count of segments on that line
        map<pair<ll,ll>, map<pair<ll,ll>, int>> mp;

        // midpoints[xmid][ymid][slope] = count of segments with that midpoint+ slope
        map<ll, map<ll, map<pair<ll,ll>, int>>> midpoints;

        int n = (int)points.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ll x1 = points[i][0], y1 = points[i][1];
                ll x2 = points[j][0], y2 = points[j][1];

                ll xmid = x1 + x2;   // doubled midpoint
                ll ymid = y1 + y2;   // doubled midpoint

                ll dy = y2 - y1;
                ll dx = x2 - x1;

                pair<ll,ll> slope, intercept;

                if(dx == 0){
                    // vertical line: slope = INF, intercept = x = x1
                    slope = {1, 0};
                    intercept = {x1, 1};
                } else {
                    slope = normFrac(dy, dx); // reduced dy/dx

                    // c = y - m*x
                    // m = p/q, so c = (y*q - p*x)/q
                    ll p = slope.first;
                    ll q = slope.second;

                    ll c_num = y1 * q - p * x1;
                    ll c_den = q;
                    intercept = normFrac(c_num, c_den);
                }

                midpoints[xmid][ymid][slope]++;
                mp[slope][intercept]++;
            }
        }

        // Count parallelograms via equal midpoints, excluding collinear duplicates by slope
        int par = 0;
        for(auto &mx : midpoints){
            for(auto &my : mx.second){
                auto &f = my.second; // slope -> count
                int total = 0;
                for(auto &sc : f){
                    int cnt = sc.second;
                    total += cnt;
                    par -= c2(cnt);
                }
                par += c2(total);
            }
        }

        // Count pairs of parallel segments on distinct lines (trapezoid candidates)
        int ans = 0;
        for(auto &sv : mp){
            auto &byC = sv.second;
            int cfsum = 0;
            int acc = 0;
            for(auto &cv : byC){
                int cf = cv.second;
                cfsum += cf;
                acc += c2(cf);  // remove pairs on same line
            }
            int inr = c2(cfsum) - acc; // pairs of segments with same slope, different intercept
            ans += inr;
        }

        // trapezoids = parallel pairs - parallelograms
        return ans - par;
    }
};
