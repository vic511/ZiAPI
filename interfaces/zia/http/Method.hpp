//
// Created by chris on 12/02/19.
//

#pragma once

namespace zia {
namespace http {

/// \brief enumeration for http module
/// \sa IRequest
enum class Method {
  Undefined, ///< undefined state
  Options,   ///< option method
  Get,       ///< get method
  Head,      ///< head method
  Post,      ///< post method
  Put,       ///< put method
  Delete,    ///< delete method
  Trace,     ///< trace method
  Connect    ///< connect method
};
} // namespace http
} // namespace zia