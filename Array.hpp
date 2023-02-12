#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <optional>

template<typename T>
class Array {
public:
    Array(std::initializer_list<T> list)
            : size(list.size()),
              array_(new T[size]{}) {
        size_t i = 0;
        for (const T &element: list) {
            if (i >= size)
                break;
            array_[i] = element;
            i++;
        }
    }
    Array(const T array[],
          const size_t new_size,
          const size_t argument_size)
            : size(new_size), array_(new T[new_size]{}) {
        const size_t min_size = std::min(argument_size, new_size);
        for (size_t i = 0; i < min_size; i++) {
            array_[i] = array[i];
        }
    }
    Array(const Array &another)
            : Array(another.array_, another.Size()) {}

    Array(const Array &another, size_t new_size)
            : Array(another.array_, new_size, another.Size()) {}

    Array &operator=(const Array &another) {
        if (&another == this)
            return *this;
        Array copy(another);
        std::swap(size, copy.size);
        std::swap(array_, copy.array_);
        return *this;
    }

    Array(Array &&another) noexcept
            : size(std::exchange(another.size, 0ull)),
              array_(std::exchange(another.array_, nullptr)) {}

    Array &operator=(Array &&another) noexcept {
        if (&another == this)
            return *this;
        delete[] array_;
        size = std::exchange(another.size, 0ull);
        array_ = std::exchange(another.array_, nullptr);
        return *this;
    }

    ~Array() {
        delete[] array_;
    }

    void Add(T elment) {
        T *arr = new T[size + 1];
        if (size == 0) {
            arr[size] = elment;
        } else {
            for (int i = 0; i < size; i++) {
                arr[i] = array_[i];
            }
            arr[size] = elment;
        }
        size += 1;
        delete[] array_;
        array_ = arr;
    }

    T &GetElement(T index) {
        return array_[index];
    }

    const size_t &Size() const {
        return size;
    }

    size_t &Size() {
        return size;
    }

    void Remove(T index) {
        T *arr = new T[size - 1];
        for (int i = index; i < size - 1; i++) {
            array_[i] = array_[i + 1];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = array_[i];
        }
        size -= 1;
        delete[] array_;
        array_ = arr;
    }


    template<class U>
    friend std::ostream &operator<<(
            std::ostream &out,
            const Array<U> &array);

private:
    size_t size;
    T *array_;

    Array(const T array[],
          const size_t size)
            : size(size), array_(new T[size]) {
        for (size_t i = 0; i < size; i++)
            array_[i] = array[i];
    }
};

template<typename T>
std::ostream &operator<<(
        std::ostream &out,
        const Array<T> &array) {
    out << '[';
    if (array.size > 0) {
        for (size_t i = 0; i < array.size - 1; i++)
            out << array.array_[i] << ", ";
        out << array.array_[array.size - 1];
    }
    out << "]\n";

    return out;
}

#endif // ARRAY_H