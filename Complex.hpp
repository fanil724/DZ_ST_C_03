#ifndef COMPLEX_H
#define COMPLEX_H

template<typename T>
class Complex {
public:
    Complex(T real_, T valid_)
            : real_(real_), valid_(valid_) {};

    void Print() {
        std::cout << real_ << "+(" << valid_ << ")i\n";
    }

    [[nodiscard]]  Complex operator+(const Complex complex2) {
        return {(real_ + complex2.real_), (valid_ + complex2.valid_)};
    }

    [[nodiscard]]Complex operator-(const Complex complex2) {
        return {(real_ - complex2.real_), (valid_ - complex2.valid_)};
    }

    [[nodiscard]]  Complex operator*(const Complex complex2) {
        return {(real_ * complex2.real_ - valid_ * complex2.valid_),
                (real_ * complex2.valid_ + complex2.real_ * real_)};
    }

    [[nodiscard]] Complex operator/(const Complex complex2) {
        return {((real_ * complex2.real_) + (valid_ * complex2.valid_)) /
                (pow(complex2.real_, 2) + pow(complex2.valid_, 2)),
                ((complex2.real_ * valid_) - (real_ * complex2.valid_)) /
                (pow(complex2.real_, 2) + pow(complex2.valid_, 2))};
    }

    Complex &operator+=(const Complex &another) {
        *this = *this + another;
        return *this;
    }

    Complex &operator-=(const Complex &another) {
        *this = *this - another;
        return *this;
    }

    Complex &operator*=(const Complex &another) {
        *this = *this * another;
        return *this;
    }

    Complex &operator/=(const Complex &another) {
        *this = *this / another;
        return *this;
    }

private:
    T real_, valid_;
};

#endif //COMPLEX_H