#pragma once

#include "zia/net/Address.hpp"
#include "zia/net/Port.hpp"

namespace zia {
namespace net {

///
/// \brief Endpoint structure contains the Ip and the Port of the connection
///
struct Endpoint {
    Port port;        ///< Port type
    Address address;  ///< Address type
};

}  // namespace net
}  // namespace zia