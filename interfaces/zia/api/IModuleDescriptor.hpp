#pragma once

#include <memory>
#include <vector>
#include "zia/api/ConfigKey.hpp"
#include "zia/api/IModule.hpp"
#include "zia/api/ModuleType.hpp"

namespace zia {
namespace api {

///
/// \brief This class will be the "descriptor" of a module and the link to the
/// creation of this one
///
///
class IModuleDescriptor {
public:
    virtual ~IModuleDescriptor() = default;

    ///
    /// \brief Return the type of the module
    /// \return Type of the module
    ///
    virtual ModuleType getType() const = 0;

    ///
    /// \brief Return the name of the module
    /// \return Name of the module
    ///
    virtual std::string const &getName() const = 0;

    ///
    /// \brief Return the default configuration of a module
    /// \return Default configuration
    ///
    virtual std::vector<ConfigKey> const &getConfigKeys() const = 0;

    ///
    /// \brief Create a instance of the module
    /// \return Instance of a module
    ///
    virtual std::unique_ptr<IModule> create() = 0;
};

}  // namespace api
}  // namespace zia