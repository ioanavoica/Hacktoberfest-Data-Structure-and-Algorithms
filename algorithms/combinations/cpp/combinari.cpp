#include <iostream>
#include <vector>
using namespace std;

void BKT(int n,std::vector<int> &v, std::vector<int> &c, int k){

    if(v.size() == k){
        for (int i = 0; i < k; i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if (!c[i] && ((v.size() && (i > v.back())) || !v.size() ) ) {
            v.push_back(i);
            c[i] = 1;
            BKT(n, v, c, k);
            v.pop_back();
            c[i] = 0;
        }
    }
}

int main() {

    int n, k;
    cin>>n;
    cin>>k;
    std::vector<int> v;
    std::vector<int> c(n + 1, 0);

    BKT(n, v, c, k);
}