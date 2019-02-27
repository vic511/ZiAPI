//
// EPITECH PROJECT, 2019
// CPP_zia_2018
// File description:
// Connection.hpp
//

#pragma once

#include "zia/net/Endpoint.hpp"
#include "zia/net/Socket.hpp"

namespace zia {
namespace net {

///
/// \brief Contains the data of a connection (IP, port, socket)
///
struct Connection {
public:
    Endpoint endpoint;  ///< Client endpoint
    Socket socket;      ///< Socket linked to the client connection
};

}  // namespace net
}  // namespace zia
