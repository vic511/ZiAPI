//
// Created by chris on 12/02/19.
//

#pragma once
#include <unordered_map>
#include "Buffer.hpp"

namespace zia {
namespace http {

/// \brief Interface for the message
class IMessage {
public:
    virtual ~IMessage() = default;

    /// \brief getter of body
    /// \return return a Buffer that contains the body
    virtual Buffer const &getBody() const = 0;

    /// \brief setter of body
    /// \param body Buffer that contains the body
    virtual void setBody(Buffer const &body) = 0;

    /// \brief getter of header
    /// \param name the name of the header you want
    /// \return return a string that contains the header
    virtual std::string const &getHeader(std::string const &name) const = 0;

    /// \brief getter of headers
    /// \return return a unordered_map of string that contains all headers
    virtual std::unordered_map<std::string, std::string> const &getHeaders()
        const = 0;

    /// \brief setter of header
    /// \param name the name of the header you want set
    /// \param value the value of the header you want set
    virtual void setHeader(std::string const &name,
                           std::string const &value) = 0;

    /// \brief getter of raw buffer
    /// \return return a Buffer that contains the raw buffer
    virtual Buffer const &getRawBuffer() = 0;

    /// \brief setter of raw buffer
    /// \throw ParsingError
    /// \param rawBuffer Buffer that contains the raw buffer
    virtual void setRawBuffer(Buffer const &rawBuffer) = 0;
};
}  // namespace http
}  // namespace zia
