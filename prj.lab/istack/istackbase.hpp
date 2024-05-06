#ifndef ISTACKBASE_ISTACKBASE_HPP_202404
#define ISTACKBASE_ISTACKBASE_HPP_202404

#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

template <typename T>
class IStackBase {
public:
    virtual void push(const T &value) = 0;
    virtual void pop() = 0;
    virtual T &top() const = 0;

    [[nodiscard]] virtual bool empty() const = 0;
    [[nodiscard]] virtual std::ptrdiff_t size() const = 0;

    virtual ~IStackBase() = default;

    virtual void printToStream(std::ostream &os) const {
        throw std::logic_error("IStackBase - try print IStackBase");
    }
};

#endif