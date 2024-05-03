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

    virtual bool empty() const = 0;
    virtual std::ptrdiff_t size() const = 0;

    virtual ~IStackBase() {};

    virtual void printToStream(std::ostream &os) const {
        os << left_brace;
        for (int i = 0; i < size(); i++) {
            if (i > 0) {
                os << comma << " ";
            }
            os << top();
        }
        os << right_brace;
    }

private:
    char left_brace = '[';
    char right_brace = ']';
    char comma = ',';
};

#endif