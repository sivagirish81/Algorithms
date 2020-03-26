class Solution {
public:
    void findCombinations(vector<int>& candidates, int target,vector<int> & temp,vector<vector<int>> &res,int pos)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        while (pos < candidates.size() && target - candidates[pos] >= 0)
        {
            temp.push_back(candidates[pos]);
            findCombinations(candidates,target - candidates[pos],temp,res,pos);
            pos++;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        findCombinations(candidates,target,temp,res,0);
        return res;
    }
};