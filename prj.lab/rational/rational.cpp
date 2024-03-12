#include <rational/rational.hpp>

#include <stdexcept>

Rational::Rational(const std::int64_t num, const std::int64_t den)
        : num_(num), den_(den) {
    if (0 == den_) {
        throw std::invalid_argument("Zero denumenator in Rational ctor");
    }
    else {
        std::int64_t nod = evkl(num_, den_);
        num_ /= nod;
        den_ /= nod;
        this->round();
    }
}

std::int64_t Rational::evkl(const std::int64_t lhs, const std::int64_t rhs) noexcept {
    std::int64_t maxe;
    std::int64_t mine;
    std::int64_t temp;
    maxe = std::max(std::abs(lhs), std::abs(rhs));
    mine = std::min(std::abs(lhs), std::abs(rhs));
    if (mine == 0) {
        return maxe;
    }
    while (maxe % mine != 0) {
        temp = maxe % mine;
        maxe = mine;
        mine = temp;
    }
    return mine;
}

Rational& Rational::round() {
    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }
    return *this;
}

bool Rational::operator==(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ == den_ * rhs.num_);
}

bool Rational::operator!=(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ != den_ * rhs.num_);
}

bool Rational::operator<(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ < den_ * rhs.num_);
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ <= den_ * rhs.num_);
}
bool Rational::operator>(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ > den_ * rhs.num_);
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ >= den_ * rhs.num_);
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.den_ + rhs.num_ * den_;
    den_ = den_ * rhs.den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.den_ - rhs.num_ * den_;
    den_ = den_ * rhs.den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.num_;
    den_ = den_ * rhs.den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    num_ = num_ * rhs.num_;
    den_ = den_ * rhs.den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return *this;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept { return operator+=(Rational(rhs)); };
Rational& Rational::operator-=(const int64_t rhs) noexcept { return operator-=(Rational(rhs)); };
Rational& Rational::operator*=(const int64_t rhs) noexcept { return operator*=(Rational(rhs)); };
Rational& Rational::operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); };


Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{lhs} /= rhs; }

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } -= rhs; };
Rational operator*(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } *= rhs; };
Rational operator/(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator/(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }


std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << num_ << sl << den_;
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
    std::int64_t num, den;
    char sl;
    istrm >> num;
    istrm.get(sl);
    int temp = istrm.peek();
    istrm >> den;
    if (!istrm || temp > '9' || temp < '0') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    if (istrm.good() || istrm.eof()) {
        if (Rational::sl == sl && den > 0) {
            *this = Rational(num, den);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

Rational& Rational::operator++() noexcept {
    num_ += den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return *this;
}

Rational Rational::operator++(int) noexcept {
    Rational a(num_, den_);
    num_ += den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return a;
}

Rational& Rational::operator--() noexcept {
    num_ -= den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return *this;
}

Rational Rational::operator--(int) noexcept {
    Rational a(num_, den_);
    num_ -= den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return a;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept { return ostrm; }

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept { return istrm; }
