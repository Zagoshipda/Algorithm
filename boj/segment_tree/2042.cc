/*
    https://www.acmicpc.net/problem/2042
    (range sum 1)

    similar problem
        https://www.acmicpc.net/problem/2268
        (sum of numbers 7) : same problem
        https://www.acmicpc.net/problem/1275
        (coffee shop 2) : same problem

        https://www.acmicpc.net/problem/10999
        (range sum 2)
        https://www.acmicpc.net/problem/11658
        (range sum 3)

    reference
        https://book.acmicpc.net/ds/segment-tree
        (boj book : segment tree)
        https://book.acmicpc.net/algorithm/sqrt-decomposition
        (boj book : square root decomposition)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    segment tree

*/

const int ARR_SIZE = 1'000'000;     // 10^6
const int NUM_UPDATE = 10'000;      // 10^4
const int NUM_QUERY = 10'000;       // 10^4
const ll MAX_NUM = LLONG_MAX;       // 2^63-1
const ll INF = MAX_NUM;

enum TYPES{
    QUERY_UPDATE = 1,
    QUERY_SUM = 2,
};

int N, M, K;
ll arr[ARR_SIZE + 1];
ll a, b, c;

int initial_index;
int range_start, range_end;
ll segment_tree[4 * ARR_SIZE + 1];

pair<int, int> get_child(int index){
    return {2 * index, 2 * index + 1};
}

ll build_segment_tree_1(int index, int start, int end){
    if(start == end){
        return segment_tree[index] = arr[start];
    }

    auto [left_child, right_child] = get_child(index);
    int mid = (start + end) / 2;
    ll left_sum = build_segment_tree_1(left_child, start, mid);
    ll right_sum = build_segment_tree_1(right_child, mid+1, end);

    return segment_tree[index] = left_sum + right_sum;
}

void build_segment_tree_2(int index, int start, int end){
    if(start == end){
        segment_tree[index] = arr[start];
        return;
    }

    auto [left_child, right_child] = get_child(index);
    int mid = (start + end) / 2;
    build_segment_tree_2(left_child, start, mid);
    build_segment_tree_2(right_child, mid+1, end);

    segment_tree[index] = segment_tree[left_child] + segment_tree[right_child];
}

void build_segment_tree(int index, int start, int end){
    build_segment_tree_1(index, start, end);

    // build_segment_tree_2(index, start, end);
}

ll update_segment_tree_1(int index, int start, int end){
    // NOTE : without boundary condition, O(N), time exceeded
    // i.e. this condition achieves O(log N) using DP memoization
    if(end < b || b < start){
        return segment_tree[index];
    }

    if(start == end){   // start == b == end
        // arr[b] = c;
        return segment_tree[index] = c;
    }

    auto [left_child, right_child] = get_child(index);
    int mid = (start + end) / 2;
    ll left_sum = update_segment_tree_1(left_child, start, mid);
    ll right_sum = update_segment_tree_1(right_child, mid+1, end);

    return segment_tree[index] = left_sum + right_sum;
}

void update_segment_tree_2(int index, int start, int end){
    // NOTE : time complexity from O(N) to O(log N)
    if(end < b || b < start){
        return;
    }

    if(start == end){   // start == b == end
        // arr[b] = c;
        segment_tree[index] = c;
        return;
    }

    auto [left_child, right_child] = get_child(index);
    int mid = (start + end) / 2;
    update_segment_tree_2(left_child, start, mid);
    update_segment_tree_2(right_child, mid+1, end);

    // assume subproblems already solved by above recursive call
    segment_tree[index] = segment_tree[left_child] + segment_tree[right_child];
}

ll diff;
void update_segment_tree_3(int index, int start, int end){
    // exclude ranges that NO need to update
    if(end < b || b < start){
        return;
    }

    if(start == end){   // start == b == end
        arr[b] += diff;
        segment_tree[index] += diff;
        return;
    }

    auto [left_child, right_child] = get_child(index);
    int mid = (start + end) / 2;
    update_segment_tree_3(left_child, start, mid);
    update_segment_tree_3(right_child, mid+1, end);

    // segment_tree[index] = segment_tree[left_child] + segment_tree[right_child];
    segment_tree[index] += diff;
}

void update_segment_tree(int index, int start, int end){
    // update_segment_tree_1(index, start, end);

    update_segment_tree_2(index, start, end);

    // diff = c - arr[b];
    // update_segment_tree_3(index, start, end);
}

ll calculate_sum(int index, int start, int end){
    if(end < b || c < start){
        return 0;
    }

    if(b <= start && end <= c){
        return segment_tree[index];
    }

    auto [left_child, right_child] = get_child(index);
    int mid = (start + end) / 2;
    return calculate_sum(left_child, start, mid) + calculate_sum(right_child, mid+1, end);
}

class Square_Root_Decomposition{
    private:
        ll range_sum[ARR_SIZE + 1];
        int group_size;
        int num_group;       // 1...

        int get_current_group(int index){
            return (index - 1) / group_size + 1;
        }

    public:
        Square_Root_Decomposition(){
            for(int ith=1; ith<=ARR_SIZE; ++ith){
                range_sum[ith] = 0;
            }
        }

        void build(){
            group_size = static_cast<int>(sqrt(N));
            num_group = N % group_size ? group_size / N + 1 : group_size / N;

            for(int ith=1; ith<=N; ++ith){
                int curr_group = get_current_group(ith);
                range_sum[curr_group] += arr[ith];
            }
        }

        void update(int idx, ll val){   // NOTE : val can be long long
            int curr_group = get_current_group(idx);
            range_sum[curr_group] -= arr[idx];
            range_sum[curr_group] += val;

            arr[idx] = val;
        }

        ll query(int left, int right){
            ll sum_left = 0;
            ll sum_middle = 0;
            ll sum_right = 0;

            int left_group = get_current_group(left);
            int right_group = get_current_group(right);
            if(left_group == right_group){
                for(int ith=left; ith<=right; ++ith){
                    sum_middle += arr[ith];
                }
            }
            else{
                int end = left_group * group_size;
                for(int ith=left; ith<=end; ++ith){
                    sum_left += arr[ith];
                }

                for(int group=left_group+1; group<=right_group-1; ++group){
                    sum_middle += range_sum[group];
                }

                int start = (right_group - 1) * group_size + 1;
                for(int ith=start; ith<=right; ++ith){
                    sum_right += arr[ith];
                }
            }

            return sum_left + sum_middle + sum_right;
        }
};

Square_Root_Decomposition square_root;

void solve_segment_tree(){  // O(logN)
    if(a == QUERY_UPDATE){
        update_segment_tree(initial_index, range_start, range_end);
    }
    else if(a == QUERY_SUM){
        cout << calculate_sum(initial_index, range_start, range_end) << endl;
    }
    else{
        // ERROR
    }
}

void solve_square_root_decomposition(){ // O(sqrt(N))
    if(a == QUERY_UPDATE){
        square_root.update(b, c);
    }
    else if(a == QUERY_SUM){
        cout << square_root.query(b, c) << endl;
    }
    else{
        // ERROR
    }
}

void solve(){
    // solve_segment_tree();

    solve_square_root_decomposition();
}

void input(){
    cin >> N >> M >> K;
    for(int ith=1; ith<=N; ++ith){
        cin >> arr[ith];
    }

    // O(logN)
    initial_index = 1;
    range_start = 1;
    range_end = N;
    // build_segment_tree(initial_index, range_start, range_end);


    // O(sqrt(N))
    square_root.build();

    for(int ith=1; ith<=M+K; ++ith){
        cin >> a >> b >> c;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
