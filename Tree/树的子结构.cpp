/*
https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    bool isSubtree(TreeNode *pRootA,TreeNode *pRootB){
        if(pRootB == NULL)
            return true;
        if(pRootA == NULL)
            return false;
        if(pRootB->val == pRootA->val){
            return isSubtree(pRootA->left,pRootB->left) 
                && isSubtree(pRootA->right,pRootB->right);
        }
        else
            return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        return isSubtree(pRoot1,pRoot2) 
            || isSubtree(pRoot1->left,pRoot2) 
            || isSubtree(pRoot1->right,pRoot2);
    }
};
