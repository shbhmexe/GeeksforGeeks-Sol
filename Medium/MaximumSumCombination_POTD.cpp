#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;
        
        pq.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});
        
        vector<int> ans;
        
        while (ans.size() < k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            
            if (i + 1 < n && vis.find({i + 1, j}) == vis.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }
            
            if (j + 1 < n && vis.find({i, j + 1}) == vis.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }
        
        return ans;
    }
};

int main() {
    Solution obj;
    
    vector<int> a = {4, 2, 5, 1};
    vector<int> b = {8, 0, 3, 5};
    int k = 5;
    
    vector<int> res = obj.topKSumPairs(a, b, k);
    
    cout << "Top " << k << " Maximum Sum Pairs are:" << endl;
    for (int sum : res) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}


// class Solution {
//   public:
//     vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
//         // CodeGenius
//         int n=a.size();
//         sort(a.rbegin(),a.rend());
//         sort(b.rbegin(),b.rend());
        
//         priority_queue<pair<int,pair<int,int>>>pq;
//         set<pair<int,int>>vis;
        
//         pq.push({a[0]+b[0],{0,0}});
//         vis.insert({0,0});
//         vector<int> ans;
//         while(ans.size()<k){
//             auto top=pq.top();
//             pq.pop();
            
//             int sum=top.first;
//             int i=top.second.first;
//             int j=top.second.second;
//             ans.push_back(sum);
            
//             if(i<n-1&& vis.find({i+1,j})==vis.end()){
//                 pq.push({a[i+1]+b[j],{i+1,j}});
//                 vis.insert({i+1,j});
//             }
//             if(j<n-1&& vis.find({i,j+1})==vis.end()){
//                 pq.push({a[i]+b[j+1],{i,j+1}});
//                 vis.insert({i,j+1});
//             }
//         }
//         return ans;
//     }
// };