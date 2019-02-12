//
// Created by chris on 12/02/19.
//

#pragma once

#include <cstdint>
#include <vector>

namespace zia {
namespace http {

/// \brief Buffer for http modules
/// \sa IMessage
using Buffer = std::vector<std::u_int8>;

} // namespace http
} // namespace zia