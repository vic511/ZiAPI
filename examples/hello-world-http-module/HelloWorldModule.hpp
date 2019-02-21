#pragma once

#include "zia/api/IHttpModule.hpp"
#include "zia/api/IModuleDescriptor.hpp"

class HelloWorldModule : public zia::api::IHttpModule {
public:
    HelloWorldModule() = default;

    void loadConfiguration(
            std::unordered_map<std::string, std::string> const &config) override;

    zia::api::HookResult onRequest(zia::http::IRequest &request,
                                   zia::http::IResponse &response) override;

    zia::api::HookResult onProcess(zia::http::IRequest &request,
                                   zia::http::IResponse &response) override;

    zia::api::HookResult onResponse(zia::http::IRequest &request,
                                    zia::http::IResponse &response) override;
};

class HelloWorldModuleDescriptor : public zia::api::IModuleDescriptor {
public:
    HelloWorldModuleDescriptor() = default;

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
        return std::make_unique<HelloWorldModule>();
    }

private:
    static const zia::api::ModuleType _type = zia::api::ModuleType::Http;
    static const std::string _name;
    static const std::vector<zia::api::ConfigKey> _configKey;
};

const std::string HelloWorldModuleDescriptor::_name =
        std::string("hello world");