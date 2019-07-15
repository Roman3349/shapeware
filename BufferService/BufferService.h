/**
* Copyright 2018 Logimic,s.r.o.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#pragma once

#include "IBufferService.h"
#include "ILaunchService.h"
#include "ShapeProperties.h"
#include "ITraceService.h"

namespace shape {
  class BufferService : public IBufferService
  {
  public:
    BufferService();
    virtual ~BufferService();

    void registerProcessFunc(IBufferService::ProcessFunc func) override;
    void unregisterProcessFunc() override;
    void start() override;
    void stop() override;

    bool empty() override;
    std::size_t size() const override;
    Record front() const override;
    Record back() const override;
    void push(const Record & rec) override;
    void pop() override;
    void load() override;
    void save() override;

    void activate(const shape::Properties *props = 0);
    void deactivate();
    void modify(const shape::Properties *props);

    void attachInterface(ILaunchService* iface);
    void detachInterface(ILaunchService* iface);

    void attachInterface(shape::ITraceService* iface);
    void detachInterface(shape::ITraceService* iface);

  private:
    class Imp;
    Imp* m_imp;
  };
}
