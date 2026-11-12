
class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        size[pu] += size[pv];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        parent.resize(n);
        size.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);

        unordered_map<string, int> emailToAccount;

        // Step 1: Connect accounts using common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                }
                else {
                    unite(i, emailToAccount[email]);
                }
            }
        }

        // Step 2: Group emails by DSU parent
        vector<vector<string>> merged(n);

        for (auto &it : emailToAccount) {
            string email = it.first;
            int root = find(it.second);

            merged[root].push_back(email);
        }

        // Step 3: Build final answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (merged[i].empty()) {
                continue;
            }

            sort(merged[i].begin(), merged[i].end());

            vector<string> account;

            account.push_back(accounts[i][0]);

            for (string &email : merged[i]) {
                account.push_back(email);
            }

            ans.push_back(account);
        }

        return ans;
    }
};
