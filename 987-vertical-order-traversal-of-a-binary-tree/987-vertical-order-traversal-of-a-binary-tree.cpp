/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        int minn=0,maxx=0;
        while(!q.empty()){
            int n=q.size();
            multiset<pair<int,int>> s;
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front().first;
                int horDist=q.front().second;
                minn=min(minn,horDist);
                maxx=max(maxx,horDist);
                q.pop();
                s.insert({horDist,curr->val});
                // m[horDist].push_back(curr->val);
                if(curr->left) q.push({curr->left,horDist-1});
                if(curr->right) q.push({curr->right,horDist+1});
            }
            for(auto a:s) m[a.first].push_back(a.second);
        }
        for(int i=minn;i<=maxx;i++){
            // sort(m[i])
            ans.push_back(m[i]);
        }
        return ans;
    }
};
// vector<vector<int>> verticalTraversal(TreeNode* root) {
// 	map<int, vector<int> > m;  // when iterate map, key is already the order of x-axis
// 	queue<pair<int, TreeNode*> > q; // for level traversal
// 	q.push({0, root});  // root default x-axis is 0
// 	while(!q.empty()) {
// 		set<pair<int, int> > tmp;  // k: x-axis, v:val Already solved the case when the position is ths same
// 		int len=q.size();
// 		for(int i=0;i<len;++i) {
// 			auto p=q.front();q.pop();
// 			tmp.insert({p.first, p.second->val});
// 			if (p.second->left) q.push({p.first-1, p.second->left});
// 			if (p.second->right) q.push({p.first+1, p.second->right});
// 		}

// 		for(auto p : tmp) m[p.first].push_back(p.second);
// 	}

// 	vector<vector<int> > res;
// 	for(auto kv : m) res.push_back(kv.second);
// 	return res;
// }
//     };
