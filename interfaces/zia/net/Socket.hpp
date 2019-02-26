//
// EPITECH PROJECT, 2019
// ZiAPI
// File description:
// Socket.hpp
//

#pragma once

#include "zia/sys/Config.hpp"

#ifdef ZIA_SYS_WINDOWS
#    include <winsock2.h>
#endif

namespace zia {
namespace net {

#ifdef ZIA_SYS_WINDOWS

///
/// \brief Socket type
///
using Socket = SOCKET;

#else

///
/// \brief Socket type
///
using Socket = int;

#endif

}  // namespace net
}  // namespace zia
