/*
    https://www.acmicpc.net/problem/1717
    (disjoint set representation)

    references
        https://www.youtube.com/watch?v=a_Qm5f5MiQ8
        (IOI KOREA - disjoint set)

        https://www.youtube.com/watch?v=5pf9HSmBuww
        (IOI KOREA - union & find)

        https://en.wikipedia.org/wiki/Disjoint-set_data_structure
        https://dl.acm.org/doi/pdf/10.1145/62.2160
        (Worst-Case Analysis of Set Union Algorithms)

            Finding set representatives
                path compression
                path splitting
                path halving
            Merging two sets
            Time complexity

    solutions
        https://www.acmicpc.net/source/16948062
        (k0s3y0, 32 ms) : initialize parent = -1, slightly different merge logic

        https://www.acmicpc.net/source/9315420
        (lim551, 20 ms) : path halving optimization

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Data structure / Operations
        disjoint set / union & find

    optimization methods
        union
            union by rank / size
        find
            path compression (most commonly used, easy to implement)


    Specification
        n+1 sets, starting from 0...n

*/

const int NUM_SET = 1'000'000;
const int NUM_OPERATION = 100'000;

enum TYPES{
    operation_union,
    operation_find,
};

int n, m;
int c, a, b;

class Disjoint_Set_Slow{
    private:
        int disjoint_set[NUM_SET + 1];

    public:
        Disjoint_Set_Slow(){
            // cout << "constructor" << endl;
            initialize();
        }

        void initialize(){
            // for(int i=0; i<=n; ++i){
            for(int i=0; i<=NUM_SET; ++i){
                disjoint_set[i] = i;
            }
        }

        void print(){
            for(int i=0; i<=n; ++i){
                cout << disjoint_set[i] << " ";
            }
            cout << endl;
        }

        void set_union(int a, int b){
            int rep_a = disjoint_set[a];
            int rep_b = disjoint_set[b];
            if(rep_a != rep_b){
                for(int idx=0; idx<=n; ++idx){
                    if(disjoint_set[idx] == rep_b){
                        disjoint_set[idx] = rep_a;
                    }
                }
            }
        }

        int set_find(int a);
};

int Disjoint_Set_Slow::set_find(int a){
    return disjoint_set[a];
}

class Disjoint_Set_Fast : Disjoint_Set_Slow{
    private:
        int parent[NUM_SET + 1];
        // NOTE : upper bound (NOT the exact value) of depth of a set which queried element belongs to
        int rank[NUM_SET + 1];

    public:
        Disjoint_Set_Fast(){
            initialize();
        }

        void initialize(){
            // NOTE : takes some more time, but for global variable initialization before the compile time
            // for(int i=0; i<=n; ++i){
            for(int i=0; i<=NUM_SET; ++i){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        void print(){
            for(int i=0; i<=n; ++i){
                cout << parent[i] << " ";
            }
            cout << endl;
        }

        int set_find(int a){
            // while(parent[a] != a){
            //     a = parent[a];
            // }
            // return a;

            // optimization 1 : path halving
            while(parent[a] != a){
                parent[a] = parent[parent[a]];
                a = parent[a];
                // a = parent[a] = parent[parent[a]];
            }
            return a;

            // optimization 2 : path splitting
            // while(parent[a] != a){
            //     int next = parent[a];
            //     parent[a] = parent[parent[a]];
            //     a = next;
            // }
            // return a;

            // optimization 3 : path compression by recursion
            // if(parent[a] == a){
            //     return a;
            // }

            // return parent[a] = set_find(parent[a]);
        }

        void set_union(int a, int b){
            int rep_a = set_find(a);
            int rep_b = set_find(b);

            // NOTE : must operation on representatives
            if(rep_a != rep_b){
                parent[rep_b] = rep_a;

                // optimization : union by rank
                // if(rank[rep_a] == rank[rep_b]){
                //     parent[rep_b] = rep_a;
                //     rank[rep_a] += 1;
                // }
                // else{
                //     if(rank[rep_a] > rank[rep_b]){
                //         parent[rep_b] = rep_a;
                //         // NOTE : no need to update the rank of a non-root node
                //         // rank[rep_b] = rank[rep_a];
                //     }
                //     else{
                //         parent[rep_a] = rep_b;
                //         // NOTE : no need to update the rank of a non-root node
                //         // rank[rep_a] = rank[rep_b];
                //     }
                // }
            }
        }
};


Disjoint_Set_Slow disjoint_set_slow;

void solve_slow_time_exceeded(){
    if(c == operation_find){
        int rep_1 = disjoint_set_slow.set_find(a);
        int rep_2 = disjoint_set_slow.set_find(b);
        if(rep_1 == rep_2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else if(c == operation_union){
        disjoint_set_slow.set_union(a, b);
    }
    else{
        // ERROR
    }
}

Disjoint_Set_Fast disjoint_set_fast;

void solve_fast(){
    if(c == operation_find){
        int rep_a = disjoint_set_fast.set_find(a);
        int rep_b = disjoint_set_fast.set_find(b);
        if(rep_a == rep_b){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else if(c == operation_union){
        disjoint_set_fast.set_union(a, b);
    }
    else{
        // ERROR
    }
    // disjoint_set_fast.print();
}

// set<int> sets[NUM_SET + 1];
vector<set<int> > sets;

void solve_stl_time_exceeded(){
    if(c == operation_find){
        vector<set<int> >::iterator rep_a = sets.end(), rep_b = sets.end();
        for(auto it=sets.begin(); it!=sets.end(); ++it){
            if(it->count(a)){
                rep_a = it;
            }
            if(it->count(b)){
                rep_b = it;
            }
            if(rep_a != sets.end() && rep_b !=sets.end()){
                break;
            }
        }
        if(rep_a == rep_b){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else if(c == operation_union){
        vector<set<int> >::iterator rep_a=sets.end(), rep_b=sets.end();
        for(auto it=sets.begin(); it!=sets.end(); ++it){
            if(it->count(a)){
                rep_a = it;
            }
            if(it->count(b)){
                rep_b = it;
            }
            if(rep_a != sets.end() && rep_b !=sets.end()){
                break;
            }
        }
        set<int> set_b = *rep_b;
        for(auto it=set_b.begin(); it!=set_b.end(); ++it){
            rep_a->insert(*it);
        }
        sets.erase(rep_b);
    }
    else{
        // ERROR
    }
}


void solve(){
    // solve_slow_time_exceeded();

    solve_fast();

    // solve_stl_time_exceeded();
}

void input(){
    cin >> n >> m;

    // initialize

    // disjoint_set_slow.print();
    // disjoint_set_slow.initialize();
    // disjoint_set_slow.print();

    // NOTE : global variable initialization, during the compile time
    // disjoint_set_fast.initialize();

    // for(int i=0; i<=n; ++i){
    //     sets.push_back({i});
    // }

    for(int i=0; i<m; ++i){
        cin >> c >> a >> b;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
