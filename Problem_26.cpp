    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
            
        int replace_index = 0;
        int start = *nums.begin();
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i-1])
            {
                nums[++replace_index] = nums[i];
            }
        }
        
        return replace_index + 1;
    }
