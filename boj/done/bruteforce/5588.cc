/*
    https://www.acmicpc.net/problem/5588
    (constellation)

    solution
        O(mn) bruteforcing
        https://www.acmicpc.net/source/19005704
        (leejaejoon, 140 ms) : try all matchings (pair<> star[], pair<> constellation)

        https://www.acmicpc.net/source/2360857
        (ntopia, 4 ms) : implemented in solve_brute_force_set_2()

        https://www.acmicpc.net/source/13838328
        (hun2ya9, 0 ms) : sort() + binary_search()

        https://www.acmicpc.net/source/21555490
        (bone, 0 ms) : sort() + lower_bound()

        implemented in solve_brute_force_set_3()
            https://www.acmicpc.net/source/71754503
            (greydra_k, 0 ms)
            https://www.acmicpc.net/source/6529057
            (alex9801, 0 ms)
            https://www.acmicpc.net/source/252340
            (Nada, 0 ms) : using map<pair<int, int>, bool>
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        parallel move in (x-axis / y-axis)

        (observation) constellation preserves its relative position
        Q. what will be the choice for the 1st constellation ?
        => n choices possible ~ O(10^3)
        try all ?
        m checks required for each choice ~ O(10^3)
        total : O(mn) ~ O(10^6)


        NOTE : all points distinct ?

        use coordinate compression + hashing ?
*/

const int NUM_TARGET = 200;     // 2 * 10^2
const int NUM_POINTS = 1'000;   // 10^3
const int MAX_NUM = 1'000'000;  // 10^6

const int START_POINT = 0;

using p_ii = pair<int, int>;

int m;
vector<p_ii> constellations;
int n;
int x, y;
vector<p_ii> stars;

map<p_ii, bool> hashes[NUM_POINTS + 1];             // (point, visited)
// unordered_map<p_ii, bool> hashes;   // (point, visited)
/*
    error: use of deleted function '
        std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map() [
            with
                _Key = std::pair<int, int>;
                _Tp = bool; _Hash = std::hash<std::pair<int, int> >;
                _Pred = std::equal_to<std::pair<int, int> >;
                _Alloc = std::allocator<std::pair<const std::pair<int, int>, bool> >
        ]
    '
*/

void solve_brute_force_map(){
    for(int ith=0; ith<n; ++ith){
        for(auto& e : stars){
            hashes[ith][e] = false;
        }

        p_ii choice = stars[ith];
        hashes[ith][choice] = true;

        p_ii moves = {
            choice.first - constellations[START_POINT].first,
            choice.second - constellations[START_POINT].second,
        };

        bool is_success = true;
        for(int jth=1; jth<m; ++jth){
            p_ii after = {
                constellations[jth].first + moves.first,
                constellations[jth].second + moves.second,
            };
            if(hashes[ith].count(after) && !hashes[ith][after]){
                hashes[ith][after] = true;
            }
            else{
                is_success = false;
                break;
            }
        }

        if(is_success){
            cout << moves.first << " " << moves.second << endl;
            break;
        }
    }
}

void solve_brute_force_set_1(){
    for(p_ii star : stars){
        p_ii moves = {
            constellations.front().first - star.first,
            constellations.front().second - star.second,
        };

        set<p_ii> candidates;
        // unordered_set<p_ii> candidates;
        /*
            error: use of deleted function '
                std::unordered_set<_Value, _Hash, _Pred, _Alloc>::unordered_set() [
                    with
                        _Value = std::pair<int, int>;
                        _Hash = std::hash<std::pair<int, int> >;
                        _Pred = std::equal_to<std::pair<int, int> >;
                        _Alloc = std::allocator<std::pair<int, int> >
                ]
            '
        */
        for(p_ii target : constellations){
            candidates.insert(target);
        }

        // bool is_success = true;
        for(p_ii before : stars){
            p_ii after = {
                before.first + moves.first,
                before.second + moves.second,
            };

            if(candidates.count(after)){
                candidates.erase(after);
            }
            // else{
            //     is_success = false;
            //     break;
            // }
        }

        // if(is_success){
        if(candidates.empty()){
            cout << -moves.first << " " << -moves.second << endl;
            break;
        }
    }
}

set<p_ii> stars_set;
void solve_brute_force_set_2(){
    // for(auto star : stars){
    //     stars_set.insert(star);
    // }
    stars_set.insert(stars.begin(), stars.end());

    for(auto target : stars){
        p_ii moves = {
            target.first - constellations.front().first,
            target.second - constellations.front().second,
        };

        bool is_success = true;
        for(auto e : constellations){
            p_ii after = {
                e.first + moves.first,
                e.second + moves.second,
            };

            if(!stars_set.count(after)){
                is_success = false;
                break;
            }
        }

        if(is_success){
            cout << moves.first << " " << moves.second << endl;
        }
    }
}

void solve_brute_force_set_3(){
    for(auto it=stars_set.begin(); it!=stars_set.end(); ++it){
        p_ii star = *it;

        p_ii moves = {
            star.first - constellations.front().first,
            star.second - constellations.front().second,
        };

        bool is_success = true;
        for(p_ii e : constellations){
            p_ii after = {
                e.first + moves.first,
                e.second + moves.second,
            };

            if(!stars_set.count(after)){
                is_success = false;
                break;
            }
        }
        if(is_success){
            cout << moves.first << " " << moves.second << endl;
        }
    }
}

void solve(){
    // solve_brute_force_map();     // 168 ms

    // solve_brute_force_set_1();   // 40 ms
    // solve_brute_force_set_2();      // 4 ms : assuming distinct stars form the given constellation
    solve_brute_force_set_3();      // 4 ms
}

void input(){
    cin >> m;

    constellations.resize(m);
    for(auto& e : constellations){
        cin >> e.first >> e.second;
    }

    cin >> n;
    // stars.resize(n);
    // for(auto& e : stars){
    //     cin >> e.first >> e.second;
    // }
    for(int ith=1; ith<=n; ++ith){
        cin >> x >> y;
        stars_set.insert({x, y});
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
