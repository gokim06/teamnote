// Time Complexity: O(log N)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
// T,
// null_type,
less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update
>;
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ordered_set<int> s;
s.insert(10);
s.insert(20);
s.insert(30);
s.insert(40);
// find_by_order(k): returns iterator to k-th element (0-indexed)
cout << *s.find_by_order(0) << "\n"; // 10
cout << *s.find_by_order(2) << "\n"; // 30
// order_of_key(x): returns number of elements strictly smaller than x
cout << s.order_of_key(25) << "\n"; // 2 (10, 20 < 25)
cout << s.order_of_key(40) << "\n"; // 3
// You can use it to find the nth element online in O(log N)
int n = 2;
cout << "The " << n << "-th smallest element is " << *s.find_by_order(n - 1) << "\n";
return 0;
}
