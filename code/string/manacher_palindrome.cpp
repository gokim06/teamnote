// Time Complexity: O(N)
// 각문자를중심으로하는최장팰린드롬의반경을반환
// Manacher("abaaba") = {0,1,0,3,0,1,6,1,0,3,0,1,0}
// # a # b # a # a # b # a #
// 0 1 0 3 0 1 6 1 0 3 0 1 0
vector<int> Manacher(const string &inp){
int n = inp.size() * 2 + 1;
vector<int> ret(n);
string s = "#";
for(auto i : inp) s += i, s += "#";
for(int i=0, p=-1, r=-1; i<n; i++){
ret[i] = i <= r ? min(r-i, ret[2*p-i]) : 0;
while(i-ret[i]-1 >= 0 && i+ret[i]+1 < n && s[i-ret[i]-1] == s[i+ret[i]+1])
ret[i]++;
if(i+ret[i] > r) r = i+ret[i], p = i;
}
return ret;
}
