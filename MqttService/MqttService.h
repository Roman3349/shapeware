#pragma once

#include "IMqttService.h"
#include "ShapeProperties.h"
#include "ILaunchService.h"
#include "IBufferService.h"
#include "ITraceService.h"
#include <string>

namespace shape {
  class MqttService : public IMqttService
  {
  public:
    MqttService();
    virtual ~MqttService();
    
    void start(const std::string& clientId) override;
    virtual void stop() override;
    virtual bool isReady() const override;

    void registerMessageHandler(MqttMessageHandlerFunc hndl) override;
    void unregisterMessageHandler() override;
    void registerMessageStrHandler(MqttMessageStrHandlerFunc hndl) override;
    void unregisterMessageStrHandler() override;
    void registerOnConnectHandler(MqttOnConnectHandlerFunc hndl) override;
    void unregisterOnConnectHandler() override;
    void registerOnSubscribeHandler(MqttOnSubscribeHandlerFunc hndl) override;
    void unregisterOnSubscribeHandler() override;
    void registerOnDisconnectHandler(MqttOnDisconnectHandlerFunc hndl) override;
    void unregisterOnDisconnectHandler() override;

    void subscribeTopic(const std::string& topic) override;
    void sendMessage(const std::string& topic, const std::vector<uint8_t> & msg) override;
    void sendMessage(const std::string& topic, const std::string & msg) override;

    //////////////
    void activate(const shape::Properties *props = 0);
    void deactivate();
    void modify(const shape::Properties *props);

    void attachInterface(shape::IBufferService* iface);
    void detachInterface(shape::IBufferService* iface);

    void attachInterface(shape::ILaunchService* iface);
    void detachInterface(shape::ILaunchService* iface);

    void attachInterface(shape::ITraceService* iface);
    void detachInterface(shape::ITraceService* iface);

  private:
    class Imp;
    Imp* m_impl;
  };
}
