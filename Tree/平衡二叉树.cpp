/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
(即，左右两个子树的高度差的绝对值不超过1度)
https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

class Solution {
public:
    bool IsBalanced(TreeNode* root,int &dep){
        if(root == NULL)
            return true;
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left,left) && IsBalanced(root->right,right)){
            int dif = left - right;
            if(dif < -1 || dif > 1)
                return false;
            dep = max(left,right) + 1;
            return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot,dep);
    }
};
