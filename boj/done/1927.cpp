/*
    https://www.acmicpc.net/problem/1927
    (min heap)

    heap implementation
        https://www.acmicpc.net/source/61093957
        https://www.acmicpc.net/source/19117585
        https://www.acmicpc.net/source/37416484

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_OPERATION 100'000
int N;
int x;

const int ROOT = 0;
class min_heap{
    private:
        vector<int> heap;

        int get_parent(int index){
            return (index-1) / 2;
        }

        int get_left_child(int index){
            return 2*index + 1;
        }

        int get_right_child(int index){
            return 2*index + 2;
        }

        bool is_root(int index){
            return index == ROOT;
        }

        bool is_leaf(int index){
            return get_left_child(index) > heap.size()-1;
        }

    public:
        bool empty(){
            return heap.empty();
        }

        int top(){
            return heap[0];
        }

        void push(int num){
            heap.push_back(num);
            int current = heap.size()-1;
            while(true){
                if(is_root(current)){
                    break;
                }
                int parent = get_parent(current);
                if(heap[parent] > heap[current]){
                    swap(heap[parent], heap[current]);
                    current = parent;
                }
                else{
                    break;
                }
            }
        }

        void pop(){
            swap(heap[ROOT], heap[heap.size()-1]);
            heap.pop_back();
            int current = ROOT;
            // ERROR : out of bounds
            // if (after pop only one element) heap becomes empty, return immediately
            // while(true){
            while(!heap.empty()){
                if(is_leaf(current)){
                    break;
                }
                int left_child = get_left_child(current);
                int right_child = get_right_child(current);
                int min_child = right_child > heap.size()-1 ? left_child : (
                    heap[left_child] < heap[right_child] ? left_child : right_child
                );
                if(heap[current] > heap[min_child]){
                    swap(heap[current], heap[min_child]);
                    current = min_child;
                }
                else{
                    break;
                }
            }
        }
};

min_heap my_min_heap;
void solve_min_heap(){
    if(x){
        my_min_heap.push(x);
    }
    else{
        if(my_min_heap.empty()){
            cout << 0 << endl;
        }
        else{
            cout << my_min_heap.top() << endl;
            my_min_heap.pop();
        }
    }
}

priority_queue<int, vector<int>, greater<int> > pq_min;
void solve_pq(){
    if(x){
        pq_min.push(x);
    }
    else{
        if(pq_min.empty()){
            cout << 0 << endl;
        }
        else{
            cout << pq_min.top() << endl;
            pq_min.pop();
        }
    }
}

void solve(){
    // solve_pq();

    solve_min_heap();
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> x;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
