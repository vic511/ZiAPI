#pragma once

#include "zia/net/Endpoint.hpp"
#include "zia/net/Socket.hpp"

namespace zia {
namespace net {

///
/// \brief This class contains the data of a connection (Ip, Port, Socket)
///
class IConnection {
public:
    virtual ~IConnection() = default;

    ///
    /// \brief Return Endpoint
    /// \sa Endpoint
    /// \return Endpoint
    ///
    virtual Endpoint const &getEndpoint() const = 0;

    ///
    /// \brief Return the Socket
    /// \sa Socket
    /// \return Socket
    ///
    virtual Socket const &getSocket() const = 0;
 };

}  // namespace net
}  // namespace zia