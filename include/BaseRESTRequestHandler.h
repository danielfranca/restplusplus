//
// Created by Daniel Franca on 9/20/16.
//

#ifndef REST_BASERESTREQUESTHANDLER_H
#define REST_BASERESTREQUESTHANDLER_H

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/JSON/Object.h"

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::JSON::Object;

#include <unordered_map>
#include <functional>


class BaseRESTRequestHandler: public HTTPRequestHandler {

public:
    virtual void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
    virtual Object::Ptr get(HTTPServerRequest& request, HTTPServerResponse& response);
    virtual Object::Ptr post(HTTPServerRequest& request, HTTPServerResponse& response);
    virtual Object::Ptr put(HTTPServerRequest& request, HTTPServerResponse& response);
    virtual Object::Ptr del(HTTPServerRequest& request, HTTPServerResponse& response);
};


class Controller {
public:

    template<typename T>
    T* operator()() {
        return new T;
    }
};

using RouteMap = std::unordered_map<std::string, std::function<BaseRESTRequestHandler*()> >;

template <typename T>
auto handler() {
    return [](){return new T;};
}

#endif //REST_BASERESTREQUESTHANDLER_H
