class Solution {
public:
    
    inline bool checkLeft(TreeNode* root, long lower_bound, long higher_bound)
    {
        auto left = root->left;
        auto left_value = left ? left->val : -1;
        // cout << left_value << ' ' << lower_bound << ' '<< root->val << ' ' << higher_bound << endl;
        return !left || left_value > lower_bound && left_value < root->val && left_value < higher_bound;
    }
    
    inline bool checkRight(TreeNode* root, long lower_bound, long higher_bound)
    {
        auto right = root->right;
        auto right_value = right ? right->val : -1;
        // cout << right_value << ' ' << lower_bound << ' '<< root->val << ' ' << higher_bound << endl;
        return !right || right_value > root->val && right_value >= lower_bound && right_value < higher_bound;
    }

    
    bool isValid(TreeNode* root, long lower_bound, long higher_bound)
    {
        if (root == nullptr) return true;
        
        if (checkLeft(root, lower_bound, higher_bound) && checkRight(root, lower_bound, higher_bound))
        {
            return isValid(root->left, lower_bound, min((long)higher_bound, (long)root->val)) &&
                   isValid(root->right, max((long)lower_bound, (long)root->val), higher_bound);
        }
        else
        {
            return false;
        }
    }

    
    bool isValidBST(TreeNode* root) {
        return isValid(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};