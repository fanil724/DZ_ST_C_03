#ifndef SSTRING_H
#define SSTRING_H

#include <iostream>
#include <string>

//Задание №3

static size_t count_ = 0;

class SString {

public:
    SString() {
        string_ = new char[81];
        coutnSString_ = count_;
        count_++;
    }

    SString(size_t size) {
        string_ = new char[size + 1];
        coutnSString_ = count_;
        count_++;
    }

    SString(char *str) {
        const size_t size = strlen(str) + 1;
        string_ = new char[size];
        strcpy_s(string_, size, str);
        coutnSString_ = count_;
        count_++;
    }

    SString(const SString &another)
            : SString(another.string_) {}

    SString &operator=(const SString &another) {
        if (&another == this)
            return *this;
        SString copy(another);
        std::swap(string_, copy.string_);
        return *this;
    }

    SString(SString &&another) noexcept
            : string_(std::exchange(another.string_, nullptr)) {}

    SString &operator=(SString &&another) noexcept {
        if (&another == this)
            return *this;
        delete[] string_;
        string_ = std::exchange(another.string_, nullptr);
        return *this;
    }

//    char &operator[](size_t index) {
//        if (index >= GetSize())
//            throw std::out_of_range("Index is out of range");
//        return string_[index];
//    }

    ~SString() {
        delete[] string_;
    }

    void SetSStrings() {
        char str[50];
        std::cout << "Enter a string:";
        gets(str);
        delete[] string_;
        size_t size = strlen(str) + 1;
        string_ = new char[size];
        strcpy_s(string_, size, str);
    }

    void ShowString() const {
        size_t size = strlen(string_);
        for (size_t i = 0; i < size; i++) {
            std::cout << string_[i];
        }
        std::cout << std::endl;
    }

    const size_t GetCount() const {
        return coutnSString_;
    }

    const size_t GetSize() const {
        return strlen(string_);
    }

    char &operator[](int index) {
        if (index >= strlen(string_)) {
            throw std::out_of_range("Index is out of range");
        }
        return string_[index];
    }

    size_t operator()(char simbol) {
        for (size_t i = 0; i < strlen(string_); i++) {
            if (simbol == string_[i]) {
                return i;
            }
        }
        return -1;
    }

    operator int() {
        return GetSize();
    }


private:
    size_t coutnSString_;
    char *string_;
};

#endif // SSTRING_H
