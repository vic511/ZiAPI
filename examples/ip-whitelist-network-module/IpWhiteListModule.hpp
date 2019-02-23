#pragma once

#include "zia/api/IModuleDescriptor.hpp"
#include "zia/api/INetworkModule.hpp"
#include "zia/net/Address.hpp"

class IpWhiteListModule : public zia::api::INetworkModule {
public:
    IpWhiteListModule() = default;

    zia::api::HookResult onAccept(
        const zia::net::IConnection &connection) override;

    zia::api::HookResult doRead(const zia::net::IConnection &connection,
                                zia::net::Buffer &buffer) override;

    zia::api::HookResult onRead(const zia::net::IConnection &connection,
                                zia::net::Buffer &buffer) override;

    zia::api::HookResult doWrite(const zia::net::IConnection &connection,
                                 zia::net::Buffer &buffer) override;

    zia::api::HookResult onWrite(const zia::net::IConnection &connection,
                                 zia::net::Buffer &buffer) override;

    zia::api::HookResult onClose(
        const zia::net::IConnection &connection) override;

    void loadConfiguration(
        std::unordered_map<std::string, std::string> const &config) override;

private:
    std::vector<zia::net::Address> parseIpList(std::string const &ipList);

private:
    std::vector<zia::net::Address> _ipList;
};

class IpWhiteListModuleDescriptor : public zia::api::IModuleDescriptor {
public:
    IpWhiteListModuleDescriptor() = default;

    zia::api::ModuleType getType() const override
    {
        return _type;
    }

    const std::string &getName() const override
    {
        return _name;
    }

    const std::vector<zia::api::ConfigKey> &getConfigKeys() const override
    {
        return _configKey;
    }

    std::unique_ptr<zia::api::IModule> create() override
    {
        return std::make_unique<IpWhiteListModule>();
    }

private:
    static const zia::api::ModuleType _type = zia::api::ModuleType::Network;
    static const std::string _name;
    static const std::vector<zia::api::ConfigKey> _configKey;
};
