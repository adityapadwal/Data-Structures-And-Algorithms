#include <iostream>
#include <vector>
using namespace std;

template<typename >
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};



// ************************************ Problems Starts From here ***********************************
void inorderBST(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorderBST(root->left, in);
    in.push_back(root->data);
    inorderBST(root->right, in);
}

vector<int> mergeArrays(vector<int> bst1, vector<int> bst2)
{
    vector<int> answer(bst1.size() + bst2.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
        {
            answer[k++] = bst1[i];
            i++;
        }
        else
        {
            answer[k++] = bst2[j];
            j++;
        }
    }

    while (i < bst1.size())
    {
        answer[k++] = bst1[i];
        i++;
    }
    while (j < bst2.size())
    {
        answer[k++] = bst2[j];
        j++;
    }

    return answer;
}

TreeNode<int> *inorderToBST(int s, int e, vector<int> ans)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode<int> *root = new TreeNode<int>(ans[mid]);
    root->left = inorderToBST(s, mid - 1, ans);
    root->right = inorderToBST(mid + 1, e, ans);
    return root;
}


// *************************** Main Function ***************************************
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{

    // Step1. Store inorder of the two BSTs into 2 separate vectors
    vector<int> bst1;
    vector<int> bst2;
    inorderBST(root1, bst1);
    inorderBST(root2, bst2);

    // 2. Merge the 2 sorted vectors
    vector<int> ans = mergeArrays(bst1, bst2);

    // 3. solve for inorderToBST function
    int s = 0;
    int e = ans.size() - 1;
    return inorderToBST(s, e, ans);
}