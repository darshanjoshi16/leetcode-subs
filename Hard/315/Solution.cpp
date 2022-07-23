class Solution {
public:
    struct SegmentTree{
        vector<int> tree;
        int n;
        SegmentTree(int n){
            this->n = n;
            tree.resize(4*(n+4));
        }
        
        int left(int node){return 2*node+1;}
        int right(int node) {return 2*node+2;}
        
        void update(int node, int s, int e, int val){
            if(s>e) return;
            if(s==e){
                tree[node]++;
                return;
            }
            
            int mid = s + (e-s)/2;
            if(val<=mid) update(left(node), s, mid, val);
            else update(right(node), mid+1, e, val);
            tree[node] = tree[left(node)] + tree[right(node)];
        }
        
        int query(int node, int s, int e, int qs, int qe){
            if(s>e || qe < s || qs > e) return 0;
            if(s>=qs && e<=qe) return tree[node];
            
            int mid = s + (e-s)/2;
            int l = query(left(node),s,mid,qs,qe);
            int r = query(right(node),mid+1,e,qs,qe);
            return l+r;
        }
        
    };
    
    void convert(vector<int>& nums){
        int sz = nums.size();
        for(int i=0; i<sz; ++i) nums[i]+=10000;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        convert(nums); // coverting range(-10000,10000) to range(0,20000);
        int maxE = *max_element(nums.begin(), nums.end());
        SegmentTree *st = new SegmentTree(maxE+1);
        
        int sz = nums.size();
        vector<int> ans(sz,0);
        for(int i=sz-1; i>=0; --i){
            st->update(0,0,maxE,nums[i]);
            int l =0, r = nums[i]-1;
            ans[i] = st->query(0,0,maxE,0,r);
        }
        return ans;
    }
};
