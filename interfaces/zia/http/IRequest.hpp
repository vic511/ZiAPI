//
// Created by chris on 12/02/19.
//

#pragma once

#include <string>
#include "zia/http/IMessage.hpp"
#include "zia/http/Method.hpp"
#include "zia/net/Endpoint.hpp"

namespace zia {
namespace http {

/// \brief Interface for the request
/// \sa IMessage
class IRequest : virtual public IMessage {
public:
    virtual ~IRequest() = default;

    /// \brief get the type of the request
    /// \return type of the request
  virtual std::string getMethod() const = 0;

    /// \brief set the type of the request
    /// \param method type of the request
    virtual void setMethod(Method method) = 0;

    /// \brief set the type of the request
    /// \param method type of the request
    virtual void setMethod(std::string const &method) = 0;

    /// \brief get the path of the request
    /// \return path of the request
    virtual std::string const &getPath() const = 0;

    /// \brief set the path of the request
    /// \param path path of the request
    virtual void setPath(std::string const &path) = 0;

    /// \brief get the endpoint of the request
    /// \return the endpoint of the request
    virtual zia::net::Endpoint const &getEndpoint() const = 0;

    /// \brief set the endpoint of the request
    /// \param endpoint endpoint of the request
    virtual void setEndpoint(zia::net::Endpoint const &endpoint) = 0;
};

}  // namespace http
}  // namespace zia
