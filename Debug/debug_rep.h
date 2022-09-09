#ifndef DEBUG_REP_H
#define DEBUG_REP_H
#include<iostream>
#include<sstream>
#include<vector>
#include<iomanip>
#include<algorithm>

// 打印单个变量的值
// 区分了普通变量和指针型变量
template<class T>
std::string debug_rep(const T &t);
template<class T>
std::string debug_rep(T *p);

// 可以打印多个类型不同的变量
template<typename T, typename... Args>
std::string debug_rep(const T& t, const Args&... rset);

template<typename T>
std::string debug_rep_with_name(std::vector<std::string>&&names, const T& t);
template<typename T, typename... Args>
std::string debug_rep_with_name(std::vector<std::string>&&names, const T& t, const Args&... rset);

template<typename T>
std::string PrintVec(const std::vector<T>& vec);
template<typename T>
std::string PrintVecIdx(const std::vector<T>& vec);
template<typename T>
std::string PrintArry(T *Begin, T *End);

#endif