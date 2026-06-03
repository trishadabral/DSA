class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        int n=landStartTime.size();
        int m=waterStartTime.size();
        vector<long long> landFinish,waterFinish;
        for(int i=0;i<n;i++)
            landFinish.push_back((long long)landStartTime[i]+landDuration[i]);

        for(int j=0;j<m;j++)
            waterFinish.push_back((long long)waterStartTime[j]+waterDuration[j]);
        sort(landFinish.begin(),landFinish.end());
        sort(waterFinish.begin(),waterFinish.end());
        long long minLandFinish=landFinish[0];
        long long minWaterFinish=waterFinish[0];
        long long ans=LLONG_MAX;
        //since there are onlt 2 possible cases we will be trying that
        // Land -> Water
        for(int j=0;j<m;j++) {
            long long ws=waterStartTime[j];
            long long wd=waterDuration[j];
            long long best;
            if(minLandFinish<=ws) {
                best=ws;
            } else {
                auto it=lower_bound(landFinish.begin(),
                                    landFinish.end(),
                                    ws);
                best=*it;
            }
            ans=min(ans,best+wd);
        }
        // Water -> Land
        for(int i=0;i<n;i++) {
            long long ls=landStartTime[i];
            long long ld=landDuration[i];
            long long best;
            if(minWaterFinish<=ls) {
                best=ls;
            } else {
                auto it=lower_bound(waterFinish.begin(),
                                    waterFinish.end(),
                                    ls);
                best=*it;
            }
            ans=min(ans,best+ld);
        }
        return ans;
    }
};