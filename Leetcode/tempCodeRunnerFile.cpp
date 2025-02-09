int k = nums.size();
        vector<int> ans(2 * k);
        for (int i = 0; i < k; ++i)
        {
            ans[i] = nums[i];
            ans[i + k] = nums[i];
        }
        return ans;