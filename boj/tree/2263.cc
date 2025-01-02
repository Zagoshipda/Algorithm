/*
    https://www.acmicpc.net/problem/2263
    (tree traversal)

    similar problem
        https://www.acmicpc.net/problem/1991
        (tree traversal)

        https://www.acmicpc.net/problem/5639
        (binary search tree)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - binary tree with 1...n nodes, NO duplicates
        => given inorder / postorder, find preorder

    Algorithm
        - build binary tree from inorder / postorder
            idea : last item of postorder is the root ~ O(n)
                where to split left / right subtree ?
                - check the appearance of the root from inorder ~ O(?)
                - the node before the root in inorder is the rightmost child of left subtree, so the next node in postorder is the root of the left subtree
                - the node after the root in inorder is the leftmost child of right subtree, so the previous node in postorder is the root of the right subtree

        - execute preorder on the binary tree
            O(n) just by a recursive call with range of indices

        time complexity
            n ~ O(10^5) ~ O(2^17)  ~ O(131072)
            logn ~ O(17) ~ O(10^2)

            n^2 ~ O(10^10)  : brute force
            nlogn ~ O(10^7) : if array is sorted
            n ~ O(10^5)     : using a hash table

            5's time limit ~ O(10^9)



3
1 2 3
3 2 1

// 1 2 (X)
// 1 2 3 (O)


19
8 4 2 14 9 18 15 5 10 1 16 11 6 12 3 17 19 13 7
8 4 14 18 15 9 10 5 2 16 11 12 6 19 17 13 7 3 1

// 1 2 4 8 5 9 14 15 18 10 3 6 11 16 12 7 13 17 19

*/

const int NUM_NODE = 100'000;   // 10^5
const int NIL = 0;

int n;
int inorders[NUM_NODE + 1];
int postorders[NUM_NODE + 1];

struct Node{
    int val;

    int left;   // position in postorder
    int right;  // position in postorder
};

int num_node;
Node nodes[NUM_NODE + 1];

int hashes_in[NUM_NODE + 1];    // hash[k] = p : inorder position p of node k
int hashes_post[NUM_NODE + 1];  // hash[k] = p : postorder position p of node k

int btree[NUM_NODE + 1];
int left[NUM_NODE + 1];
int right[NUM_NODE + 1];


void visit(int node){
    cout << node << " ";
}

// WRONG
void postorder(int curr){
    int pos_root = hashes_in[nodes[curr].val];

    int pos_predecessor = NIL;
    int pos_successor = NIL;

    if(1 < pos_root){
        pos_predecessor = hashes_post[inorders[pos_root - 1]];
    }
    if(pos_root < n){
        pos_successor = hashes_post[inorders[pos_root + 1]];
    }

    if(pos_predecessor < n){
        cout << postorders[pos_predecessor + 1] << " " << nodes[curr].val << endl;
        if(inorders[pos_predecessor + 1] == nodes[curr].val){
            nodes[pos_predecessor].val = postorders[pos_predecessor];
            nodes[curr].left = pos_predecessor;
            postorder(pos_predecessor);
        }
        else{
            // TODO
            nodes[pos_predecessor + 1].val = postorders[pos_predecessor + 1];
            nodes[curr].left = pos_predecessor + 1;
            postorder(pos_predecessor + 1);
        }
    }

    if(1 < pos_successor){
        if(inorders[pos_successor - 1] == nodes[curr].val){
            nodes[pos_successor].val = postorders[pos_successor];
            nodes[curr].right = pos_successor;
            postorder(pos_successor);
        }
        else{
            // TODO
            nodes[curr - 1].val = postorders[curr - 1];
            nodes[curr].right = curr - 1;
            postorder(curr - 1);
        }
    }

    // visit(node);
}

void preorder(int in_left, int in_right, int post_left, int post_right){
    if(in_left > in_right || post_left > post_right){
        return;
    }

    int root_post = post_right;
    int root_in = hashes_in[postorders[root_post]];
    int num_left = root_in - in_left;
    int num_right = in_right - root_in;
    assert(post_left + num_left == post_right - num_right);

    visit(postorders[root_post]);

    preorder(in_left, root_in - 1, post_left, post_left + num_left - 1);
    preorder(root_in + 1, in_right, post_left + num_left, post_right - 1);
}

void solve_struct(){
    // dfs
    nodes[n].val = postorders[n];
    postorder(n);

    // print answer
    // preorder(n);
}

void solve_array(){
    preorder(1, n, 1, n);
}

void solve(){
    // solve_struct();

    solve_array();
}

void input(){
    cin >> n;

    for(int ith=1; ith<=n; ++ith){
        cin >> inorders[ith];
        hashes_in[inorders[ith]] = ith;
    }
    for(int ith=1; ith<=n; ++ith){
        cin >> postorders[ith];
        hashes_post[postorders[ith]] = ith;
    }
}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    solve();

    return 0;
}
