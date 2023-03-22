#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'    // for debugging
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 27
#define ROOT 'A'
#define ASCII 65
#define EMPTY '.'
int N;
struct Tree{
    char value;
    struct Tree* left;
    struct Tree* right;
};

struct Tree tree[SIZE];

void print_preorder(struct Tree* root){
    // current node
    if(root == nullptr){
        return;
    }

    // current node
    cout << root->value;

    // left child
    print_preorder(root->left);

    // right child
    print_preorder(root->right);

    return;
}
void print_inorder(struct Tree* root){
    if(root == nullptr){
        return;
    }

    // left child
    print_inorder(root->left);

    // current node
    cout << root->value;

    // right child
    print_inorder(root->right);

    return;
}

void print_postorder(struct Tree* root){
    if(root == nullptr){
        return;
    }

    // left child
    print_postorder(root->left);

    // right child
    print_postorder(root->right);

    // current node
    cout << root->value;

    return;
}

int main(){
    IOS;

    cin >> N;
    char root_node, left_child, right_child;
    for(int i=0; i<N; ++i){
        cin >> root_node >> left_child >> right_child;
        tree[root_node-ASCII].value = root_node;
        if(left_child == EMPTY){
            tree[root_node-ASCII].left = nullptr;
        }
        else{
            tree[root_node-ASCII].left = &tree[left_child-ASCII];
        }
        if(right_child == EMPTY){
            tree[root_node-ASCII].right = nullptr;
        }
        else{
            tree[root_node-ASCII].right = &tree[right_child-ASCII];
        }
    }

    print_preorder(&tree[ROOT-ASCII]);
    cout << endl;
    print_inorder(&tree[ROOT-ASCII]);
    cout << endl;
    print_postorder(&tree[ROOT-ASCII]);

    return 0;
}
