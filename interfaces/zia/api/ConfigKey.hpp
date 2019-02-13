#pragma once

#include <string>

namespace zia {
namespace api {

///
/// \brief  Structure for the default configuration of a Module
/// \sa IModuleDescriptor
///
struct ConfigKey {
    std::string name;          ///< Name of the key
    std::string defaultValue;  ///< Default value of the key, if empty the key
                               ///< is required in the configuration file
};

}  // namespace api
}  // namespace zia
