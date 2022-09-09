
#include "debug_rep.h"

template<class T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret<<t;
    return ret.str();
}
template<class T>
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret<<"pointer "<<(void*)p<<":";
    if (p)
        ret<<" "<<debug_rep(*p);
    else 
        ret<<" null pointer";
    return ret.str();
}
template<typename T, typename... Args>
std::string debug_rep(const T& t, const Args&... rset) {
    std::ostringstream ret;
    ret<<t;
    return ret.str() + " | " + debug_rep(rset...);
}

template<typename T>
std::string debug_rep_with_name(std::vector<std::string>&&names, const T& t) {
    std::ostringstream ret;
    ret<<std::left<<std::setw(10)<<names[0]<<": ";
    ret<<debug_rep(t)<<"\n";
    ret<<"---------debug_rep end---------\n";
    return ret.str();
}
template<typename T, typename... Args>
std::string debug_rep_with_name(std::vector<std::string>&&names, const T& t, const Args&... rset) {
    std::ostringstream ret;
    ret<<std::left<<std::setw(10)<<names[0]<<": ";
    ret<<debug_rep(t);
    names.erase(names.begin());
    return ret.str() + "\n" + debug_rep_with_name(std::move(names), rset...);
}

template<typename T>
std::string PrintVec(const std::vector<T>& vec) {
    std::ostringstream ret;
    int idx = 0;
    std::for_each(vec.begin(), vec.end(), [&](const T &t){
        ret<<t<<" ";
    });
    return ret.str();
}
template<typename T>
std::string PrintVecIdx(const std::vector<T>& vec) {
    std::ostringstream ret;
    int idx = 0;
    std::for_each(vec.begin(), vec.end(), [&](const T &t){
        ret<<idx++<<": "<<t<<" | ";
    });
    return ret.str();
}

template<typename T>
std::string PrintArry(T *Begin, T *End) {
    std::ostringstream ret;
    std::for_each(Begin, End, [&](const T &t){
        ret<<t<<" ";
    });
    return ret.str();
}

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