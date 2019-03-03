#pragma once

#include "zia/net/Address.hpp"
#include "zia/net/Port.hpp"

namespace zia {
namespace net {

///
/// \brief Endpoint structure contains the Ip and the Port of the connection
///
struct Endpoint {
    Address address;  ///< Address type
    Port port;        ///< Port type
};

}  // namespace net
}  // namespace zia
