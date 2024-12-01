#ifndef LIB_SLICE_HPP
#define LIB_SLICE_HPP

#include <algorithm>

#include <cstddef>
#include <cstdlib>

namespace aoc
{

template <typename T> class Slice {
private:
    size_t size_ = 0;
    size_t scope_ = 5;
    T* arr_ = nullptr;

    void GrowIfNeeded() {
        if (size_ == scope_) {
            scope_ <<= 1;
            arr_ = (T*)realloc(arr_, scope_ * sizeof(T));
        }
    }

public:
    Slice() {
        arr_ = (T*)calloc(sizeof(T), scope_);
    }

    ~Slice() {
        free(arr_);
    }

    void Append(const T& val) {
        GrowIfNeeded();
        arr_[size_++] = val;
    }

    void Append(T&& val) {
        GrowIfNeeded();
        arr_[size_++] = std::move(val);
    }

    void Sort() {
        std::sort(arr_, arr_ + size_);
    }

    template <typename Compare>
    void Sort(Compare comp) {
        std::sort(arr_, arr_ + size_, comp);
    }

    T& operator[](size_t index) {
        return arr_[index];
    }

    size_t Size() const {
        return size_;
    }
};

}
    
#endif // LIB_SLICE_HPP
