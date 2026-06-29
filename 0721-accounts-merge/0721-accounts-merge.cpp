/*

    "Mergeing Groups" -> DSU  

    how to merge groups in DSU????????

    Suppose we have 5 nodes.

    Initially

    0    1    2    3    4

    Each node is its own group.

    Components = 5
    Suppose we get an edge

    0 ----- 1

    We perform

    unionBySize(0,1)

    but here what we have nodess??????? 
        EACH ACCOUNT

    and what is edge???????????
        COMMON EMIALS

    When should two accounts become one account?
    If they share at least one email.

    Account 0

    John
    a
    b

    Account 1

    John
    b
    c        

    b is common 
    SO,
    Account 0  --------  Account 1

    How do we know two accounts share an email?

    unordered_map<string,int> mp;
        Email -> Account Index

    Account 0

    a
    b

    Store

    a -> 0
    b -> 0

    Now process Account 1:

    b
    c

    Does b already exist?
    YES
        b -> 0

    Merge them.

    unionBySize(0,1);
    
    After all unions
    Suppose DSU groups become

    {0,1}

    {2}

    {3,4}

    Now collect all emails belonging to each group's leader.

    Leader 0

    a
    b
    c

    Leader 2

    x
    y

    Leader 3

    m
    n

    Sort the emails.

    Add the person's name at the beginning.
    DONE................


    Nodes = Accounts

    Connection = Common Email

    DSU = Merge Connected Accounts


*/

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        // email -> account index
        unordered_map<string, int> mailToIndex;

        // Merge accounts having a common email
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mailToIndex.find(mail) == mailToIndex.end()) {
                    mailToIndex[mail] = i;
                }
                else {
                    ds.unionBySize(i, mailToIndex[mail]);
                }
            }
        }

        // Store emails according to their ultimate parent
        vector<string> mergedMail[n];

        for (auto &it : mailToIndex) {

            string mail = it.first;
            int node = it.second;

            int parent = ds.findUPar(node);

            mergedMail[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        // Build final answer
        for (int i = 0; i < n; i++) {

            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            // Add person's name
            temp.push_back(accounts[i][0]);

            // Add sorted emails
            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};