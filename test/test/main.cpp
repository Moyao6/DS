#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<string>
#include<cstring>
#include<deque>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#define sf(a) scanf("%lf",&a)
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf(a) scanf("%lf",&a)
#define sf2(a,b) scanf("%lf%lf",&a,&b)
#define mp(a,b) make_pair(a,b)
using namespace std;
template <typename T>
void run(T x, int y){
    cout << "函数隐式实例化" << endl;
}

template<> void run<int> (int x, int y){
    cout << "函数显式具体化"<<endl;
}
int main(){
    run('1','1');
    return 0;
}
