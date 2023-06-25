#include "../inc/num_vector.h"
#include <algorithm>
#include <iostream>

namespace exam{

    num_vector::num_vector(std::size_t capacity) :
        capacity_{capacity},
        size_{0},
        data_{ new double[capacity]{} }
    { }

    num_vector::num_vector(std::initializer_list<double> lst) :
        capacity_{lst.size()},
        size_{lst.size()},
        data_{new double[lst.size()] }
    {
        std::copy(lst.begin(), lst.end(), data_);
    }

    num_vector::~num_vector() {
        delete[] data_;
    }

    /* Modifiers */

    void num_vector::append(double val) {
        if (capacity() == size()){
            resize(2 * capacity());
        }
        data_[size_++] = val;
    }

    double num_vector::pop_back() {
        return data_[--size_];
    }

    void num_vector::resize(std::size_t new_capacity) {
        if (size_ < new_capacity) {
            auto data = new double[new_capacity]{};
            std::copy(data_, data_ + size(), data);
            delete[] data_;
            data_ = data;
            capacity_ = new_capacity;
        }
    }

    double num_vector::at(std::size_t index) const {
        if (index >= size_)
            throw std::out_of_range("index out of range");
        return data_[index];
    }

    double& num_vector::at(std::size_t index) {
        if (index >= size_)
            throw std::out_of_range("index out of range");
        return data_[index];
    }

    double num_vector::operator[](std::size_t index) const {
        return data_[index];
    }

    double& num_vector::operator[](std::size_t index) {
        return data_[index];
    }


    std::size_t num_vector::size() const {
        return size_;
    }

    std::size_t num_vector::capacity() const {
        return capacity_;
    }


    num_vector& num_vector::operator+=(double val) {
        for (auto i{0u}; i < size_; ++i)
            data_[i] += val;
        return *this;
    }

    num_vector& num_vector::operator+=(const num_vector& rhs) {
        if (size_ != rhs.size_)
            throw std::invalid_argument("size mismatch");

        for (auto i{0u}; i < size_; ++i)
            data_[i] += rhs.data_[i];

        return *this;
    }

    std::ostream& operator<<(std::ostream& out, const num_vector& vec) {
        auto comma = "";
        out << '[';
        for (auto i{0u}; i < vec.size(); ++i) {
            out << comma << vec[i];
            comma = ", ";
        }
        out << ']';
        return out;
    }


    bool operator==(const num_vector& lhs, const num_vector& rhs) {
        if (lhs.size() != rhs.size())
            return false;

        for(auto i{0u}; i < lhs.size(); ++i){
            if (lhs[i] != rhs[i])
                return false;
        }

        return true;
    }

    bool operator!=(const num_vector& lhs, const num_vector& rhs) {
        return !(lhs == rhs);
    }

    void num_vector::swap(const num_vector& other) {
        auto temp = this->data_;
        this->data_ = other.data_;
        other.data_ = temp;
    }

    num_vector &num_vector::operator+(const num_vector &other) {
        for (const auto& c:other) {
            auto result = this->data_ + other.data_;
            return result;
        }
    }

    num_vector::num_vector(const num_vector &other): data_{other.data_}, capacity_{other.capacity()}, size_{other.size()} {

    }
}