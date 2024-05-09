#pragma once
#ifndef UNITTEST_UNITTEST_HPP_202405
#define UNITTEST_UNITTEST_HPP_202405

#include <vector>
#include <string>

template<typename T>
void FillData(const int n, std::vector<T>& data) {
    data.clear();
    data.reserve(n);
    for (int i = 0; i < n; i++) {
        data.emplace_back(i);
    }
}

template<>
void FillData(const int n, std::vector<std::string>& data) {
    data.clear();
    data.reserve(n);
    for (int i = 0; i < n; i++) {
        data.emplace_back(std::to_string(i));
    }
}

#endif