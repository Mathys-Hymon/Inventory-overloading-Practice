#pragma once
#include <vector>

template <typename T>
std::vector<T>& operator+=(std::vector<T>& vec, const T& element) {
    vec.push_back(element);
    return vec;
}

template <typename T>
std::vector<T>& operator+=(std::vector<T>& vec, const std::vector<T>& other) {
    vec.insert(vec.end(), other.begin(), other.end());
    return vec;
}

template <typename T>
std::vector<T>& operator-=(std::vector<T>& vec, const T& element) {
    auto it = std::remove(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        vec.erase(it, vec.end());
    }
    return vec;
}

template <typename T>
std::vector<T>& operator-=(std::vector<T>& vec, const std::vector<T>& other) {
    for (const auto& element : other) {
        vec -= element; // Utilise l'opérateur précédent pour chaque élément
    }
    return vec;
}