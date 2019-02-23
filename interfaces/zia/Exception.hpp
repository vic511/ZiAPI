#pragma once

#include <stdexcept>

///
/// \brief Exception class for the Zia
///
namespace zia {
class Exception : public std::runtime_error {
public:
    virtual ~Exception() = default;

    explicit Exception(char const *whatArg) : std::runtime_error(whatArg) {}

    explicit Exception(std::string const &whatArg) : std::runtime_error(whatArg)
    {}
};
}  // namespace zia