#include <iostream>
#include <string>
using namespace std;

class Treeclass {
private:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
    };

public:
    TreeNode* root;

    Treeclass() : root(nullptr) {}

    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode{val, nullptr, nullptr};
        }

        if (val < root->value) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        kthSmallestforhelp(root, k, result);
        return result;
    }

private:
    void kthSmallestforhelp(TreeNode* root, int& k, int& result) {
        if (root == nullptr) {
            return;
        }

        kthSmallestforhelp(root->left, k, result);
        k--;

        if (k == 0) {
            result = root->value;
            return;
        }

        kthSmallestforhelp(root->right, k, result);
    }
};

int main() {
    Treeclass tree;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 46);
    tree.root = tree.insert(tree.root, 1);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 32);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 45);
    tree.root = tree.insert(tree.root, 38);
    tree.root = tree.insert(tree.root, 7);

    int k = 3;
    int result = tree.kthSmallest(tree.root, k);
    cout << "The " << k << "th smallest element in the BST is: " << result << endl;

    return 0;
}
