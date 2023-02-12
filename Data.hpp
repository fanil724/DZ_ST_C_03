#ifndef DATA_H
#define DATA_H

enum months {
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

class Data {
public:
    Data() : m_day(1), m_month(1), m_year(1970) {};

    Data(const Data &d) : m_day(d.m_day), m_month(d.m_month), m_year(d.m_year) {}

    Data(size_t day, size_t month, size_t year
    ) : m_day(day), m_month(month), m_year(year) {};

    ~Data() {
        m_day = 1;
        m_month = 1;
        m_year = 1970;
    }

    void increase() {
        if (is_last_day_of_the_year()) {
            ++m_year;
            m_month = 1;
            m_day = 1;
        } else if (is_last_day_of_the_month()) {
            ++m_month;
            m_day = 1;
        } else {
            ++m_day;
        }
    }

   const bool operator>(const Data &d) {
        if (m_year > d.m_year) {
            if (m_month > d.m_month) {
                if (m_day > d.m_day)
                    return true;
                return false;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool operator<(const Data &d) {
        if (m_year < d.m_year) {
            if (m_month < d.m_month) {
                if (m_day < d.m_day)
                    return true;
                return false;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool operator==(const Data &d) {
        if (m_year == d.m_year) {
            if (m_month == d.m_month) {
                if (m_day == d.m_day) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool operator!=(const Data &d) {
        if (m_year == d.m_year) {
            if (m_month == d.m_month) {
                if (m_day == d.m_day) {
                    return false;
                } else { return true; }
            } else {
                return true;
            }
        } else {
            return true;
        }
    }

    [[nodiscard]] bool is_leap_year() const {
        return ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0);
    }

    Data &operator=(const Data &d) {
        if (&d == this)
            return *this;
        Data copy(d);
        std::swap(m_day, copy.m_day);
        std::swap(m_month, copy.m_month);
        std::swap(m_year, copy.m_year);

        return *this;
    }

    Data &operator+=(const Data &d) {
        m_year = m_year + d.m_year;
        if ((m_month + d.m_month) > 12) {
            m_year++;
            m_month = (m_month + d.m_month - 12);
        } else {
            m_month = (m_month + d.m_month);
        }
        if ((m_day + d.m_day) > 31) {
            if (is_28day_february()) {
                m_day = (m_day + d.m_day - 28);
            } else if (is_29day_february()) {
                m_day = (m_day + d.m_day - 29);
            } else if (is_30day_month()) {
                m_day = (m_day + d.m_day - 30);
            } else {
                m_day = (m_day + d.m_day - 31);
            }
            if (m_month == 12) {
                m_year++;
                m_month = 1;
            } else {
                m_month++;
            }
        } else {
            m_day = (m_day + d.m_day);
        }
    }

    Data &operator-=(const Data &d) {
        m_year = m_year - d.m_year;

        if ((m_month - d.m_month) <= 0) {
            m_year--;
            m_month = 12 - (d.m_month - m_month);
        } else {
            m_month = m_month - d.m_month;
        }
        if ((m_day - d.m_day) <= 0) {
            if (m_month == 0) {
                m_year--;
                m_month = 12;
            } else {
                m_month--;
            }
            if (is_28day_february()) {
                m_day = 28 - (d.m_day - m_day);
            } else if (is_29day_february()) {
                m_day = 29 - (d.m_day - m_day);
            } else if (is_30day_month()) {
                m_day = 30 - (d.m_day - m_day);
            } else {
                m_day = 31 - (d.m_day - m_day);
            }
        } else {
            m_day = m_day - d.m_day;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Data &d) {
        os << d.m_day << "." << d.m_month << "." << d.m_year << std::endl;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Data &dt) {
        is >> dt.m_day >> dt.m_month >> dt.m_year;
        return is;
    }

    bool is_last_day_of_the_year() const {
        return m_month == DEC && m_day == 31;
    }

    bool is_last_day_of_the_month() const {
        bool result = true;
        if ((is_28day_february() && m_day != 28) ||
            (is_29day_february() && m_day != 29) ||
            (is_30day_month() && m_day != 30) ||
            (is_31day_month() && m_day != 31)
                ) {
            result = false;
        }
        return result;
    }

    bool is_february() const {
        return m_month == FEB;
    }

    bool is_28day_february() const {
        return m_month == FEB && !is_leap_year();
    }

    bool is_29day_february() const {
        return m_month == FEB && is_leap_year();
    }

    bool is_30day_month() const {
        return m_month == APR || m_month == JUN || m_month == SEP || m_month == NOV;
    }

    bool is_31day_month() const {
        return !is_february() && !is_30day_month();
    }

private:
    int m_day;
    int m_month;
    size_t m_year;


};


#endif //DATA_H