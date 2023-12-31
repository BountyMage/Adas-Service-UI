/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/ADAS_SystStatus_ServiceSomeIPStubAdapter.hpp>
#include <v1/commonapi/ADAS_SystStatus_Service.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::StubAdapter> createADAS_SystStatus_ServiceSomeIPStubAdapter(
                   const CommonAPI::SomeIP::Address &_address,
                   const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    return std::make_shared< ADAS_SystStatus_ServiceSomeIPStubAdapter<::v1::commonapi::ADAS_SystStatus_ServiceStub>>(_address, _connection, _stub);
}

void initializeADAS_SystStatus_ServiceSomeIPStubAdapter() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.ADAS_SystStatus_Service:v1_0:commonapi.ADAS_SystStatus_Service",
         0x3331, 0x1, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerStubAdapterCreateMethod(
        "commonapi.ADAS_SystStatus_Service:v1_0",
        &createADAS_SystStatus_ServiceSomeIPStubAdapter);
}

INITIALIZER(registerADAS_SystStatus_ServiceSomeIPStubAdapter) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeADAS_SystStatus_ServiceSomeIPStubAdapter);
}

} // namespace commonapi
} // namespace v1
