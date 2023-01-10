/*
181. Pair Sum Binary Tree: Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
*/

#include <vector>
#include <algorithm>
#include <climits>

/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

void intoArray(BinaryTreeNode<int> *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    arr.push_back(root->data);
    intoArray(root->left, arr);
    intoArray(root->right, arr);
}

// O(nlogn)
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> arr;
    intoArray(root, arr);
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else if (arr[i] + arr[j] > sum)
        {
            j--;
        }
        else
        {
            cout << arr[i] << " " << arr[j] << "\n";
            i++;
            j--;
        }
    }
}