//
// Created by chris on 12/02/19.
//

#pragma once

#include "zia/Exception.hpp"

namespace zia {
namespace http {

/// \brief throw a exception
/// \sa IMessage
class ParsingError : public zia::Exception {
    virtual ~ParsingError() = default;

    /// \param message error message
    ParsingError(std::string const &message) : Exception(message) {}
};
}  // namespace http
}  // namespace zia