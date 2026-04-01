#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int cost = f[2];
            adj[u].push_back({v, cost});
        }

        queue<tuple<int,int,int>> q; 
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push({src, 0, 0});

        while (!q.empty()) {
            auto [u, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                int wt = it.second;

                if (cost + wt < dist[v]) {
                    dist[v] = cost + wt;
                    q.push({v, dist[v], stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};