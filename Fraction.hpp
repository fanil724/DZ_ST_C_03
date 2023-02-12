#ifndef FRACTION_H
#define FRACTION_H

#include <numeric>

template<typename T>
class Fraction {
public:
    Fraction(T numerator, T denominator)
            : numerator_(numerator), denominator_(denominator) {}

    Fraction &reduce() {
        T gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
        return *this;
    }

    [[nodiscard]] Fraction operator+(const Fraction &another) const noexcept {
        return std::move(Fraction(numerator_ * another.denominator_
                                  + another.numerator_ * denominator_,
                                  denominator_ * another.denominator_).reduce());
    }

    [[nodiscard]] Fraction operator-(const Fraction &another) const noexcept {
        return std::move(Fraction(numerator_ * another.denominator_
                                  - another.numerator_ * denominator_,
                                  denominator_ * another.denominator_).reduce());
    }

    [[nodiscard]] Fraction operator*(const Fraction &another) const noexcept {
        return std::move(Fraction(numerator_ * another.numerator_, another.denominator_ * denominator_).reduce());
    }

    [[nodiscard]] Fraction operator/(const Fraction &another) const noexcept {
        return std::move(Fraction(numerator_ * another.denominator_, another.numerator_ * denominator_).reduce());
    }

    Fraction &operator+=(const Fraction &another) {
        *this = *this + another;
        return *this;
    }

    Fraction &operator-=(const Fraction &another) {
        *this = *this - another;
        return *this;
    }

    Fraction &operator*=(const Fraction &another) {
        *this = *this * another;
        return *this;
    }

    Fraction &operator/=(const Fraction &another) {
        *this = *this / another;
        return *this;
    }

    [[nodiscard]] const T &numerator() const noexcept {
        return numerator_;
    }

    [[nodiscard]] const T &denominator() const noexcept {
        return denominator_;
    }

    void print() {
        std::cout << numerator_ << "/" << denominator_ << std::endl;
    }

private:
    T numerator_, denominator_;
};

#endif //FRACTION_H