//
// EPITECH PROJECT, 2019
// ZiAPI
// File description:
// ServerError.hpp
//

#pragma once

#include "zia/Exception.hpp"

namespace zia {
namespace api {

class ServerError : public Exception {
    ServerError(std::string const &whatArg) : Exception(whatArg) {}
};

}  // namespace api
}  // namespace zia
