#include "HelloWorldModule.hpp"

void HelloWorldModule::loadConfiguration(
    std::unordered_map<std::string, std::string> const &config)
{
    // If your module needs configuration
}

zia::api::HookResult HelloWorldModule::onRequest(zia::http::IRequest &request,
                                                 zia::http::IResponse &response)
{
    return zia::api::HookResult::Declined;
}

zia::api::HookResult HelloWorldModule::onProcess(zia::http::IRequest &request,
                                                 zia::http::IResponse &response)
{
    zia::http::Buffer buff("Hello world");

    response.setBody(buff);
    return zia::api::HookResult::Ok;
}

zia::api::HookResult HelloWorldModule::onResponse(
    zia::http::IRequest &request, zia::http::IResponse &response)
{
    //
    return zia::api::HookResult::Declined;
}

extern "C" {
HelloWorldModuleDescriptor descriptor;
}

const std::string HelloWorldModuleDescriptor::_name =
        std::string("HelloWorld");