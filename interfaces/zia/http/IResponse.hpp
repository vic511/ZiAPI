//
// Created by chris on 12/02/19.
//

#pragma once

#include "zia/http/IMessage.hpp"
#include "zia/http/StatusCode.hpp"

namespace zia {
namespace http {

/// \brief Interface for the response
/// \sa IMessage
class IResponse : public IMessage {
public:
    virtual ~IResponse() = default;

    /// \brief set the status of the response
    /// \param code status code of the request
    /// \param reason status message of the response
    virtual void setStatus(StatusCode code, std::string const &reason) = 0;

    /// \brief get the status code of the response
    /// \return status code of the response
    virtual StatusCode getStatusCode() = 0;

    /// \brief get the reason of the response
    /// \return reason of the response
    virtual std::string const &getReason() = 0;
};
}  // namespace http
}  // namespace zia
