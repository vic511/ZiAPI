#pragma once

namespace zia {
namespace api {

///
/// \brief Enumeration of the different types of modules.
/// \sa IModuleDescriptor, IModule
///
enum class ModuleType {
    Undefined,  ///< Undefined state
    Http,       ///< Http module type
    Network     ///< Network module type
};

}  // namespace api
}  // namespace zia