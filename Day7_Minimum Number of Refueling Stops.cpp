class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size()==0) {
            return startFuel >= target ? 0 : -1;
        }
        long long F = startFuel;
        int prevStop = 0;
        priority_queue<int> pq;
        int minStops = 0;
        for(int i=0;i<stations.size();i++) {
            int dist = stations[i][0] - prevStop;
            while(F < dist && !pq.empty()) {
                F = F + pq.top();
                pq.pop();
                minStops++;
            }
            if (F < dist) return -1;
            F = F - dist;
            prevStop = stations[i][0];
            pq.push(stations[i][1]);
        }
        int dist = target - stations[stations.size()-1][0];
        while(F < dist && !pq.empty()) {
            F = F + pq.top();
            pq.pop();
            minStops++;
        }
        if (F < dist) return -1;
        return minStops;
    }
};
