#ifndef OVERCOAT_H
#define OVERCOAT_H

#include <cstdint>
#include <algorithm>
#include <cstring>

class Overcoat {
public:
    Overcoat(char *types, uint64_t price)
            : types_(types), price_(price) {}

    Overcoat(const Overcoat &another)
            : Overcoat(another.types_, another.price_) {}

    bool operator==(const Overcoat &over) {
        if (strcmp(over.types_,this->types_)==0)
            return true;
        return false;
    }

    bool operator>(const Overcoat &over) {
        if (strcmp(over.types_,this->types_)!=0)
            return false;
        if (this->price_ > over.price_)
            return true;
        return false;
    }

    Overcoat &operator=(const Overcoat &over) {
        if (&over == this)
            return *this;
        Overcoat copy(over);
        std::swap(types_, copy.types_);
        std::swap(price_, copy.price_);
        return *this;
    }

    void printOvercoat() {
        std::cout << "Type: " << types_ << " " << "Price: " << price_ << std::endl;
    }

private:
    char *types_;
    uint64_t price_;
};

#endif //OVERCOAT_H