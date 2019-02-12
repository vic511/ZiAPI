#pragma once

#include <string>
#include <unordered_map>

namespace zia {
namespace api {

///
/// \brief      Zia module interface
///
/// This is the interface for module, every modules depends of this interface
///

class IModule {
public:
    virtual ~IModule() = default;

    ///
    /// \brief Load the configuration for the module
    ///
    /// \param  config   Configuration directives
    ///
    virtual void loadConfiguration(
        std::unordered_map<std::string, std::string> const &config) = 0;
};

}  // namespace api
}  // namespace zia