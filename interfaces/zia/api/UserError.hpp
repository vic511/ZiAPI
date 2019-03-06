//
// EPITECH PROJECT, 2019
// ZiAPI
// File description:
// UserError.hpp
//

#pragma once

#include "zia/Exception.hpp"

namespace zia {
namespace api {

class UserError : public Exception {
    UserError(std::string const &whatArg) : Exception(whatArg) {}
};

}  // namespace api
}  // namespace zia
