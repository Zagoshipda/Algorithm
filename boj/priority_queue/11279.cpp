/*
    https://www.acmicpc.net/problem/11279
    (max heap)

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

class max_heap{
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
            // return (heap.size() == 1 && index == ROOT) ? true : index > get_parent(static_cast<int>(heap.size())-1);

            return index >= heap.size() / 2;
        }

    public:
        bool empty(){
            return heap.empty();
        }

        int top(){
            return heap[ROOT];
        }

        void push(int num){
            heap.push_back(num);

            int current = heap.size()-1;
            while(!is_root(current)){
                int parent = get_parent(current);
                if(heap[current] > heap[parent]){
                    swap(heap[current], heap[parent]);
                    current = parent;
                }
                else{
                    break;
                }
            }
        }

        void pop(){
            // swap(heap[0], heap[heap.size()-1]);
            swap(heap[0], heap.back());
            heap.pop_back();

            int current = ROOT;
            while(!heap.empty() && !is_leaf(current)){
                int left_child = get_left_child(current);
                int right_child = get_right_child(current);
                int max_child = (right_child > heap.size()-1) ? left_child : (
                    (heap[left_child] > heap[right_child]) ? left_child : right_child
                );
                if(heap[max_child] > heap[current]){
                    swap(heap[max_child], heap[current]);
                    current = max_child;
                }
                else{
                    break;
                }
            }
        }
};

max_heap my_max_heap;
// priority_queue<int, vector<int>, less<int> > my_max_heap;

void solve_max_heap(){
    if(x){
        my_max_heap.push(x);
    }
    else{
        if(my_max_heap.empty()){
            cout << 0 << endl;
        }
        else{
            cout << my_max_heap.top() << endl;
            my_max_heap.pop();
        }
    }
}

void solve(){
    solve_max_heap();
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
