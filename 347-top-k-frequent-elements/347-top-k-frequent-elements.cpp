
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if( k == nums.size())
            return nums;
        
        map<int,int> cm;
        for(int n:nums)
            cm[n]+=1;
        
        auto comp = [&cm](int n1, int n2){ return cm[n1] > cm[n2];};
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        
        for(auto p:cm){
            heap.push(p.first);
            if(heap.size() > k) heap.pop();
        }
        
        vector<int> top(k);
        for(int i = k-1;i>=0;i--) {top[i]=heap.top(); heap.pop();}
        return top;
    }
};