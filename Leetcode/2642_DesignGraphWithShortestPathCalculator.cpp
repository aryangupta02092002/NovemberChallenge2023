class Graph {
public:
    vector<vector<pair<int, int>>> adj;

    Graph(int n, vector<std::vector<int>>& edges) {
        adj.resize(n);
        for (auto edge : edges)
            adj[edge[0]].emplace_back(edge[1], edge[2]);
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }

    int shortestPath(int node1, int node2) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int node = pq.top().second;
            int currCost = pq.top().first;
            pq.pop();

            if (currCost > dist[node])
                continue;

            if(node == node2)
                return currCost ;

            for (auto edge : adj[node]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + dist[node];

                if (dist[neighbor] > newRouteCost) {
                    dist[neighbor] = newRouteCost;
                    pq.push({newRouteCost, neighbor});
                }
            }
        }

        return ((dist[node2] == INT_MAX) ? -1 : dist[node2]);
    }
};
