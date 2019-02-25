//
// EPITECH PROJECT, 2019
// CPP_zia_2018
// File description:
// Config.hpp
//

#pragma once

#ifdef __linux__

#    define ZIA_SYS_LINUX

#elif defined(_WIN32)

#    define ZIA_SYS_WINDOWS

#else

#    error Incompatible system

#endif
