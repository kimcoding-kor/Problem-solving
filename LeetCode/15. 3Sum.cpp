class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector <int>> ans;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<sz - 2;i++){
            int a = i + 1, b = sz - 1,sum;
            while(a < b){
                sum = nums[i] + nums[a] + nums[b];
                if(!sum){
                    vector <int> v(3,0);
                    v[0] = nums[i], v[1] = nums[a], v[2] = nums[b];
                    ans.emplace_back(v);
                    while(a < b && nums[b - 1] == nums[b]) b--;
                    while(a < b && nums[a] == nums[a + 1]) a++;
                }
                if(sum <= 0) a++;
                else b--;
            }
            while(i < sz - 2 && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};