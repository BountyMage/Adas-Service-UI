/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_ADAS__Syst_Status__Service_STUB_DEFAULT_HPP_
#define V1_COMMONAPI_ADAS__Syst_Status__Service_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v1/commonapi/ADAS_SystStatus_ServiceStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v1 {
namespace commonapi {

/**
 * Provides a default implementation for ADAS_SystStatus_ServiceStubRemoteEvent and
 * ADAS_SystStatus_ServiceStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT ADAS_SystStatus_ServiceStubDefault
    : public virtual ADAS_SystStatus_ServiceStub {
public:
    COMMONAPI_EXPORT ADAS_SystStatus_ServiceStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(ADAS_SystStatus_Service::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT ADAS_SystStatus_ServiceStubRemoteEvent* initStubAdapter(const std::shared_ptr< ADAS_SystStatus_ServiceStubAdapter> &_adapter) {
        CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual const ::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct &getADAS_SystStatusAttribute() {
        return aDAS_SystStatusAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const ::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct &getADAS_SystStatusAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getADAS_SystStatusAttribute();
    }
    COMMONAPI_EXPORT virtual void setADAS_SystStatusAttribute(::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct _value) {
        const bool valueChanged = trySetADAS_SystStatusAttribute(std::move(_value));
        if (valueChanged) {
            fireADAS_SystStatusAttributeChanged(aDAS_SystStatusAttributeValue_);
        }
    }


protected:
    COMMONAPI_EXPORT virtual bool trySetADAS_SystStatusAttribute(::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct _value) {
        if (!validateADAS_SystStatusAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<ADAS_SystStatus_ServiceStubAdapter> stubAdapter = CommonAPI::Stub<ADAS_SystStatus_ServiceStubAdapter, ADAS_SystStatus_ServiceStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockADAS_SystStatusAttribute(true);
            valueChanged = (aDAS_SystStatusAttributeValue_ != _value);
            aDAS_SystStatusAttributeValue_ = std::move(_value);
            stubAdapter->lockADAS_SystStatusAttribute(false);
        } else {
            valueChanged = (aDAS_SystStatusAttributeValue_ != _value);
            aDAS_SystStatusAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateADAS_SystStatusAttributeRequestedValue(const ::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct &_value) {
        (void)_value;
        return true;
    }
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual ADAS_SystStatus_ServiceStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(ADAS_SystStatus_ServiceStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }


    private:
        ADAS_SystStatus_ServiceStubDefault *defaultStub_;
    };
protected:
    ADAS_SystStatus_ServiceStubDefault::RemoteEventHandler remoteEventHandler_;

private:

    ::v1::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct aDAS_SystStatusAttributeValue_ {};

    CommonAPI::Version interfaceVersion_;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_ADAS__Syst_Status__Service_STUB_DEFAULT