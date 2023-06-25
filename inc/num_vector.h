#ifndef EXAM_2023_II_NUM_VECTOR_H
#define EXAM_2023_II_NUM_VECTOR_H

#include <initializer_list>
#include <iostream>
#include <cstdlib>

namespace exam{

    class num_vector {
    public:
        /* Constructors */
        num_vector(std::size_t capacity);
        num_vector(std::initializer_list<double> lst);

        /* TODO: implement the missing special member functions, following the rule of three */
        num_vector(const num_vector& other);
        /* Destructor */
        ~num_vector();

        /* Modifiers */
        void swap(const num_vector& other);
        /* TODO: implement the swap function. It should swap the content of the current instance with another num_vector object */

        void append(double number);
        double pop_back();

        /* Accessors */

        double at(std::size_t index) const;
        double& at(std::size_t index);

        double operator[](std::size_t index) const;
        double& operator[](std::size_t index);

        std::size_t size() const;
        std::size_t capacity() const;

        /* Member operators */

        num_vector& operator+=(double val);
        num_vector& operator+=(const num_vector& rhs);

        /* TODO: implement the addition operator as a member function */
        num_vector& operator+(const num_vector& other);

    private:
        std::size_t capacity_;
        std::size_t size_;
        double *data_;

        void resize(std::size_t new_capacity);
    };

    /* Stream output operator */
    std::ostream& operator<<(std::ostream& out, const num_vector& vec);

    /* Free function comparison operators */
    bool operator==(const num_vector& lhs, const num_vector& rhs);
    bool operator!=(const num_vector& lhs, const num_vector& rhs);
}

#endif //EXAM_2023_II_NUM_VECTOR_H
