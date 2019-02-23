#pragma once

namespace zia {
namespace api {

///
/// \brief This is the return type of the methods of a module
/// \sa IHttpModule, INetworModule
///
enum class HookResult {
    Undefined,  ///< Undefined state
    Declined,   ///< The method of a module doesn't process the request
    Ok,    ///< The method of a module process the request and let the others
           ///< methods process the request
    Done,  ///< The method of a module process the request and this is the last
           ///< method to process the request
    Abort  ///< Used to notify the core that the current connection must be
           ///< aborted
};

}  // namespace api
}  // namespace zia