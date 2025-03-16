#include <iostream>
#include <vector>
using namespace std;
int binsearch(vector <int> a, int x){
int l=0, r=a.size()-1, m;
while (l<=r){
    m=l+(r-l)/2;
    if (a[m]==x) return m;
    else if (a[m]>x) l=m+1;
    else r=m-1;
}
return -1;
}
int main()
{
    int n;
vector <int> a;
while (cin >> n) {
        a.push_back(n);
    }
int i=-1;
int idx=-1;
while (idx==-1){
    i--;
    idx=binsearch(a,i);
}
cout << idx;
}
