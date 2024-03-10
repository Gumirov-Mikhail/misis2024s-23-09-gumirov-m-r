#include <complex/complex.hpp>

Complex Complex::operator-() const noexcept {
    return Complex(-re, -im);
}

bool Complex::operator==(const Complex& rhs) const noexcept {
    constexpr double eps = 2 * std::numeric_limits<double>::epsilon();
    return (std::abs(re - rhs.re) < eps && std::abs(im - rhs.im) < eps);
}

bool Complex::operator!=(const Complex& rhs) const noexcept {
    constexpr double eps = 2 * std::numeric_limits<double>::epsilon();
    return (std::abs(re - rhs.re) >= eps || std::abs(im - rhs.im) >= eps);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator+=(const double rhs) noexcept {
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept {
    return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
    double re1 = re, im1 = im;
    re = re1 * rhs.re - im1 * rhs.im;
    im = im1 * rhs.re - re1 * rhs.im;
    return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept {
    return operator*=(Complex(rhs));
}

Complex& Complex::operator/=(const Complex& rhs) {
    if (rhs.re == 0 && rhs.im == 0) {
        perror("Error! Division by zero!"); //поменять на свою функцию
    }
    else {
        double re1 = re, im1 = im;
        re = (re1 * rhs.re + im1 * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
        im = (rhs.re * im1 + (-re1) * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    }
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    return operator/=(Complex(rhs));
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) noexcept {
    double re1, im1;
    char left1, separator1, right1;
    istrm >> left1 >> re1 >> separator1 >> im1 >> right1;
    if(istrm.good()) {
        if ((Complex::leftBrace == left1) && (Complex::separator == separator1) && (Complex::rightBrace == right1)) {
            re = re1;
            im = im1;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }

