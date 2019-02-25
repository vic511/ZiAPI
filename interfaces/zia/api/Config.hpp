//
// EPITECH PROJECT, 2019
// CPP_zia_2018
// File description:
// Config.hpp
//

#pragma once

#include "zia/sys/Config.hpp"

#ifdef ZIA_SYS_LINUX

#    define ZIA_API_EXPORT

#else

#    define ZIA_API_EXPORT __declspec(dllexport)

#endif
