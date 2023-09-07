/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_ADAS__Syst_Status__Service_STUB_HPP_
#define V1_COMMONAPI_ADAS__Syst_Status__Service_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/commonapi/ADAS_SystStatus_Service.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <cstdint>

#include <mutex>

#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service ADAS_SystStatus_Service. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class ADAS_SystStatus_ServiceStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual ADAS_SystStatus_Service {
 public:
    ///Notifies all remote listeners about a change of value of the attribute ADAS_SystStatus.
    virtual void fireADAS_SystStatusAttributeChanged(const ::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct &ADAS_SystStatus) = 0;


    virtual void deactivateManagedInstances() = 0;

    void lockADAS_SystStatusAttribute(bool _lockAccess) {
        if (_lockAccess) {
            aDAS_SystStatusMutex_.lock();
        } else {
            aDAS_SystStatusMutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
    std::recursive_mutex aDAS_SystStatusMutex_;

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for ADAS_SystStatus_Service.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class ADAS_SystStatus_ServiceStubRemoteEvent
{
public:
    virtual ~ADAS_SystStatus_ServiceStubRemoteEvent() { }

};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service ADAS_SystStatus_Service to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class ADAS_SystStatus_ServiceStub
    : public virtual CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>
{
public:

    virtual ~ADAS_SystStatus_ServiceStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 1);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// Provides getter access to the attribute ADAS_SystStatus
    virtual const ::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct &getADAS_SystStatusAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireADAS_SystStatusAttributeChanged(::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct _value) {
    auto stubAdapter = CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireADAS_SystStatusAttributeChanged(_value);
    }
    void lockADAS_SystStatusAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockADAS_SystStatusAttribute(_lockAccess);
    }


    using CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef ADAS_SystStatus_ServiceStubRemoteEvent RemoteEventType;
    typedef ADAS_SystStatus_Service StubInterface;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_ADAS__Syst_Status__Service_STUB_HPP_