#ifndef DEBUG_REP_H
#define DEBUG_REP_H
#include<iostream>
#include<sstream>
#include<vector>
#include<iomanip>
#include<algorithm>

namespace DEBUG {
    // 打印单个变量的值
    // 区分了普通变量和指针型变量
    template<class T>
    std::string debug_rep(const T &t);
    template<class T>
    std::string debug_rep(T *p);
    template<class T>
    std::string debug_rep(const T &t) {
        std::ostringstream ret;
        ret<<t;
        return ret.str();
    }

    // 可以打印多个类型不同的变量
    template<typename T, typename... Args>
    std::string debug_rep(const T& t, const Args&... rset);

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
    std::string debug_rep_with_name(std::vector<std::string>&&names, const T& t);
    template<typename T, typename... Args>
    std::string debug_rep_with_name(std::vector<std::string>&&names, const T& t, const Args&... rset);

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
    std::string PrintVec(const std::vector<T>& vec);
    template<typename T>
    std::string PrintVecIdx(const std::vector<T>& vec);
    template<typename T>
    std::string PrintArry(T *Begin, T *End);

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

}
#endif