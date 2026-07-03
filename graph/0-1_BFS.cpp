#include <bits/stdc++.h>
using namespace std;

vector<int> zeroOneBFS(int n, vector<vector<pair<int, int>>> &adj, int src) {
    deque<pair<int, int>> dq;   // {cost, node}

    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    dq.push_front({0, src});

    while (!dq.empty()) {
        auto [cost, node] = dq.front();
        dq.pop_front();

        // Skip outdated entries
        if (cost > dist[node])
            continue;

        for (auto [nbr, wt] : adj[node]) {

            if (cost + wt < dist[nbr]) {

                dist[nbr] = cost + wt;

                if (wt == 0)
                    dq.push_front({dist[nbr], nbr});
                else
                    dq.push_back({dist[nbr], nbr});
            }
        }
    }

    return dist;
}
