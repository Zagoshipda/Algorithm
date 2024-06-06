/*
    https://www.acmicpc.net/problem/28340
    (k-ary Huffman encoding)

    similar problem
        https://www.acmicpc.net/problem/13975
        (merging files 3)

    solution
        https://www.acmicpc.net/source/63674815
        (koosaga, 12 ms)
        https://www.acmicpc.net/source/69704556
        (zenith82114, 8 ms) : calculate depth for each node by DP

    reference
        Huffman coding
            https://en.wikipedia.org/wiki/Huffman_coding
            Encode
                    creating a Huffman tree : "binary tree" of nodes that (omits unused symbols) produces the most optimal code lengths
                - Initially, all nodes are leaf nodes = the symbol itself + the weight (frequency of appearance) of the symbol
                - Internal nodes contain a weight, links to two child nodes, and an optional link to a parent node
                - As a common convention, bit '0' represents following the left child, and bit '1' represents following the right child
                - up to n leaf nodes, n-1 internal nodes

                - begins with the leaf nodes containing the probabilities of the symbol they represent
                - repeat until only one node remains, which is the root of the Huffman tree
                    - takes the two nodes with smallest probability, and creates a new internal node having these two nodes as children, and the weight of the new node is set to the sum of the weight of its children
                    - apply the process again, on the new internal node and on the remaining leaf nodes (i.e., we exclude the two leaf nodes)

                Once the Huffman tree has been generated, it is traversed to generate a dictionary which maps the symbols to binary codes
                    - Start with current node set to the root
                    - repeat the process at both the left child and the right child until the leaf node (symbol)
                        - If node is not a leaf node, label the edge to the left child as 0 and the edge to the right child as 1.
                    - encoding of any symbol is then read by a concatenation of the labels on the edges along the "path from the root node to the symbol"

            Algorithm
                - priority queue
                    - using a priority queue where the node with lowest probability is given highest priority
                    - efficient priority queue require O(log n) time per insertion, and a tree with n leaves has 2n−1 nodes, this algorithm operates in O(n log n) time, where n is the number of symbols
                - two queues
                    If the symbols are sorted by probability, there is a linear-time (O(n)) method to create a Huffman tree using two queues
                    - the first one containing the initial weights, and combined weights being put in the back of the second queue
                    - Dequeue the two nodes with the lowest weight by examining the fronts of both queues
                    + Enqueue the new node into the rear of the second queue
                    => This assures that the lowest weight is always kept at the front of one of the two queues

            Time complexity
                - time complexity is not very important in the choice of algorithm here, since n here is the number of symbols in the alphabet, which is typically a very small number (compared to the length of the message to be encoded)

            (modification)
                minimizing variance & minimizing the length of the longest character code
                    - It is generally beneficial to minimize the variance of codeword length
                    - To minimize variance, simply break ties between queues by choosing the item in the first queue

                n-ary Huffman coding
                    - n-ary Huffman algorithm uses the {0, 1,..., n−1} alphabet to encode message and build an n-ary tree
                    - n least probable symbols are taken together
                    - for n greater than 2, not all sets of source words can properly form an n-ary tree for Huffman coding, so that additional 0-probability place holders must be added
                    (observation) If the number of source words is congruent to 1 modulo n−1, then the set of source words will form a proper Huffman tree
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        - n-ary Huffman algorithm uses the {0, 1,..., n−1} alphabet to encode message and build an n-ary tree
        - If the number of source words is congruent to 1 modulo n−1, then the set of source words will form a proper Huffman tree
        n = 1 (mod n-1)

        length
            1 : n-1
            2 : n-1
            ...
        4 2
        1 2 3 4
        0 1 2 3
            length
            1 : 4th X 3 = 3
            2 : 3rd X 2 = 4
            3 : 2nd X 1 = 3

2
7 5
1 1 2 3 4 4 4
3 3
1 2 3

// 23
// 7 (X)
// 6 (O)


*/

const int NUM_CHARACTER = 10'000;   // 10^4
const int MAX_BASE = 10'000;    // 10^4
const int MAX_NUM = 100'000;    // 10^5

int T;
int N, K;
ll C;

void solve_greedy_wrong(){
    ll Ci[NUM_CHARACTER << 1];

    sort(Ci+1, Ci+1+N, greater<ll>());

    ll sum = 0;
    for(int idx=1, cnt=0, len=1; idx<=N; ++idx, ++cnt){
        if(cnt >= K-1){
            cnt = 0;
            ++len;
        }
        sum += len * Ci[idx];
    }
    cout << sum << endl;
}

priority_queue<ll, vector<ll>, greater<ll> > pq_min; // (cnt)
void solve_greedy(){
    ll sum = 0;
    while(pq_min.size() > 1){
        ll sum_cnt = 0;
        for(int ith=1; ith<=K; ++ith){
            ll cnt = pq_min.top();
            pq_min.pop();

            sum_cnt += cnt;
        }

        pq_min.push(sum_cnt);
        // NOTE : regard as the sum of internal nodes
        sum += sum_cnt;
    }

    cout << sum << endl;
    pq_min.pop();
}

void solve(){
    solve_greedy();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        for(int idx=1; idx<=N; ++idx){
            // cin >> Ci[idx];
            cin >> C;
            pq_min.push(C);
        }

        for( ; K > 2 && (N-1) % (K-1); ++N){
            pq_min.push(0);
        }

        solve();
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
