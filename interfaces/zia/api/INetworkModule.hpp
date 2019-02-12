#pragma once

#include "zia/api/HookResult.hpp"
#include "zia/api/IModule.hpp"
#include "zia/net/IConnection.hpp"
#include "zia/net/Buffer.hpp"

namespace zia {

namespace api {

///
/// \brief Interface for network modules, depends of the IModule interface
/// \sa IModule
///
class INetworkModule : public IModule {
    virtual ~INetworkModule() = default;
    ///
    /// \brief This method wiil be called just after the accept of a socket
    /// \sa HookResult, Endpoint, Socket
    /// \param connection Contains the data of the connection (Endpoint and
    /// Socket) \return Result of the hook
    ///
    virtual HookResult onAccept(net::IConnection const &connection) = 0;

    ///
    /// \brief This method wiil be called instead of the basic read function
    /// \sa HookResult, Endpoint, Socket
    /// \param connection Contains the data of the connection (Endpoint and
    /// Socket) \param buffer Contains the data read by the method \return
    /// Result of the hook
    ///
    virtual HookResult doRead(net::IConnection const &connection,
                              net::Buffer &buffer) = 0;

    ///
    /// \brief This method wiil be called after the read function
    /// \sa HookResult, Endpoint, Socket
    /// \param connection Contains the data of the connection (Endpoint and
    /// Socket) \param buffer Contains the data read by the read function
    /// \return Result of the hook
    ///
    virtual HookResult onRead(net::IConnection const &connection,
                              net::Buffer &buffer) = 0;

    ///
    /// \brief This method wiil be called instead of the basic write function
    /// \sa HookResult, Endpoint, Socket
    /// \param connection Contains the data of the connection (Endpoint and
    /// Socket) \param buffer Contains the data to write in the Socket \return
    /// Result of the hook
    ///
    virtual HookResult doWrite(net::IConnection const &connection,
                               net::Buffer &buffer) = 0;

    ///
    /// \brief This method wiil be called after the write function
    /// \sa HookResult, Endpoint, Socket
    /// \param connection Contains the data of the connection (Endpoint and
    /// Socket) \param buffer Contains the data write by the read function
    /// \return Result of the hook
    ///
    virtual HookResult onWrite(net::IConnection const &connection,
                               net::Buffer &buffer) = 0;

    ///
    /// \brief This method wiil be called before the close function
    /// \sa HookResult, Endpoint, Socket
    /// \param connection Contains the data of the connection (Endpoint and
    /// Socket) \return Result of the hook
    ///
    virtual HookResult onClose(net::IConnection const &connection) = 0;
};

}  // namespace api
}  // namespace zia