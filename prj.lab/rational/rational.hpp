#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <cstdint>
#include <iosfwd>
#include <iostream>
#include <algorithm>

class Rational {
public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;
    explicit Rational(const std::int64_t num) noexcept : num_(num) {}
    Rational(const std::int64_t num, const std::int64_t den);
    ~Rational() = default;
    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    [[nodiscard]] std::int64_t num() const noexcept { return num_; }
    [[nodiscard]] std::int64_t den() const noexcept { return den_; }

    [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

    [[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator/=(const Rational& rhs);

    Rational& operator+=(const int64_t rhs) noexcept;
    Rational& operator-=(const int64_t rhs) noexcept;
    Rational& operator*=(const int64_t rhs) noexcept;
    Rational& operator/=(const int64_t rhs);

    std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
    std::istream& ReadFrom(std::istream& istrm) noexcept;

    std::int64_t evkl(const std::int64_t lhs, const std::int64_t rhs) noexcept;
    std::int64_t evkl(const Rational& lhs) noexcept { return evkl(lhs.num_, lhs.den_); }
    Rational& round();

private:
    std::int64_t num_ = 0;
    std::int64_t den_ = 1;
    static const char sl {'/'};

};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int64_t rhs);

[[nodiscard]] Rational operator+(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int64_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

#endif

