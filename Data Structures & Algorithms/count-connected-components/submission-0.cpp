class Solution {
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto& e : edges) {
            if (unite(e[0], e[1]))
                components--;
        }

        return components;
    }
};