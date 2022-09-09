
#include "debug_rep.h"
using namespace DEBUG;

int main() {
    int *p = new int(3);
    std::cout<<debug_rep(p)<<"\n";
    std::cout<<debug_rep(1, 3.14, "2333")<<"\n";
    std::cout<<debug_rep_with_name({"a", "b", "c"}, 1, 3.14, "23333");
    std::vector<int> vec = {1, 2, 3};
    std::cout<<PrintVecIdx(vec)<<"\n";
    std::cout<<PrintVec(vec)<<"\n";
    int a[3] = {0, 1, 2};
    std::cout<<PrintArry(a, a+3)<<"\n";
    return 0;
}