#pragma once

#include "zia/Exception.hpp"

namespace zia {
namespace api {

///
/// \brief Configuration error class
///
class ConfigurationError : public zia::Exception {
public:
    explicit ConfigurationError(std::string const &message) : Exception(message)
    {}

    virtual ~ConfigurationError() = default;
};

}  // namespace api
}  // namespace zia