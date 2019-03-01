#include <arpa/inet.h>
#include <netinet/in.h>
#include "IpWhiteListModule.hpp"
#include "zia/api/ConfigurationError.hpp"

IpWhiteListModule::IpWhiteListModule() : _ipList() {}

void IpWhiteListModule::loadConfiguration(
    std::unordered_map<std::string, std::string> const &config)
{
    _ipList = parseIpList(config.at("WhiteListedIps"));
}

zia::api::HookResult IpWhiteListModule::onAccept(
    const zia::net::Connection &connection)
{
    for (auto const &addr : _ipList) {
        if (connection.endpoint.address == addr) {
            return zia::api::HookResult::Ok;
        }
    }
    return zia::api::HookResult::Abort;
}

zia::api::HookResult IpWhiteListModule::doRead(const zia::net::Connection &,
                                               zia::net::Buffer &)
{
    return zia::api::HookResult::Declined;
}

zia::api::HookResult IpWhiteListModule::onRead(const zia::net::Connection &,
                                               zia::net::Buffer &)
{
    return zia::api::HookResult::Declined;
}

zia::api::HookResult IpWhiteListModule::doWrite(const zia::net::Connection &,
                                                zia::net::Buffer &)
{
    return zia::api::HookResult::Declined;
}

zia::api::HookResult IpWhiteListModule::onWrite(const zia::net::Connection &,
                                                zia::net::Buffer &)
{
    return zia::api::HookResult::Declined;
}

zia::api::HookResult IpWhiteListModule::onClose(const zia::net::Connection &)
{
    return zia::api::HookResult::Declined;
}

std::vector<zia::net::Address> IpWhiteListModule::parseIpList(
    std::string const &ipList)
{
    std::size_t it = 0;
    std::string substr;
    std::string cpy(ipList);
    std::vector<std::uint32_t> vec;
    in_addr addr;

    while (it < cpy.length()) {
        substr = cpy.substr(it, cpy.find(','));
        cpy = cpy.substr(it);
        it = cpy.find(',') + 1;
        if (it == 0) {
            it = cpy.length();
        }
        if (inet_aton(substr.c_str(), &addr) == 0) {
            throw zia::api::ConfigurationError(
                "IpWhiteListModule : error in ip list");
        }
        vec.push_back(ntohl(addr.s_addr));
    }
    return vec;
}

const std::string IpWhiteListModuleDescriptor::_name =
    std::string("IpWhiteList");

const std::vector<zia::api::ConfigKey> IpWhiteListModuleDescriptor::_configKey =
    {};

extern "C" {
IpWhiteListModuleDescriptor descriptor;
}
