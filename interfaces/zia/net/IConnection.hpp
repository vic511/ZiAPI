#pragma once

#include "zia/net/Endpoint.hpp"
#include "zia/net/Socket.hpp"

namespace zia {
namespace net {

///
/// \brief This class contains the data of a connection (Ip, Port, Socket)
///
class IConnection {
    virtual ~IConnection() = default;

    ///
    /// \brief Return Endpoint
    /// \sa Endpoint
    /// \return Endpoint
    ///
    virtual Endpoint const &getEndpoint() = 0;

    ///
    /// \brief Return the Socket
    /// \sa Socket
    /// \return Socket
    ///
    virtual Socket const &getSocket() = 0;
};

}  // namespace net
}  // namespace zia