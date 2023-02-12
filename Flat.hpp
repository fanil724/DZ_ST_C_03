#ifndef FLAT_H
#define FLAT_H

#include <cstdint>
#include <algorithm>

class Flat {
public:
    Flat(double area, uint64_t price)
            : area_(area), price_(price) {}

    Flat(const Flat &another)
            : Flat(another.area_, another.price_) {}

    bool operator==(const Flat &flat) {
        if (flat.area_ == this->area_)
            return true;
        return false;
    }

    bool operator>(const Flat &flat) {
        if (this->price_ > flat.price_)
            return true;
        return false;
    }

    Flat &operator=(const Flat &flat) {
        if (&flat == this)
            return *this;
        Flat copy(flat);
        std::swap(area_, copy.area_);
        std::swap(price_, copy.price_);
        return *this;
    }

    void printFlat() {
        std::cout << "S: " << area_ << " " << "Price: " << price_ << std::endl;
    }

private:
    double area_;
    uint64_t price_;
};


#endif //FLAT_H