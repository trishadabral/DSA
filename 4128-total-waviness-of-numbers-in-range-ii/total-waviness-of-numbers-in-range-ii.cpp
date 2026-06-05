#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    map<tuple<int,bool,bool,int,int,int>,Node> dp;

    Node dfs(int pos,
             bool tight,
             bool started,
             int len,
             int last1,
             int last2) {

        if(pos == s.size()) {
            return {1,0};
        }

        auto key = make_tuple(pos,tight,started,len,last1,last2);

        if(!tight && dp.count(key))
            return dp[key];

        int limit = tight ? s[pos]-'0' : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for(int d=0; d<=limit; d++) {

            bool ntight = tight && (d==limit);

            if(!started && d==0) {

                Node nxt = dfs(pos+1,
                               ntight,
                               false,
                               0,
                               -1,
                               -1);

                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            }
            else {

                if(len==0) {

                    Node nxt = dfs(pos+1,
                                   ntight,
                                   true,
                                   1,
                                   d,
                                   -1);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav;
                }
                else if(len==1) {

                    Node nxt = dfs(pos+1,
                                   ntight,
                                   true,
                                   2,
                                   d,
                                   last1);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav;
                }
                else {

                    long long add = 0;

                    if((last1 > last2 && last1 > d) ||
                       (last1 < last2 && last1 < d))
                        add = 1;

                    Node nxt = dfs(pos+1,
                                   ntight,
                                   true,
                                   len+1,
                                   d,
                                   last1);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav + add*nxt.cnt;
                }
            }
        }
        Node ans = {totalCnt,totalWav};
        if(!tight)
            dp[key] = ans;
        return ans;
    }
    long long solve(long long x) {
        if(x < 0)
            return 0;
        s = to_string(x);
        dp.clear();
        return dfs(0,true,false,0,-1,-1).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1-1);
    }
};