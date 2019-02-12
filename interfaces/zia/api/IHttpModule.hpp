#pragma once

#include "zia/api/HookResult.hpp"
#include "zia/api/IModule.hpp"
#include "zia/http/IRequest.hpp"
#include "zia/http/IResponse.hpp"

namespace zia {

namespace api {

///
/// \brief Interface for http modules, depends of the IModule interface
/// \sa IModule
///
class IHttpModule : public IModule {
public:
    virtual ~IHttpModule() = default;
    ///
    /// \brief This method will be called just after the Http request is
    /// received \sa HookResult \param request Data of the request \param
    /// response Date of th response \return Result of the hook
    ///
    virtual HookResult onRequest(http::IRequest &request,
                                 http::IResponse &response) = 0;

    ///
    /// \brief This method will be called after the onRequest method
    /// \param request Data of the request
    /// \param response Date of th response
    /// \return Result of the hook
    ///
    virtual HookResult onProcess(http::IRequest &request,
                                 http::IResponse &response) = 0;

    ///
    /// \brief This method will be called before the response is send
    /// \param request Data of the request
    /// \param response Date of th response
    /// \return Result of the hook
    ///
    virtual HookResult onResponse(http::IRequest &request,
                                  http::IResponse &response) = 0;
};

}  // namespace api
}  // namespace zia