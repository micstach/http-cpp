//
// The MIT License (MIT)
//
// Copyright (c) 2013-2014 by Konstantin (Kosta) Baumann & Autodesk Inc.
//
// Permission is hereby granted, free of charge,  to any person obtaining a copy of
// this software and  associated documentation  files  (the "Software"), to deal in
// the  Software  without  restriction,  including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software,  and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this  permission notice  shall be included in all
// copies or substantial portions of the Software.
//
// THE  SOFTWARE  IS  PROVIDED  "AS IS",  WITHOUT  WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE  AND NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE  LIABLE FOR ANY CLAIM,  DAMAGES OR OTHER LIABILITY, WHETHER
// IN  AN  ACTION  OF  CONTRACT,  TORT  OR  OTHERWISE,  ARISING  FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include "status.hpp"

bool http::status_is_known(http::status s) {
    switch(s) {
#define HTTP_STATUS_CASE(X) case X: return true
        HTTP_STATUS_CASE(HTTP_000_UNKNOWN);

        HTTP_STATUS_CASE(HTTP_100_CONTINUE);
        HTTP_STATUS_CASE(HTTP_101_SWITCHING_PROTOCOLS);
        HTTP_STATUS_CASE(HTTP_102_PROCESSING);

        HTTP_STATUS_CASE(HTTP_200_OK);
        HTTP_STATUS_CASE(HTTP_201_CREATED);
        HTTP_STATUS_CASE(HTTP_202_ACCEPTED);
        HTTP_STATUS_CASE(HTTP_203_NON_AUTHORITATIVE_INFORMATION);
        HTTP_STATUS_CASE(HTTP_204_NO_CONTENT);
        HTTP_STATUS_CASE(HTTP_205_RESET_CONTENT);
        HTTP_STATUS_CASE(HTTP_206_PARTIAL_CONTENT);
        HTTP_STATUS_CASE(HTTP_207_MULTI_STATUS);
        HTTP_STATUS_CASE(HTTP_208_ALREADY_REOPENED);
        HTTP_STATUS_CASE(HTTP_226_IM_USED);

        HTTP_STATUS_CASE(HTTP_300_MULTIPLE_CHOICES);
        HTTP_STATUS_CASE(HTTP_301_MOVED_PERMANENTLY);
        HTTP_STATUS_CASE(HTTP_302_FOUND);
        HTTP_STATUS_CASE(HTTP_303_SEE_OTHER);
        HTTP_STATUS_CASE(HTTP_304_NOT_MODIFIED);
        HTTP_STATUS_CASE(HTTP_305_USE_PROXY);
        HTTP_STATUS_CASE(HTTP_306_SWITCH_PROXY);
        HTTP_STATUS_CASE(HTTP_307_TEMPORARY_REDIRECT);
        HTTP_STATUS_CASE(HTTP_308_PERMANENT_REDIRECT);

        HTTP_STATUS_CASE(HTTP_400_BAD_REQUEST);
        HTTP_STATUS_CASE(HTTP_401_UNAUTHORIZED);
        HTTP_STATUS_CASE(HTTP_402_PAYMENT_REQUIRED);
        HTTP_STATUS_CASE(HTTP_403_FORBIDDEN);
        HTTP_STATUS_CASE(HTTP_404_NOT_FOUND);
        HTTP_STATUS_CASE(HTTP_405_METHOD_NOT_ALLOWED);
        HTTP_STATUS_CASE(HTTP_406_NOT_ACCECPTABLE);
        HTTP_STATUS_CASE(HTTP_407_PROXY_AUTHENTICATION_REQUIRED);
        HTTP_STATUS_CASE(HTTP_408_REQUEST_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_409_CONFLICT);
        HTTP_STATUS_CASE(HTTP_410_GONE);
        HTTP_STATUS_CASE(HTTP_411_LENGTH_REQUIRED);
        HTTP_STATUS_CASE(HTTP_412_PRECONDITION_FAILED);
        HTTP_STATUS_CASE(HTTP_413_REQUEST_ENTITY_TOO_LARGE);
        HTTP_STATUS_CASE(HTTP_414_REQUEST_URI_TOO_LONG);
        HTTP_STATUS_CASE(HTTP_415_UNSUPPORTED_MEDIA_TYPE);
        HTTP_STATUS_CASE(HTTP_416_REQUEST_RANGE_NOT_SATISFIABLE);
        HTTP_STATUS_CASE(HTTP_417_EXPECTATION_FAILED);
        HTTP_STATUS_CASE(HTTP_418_I_AM_A_TEAPOT);
        HTTP_STATUS_CASE(HTTP_419_AUTHENTICATION_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_420_METHOD_FAILURE);
        // HTTP_STATUS_CASE(HTTP_420_ENHANCE_YOUR_CALM);
        HTTP_STATUS_CASE(HTTP_422_UNPROCESSABLE_ENTITY);
        HTTP_STATUS_CASE(HTTP_423_LOCKED);
        HTTP_STATUS_CASE(HTTP_424_FAILED_DEPENDENCY);
        HTTP_STATUS_CASE(HTTP_425_UNORDERED_COLLECTION);
        HTTP_STATUS_CASE(HTTP_426_UPGRADE_REQUIRED);
        HTTP_STATUS_CASE(HTTP_428_PRECONDITION_REQUIRED);
        HTTP_STATUS_CASE(HTTP_429_TOO_MANY_REQUESTS);
        HTTP_STATUS_CASE(HTTP_431_REQUEST_HEADER_FIELDS_TOO_LARGE);
        HTTP_STATUS_CASE(HTTP_440_LOGIN_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_444_NO_RESPONSE);
        HTTP_STATUS_CASE(HTTP_449_RETRY_WITH);
        HTTP_STATUS_CASE(HTTP_450_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS);
        //HTTP_STATUS_CASE(HTTP_451_UNAVAILABLE_FOR_LEGAL_REASONS);
        HTTP_STATUS_CASE(HTTP_451_REDIRECTED);
        HTTP_STATUS_CASE(HTTP_494_REQUEST_HEADER_TOO_LARGE);
        HTTP_STATUS_CASE(HTTP_495_CERT_ERROR);
        HTTP_STATUS_CASE(HTTP_496_NO_CERT);
        HTTP_STATUS_CASE(HTTP_497_HTTP_TO_HTTPS);
        HTTP_STATUS_CASE(HTTP_499_CLIENT_CLOSED_REQUEST);

        HTTP_STATUS_CASE(HTTP_500_INTERNAL_SERVER_ERROR);
        HTTP_STATUS_CASE(HTTP_501_NOT_IMPLEMENTED);
        HTTP_STATUS_CASE(HTTP_502_BAD_GATEWAY);
        HTTP_STATUS_CASE(HTTP_503_SERVICE_UNAVAILABLE);
        HTTP_STATUS_CASE(HTTP_504_GATEWAY_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_505_HTTP_VERSION_NOT_SUPPORTED);
        HTTP_STATUS_CASE(HTTP_506_VARIANT_ALSO_NEGOTIATES);
        HTTP_STATUS_CASE(HTTP_507_INSUFFICIENT_STORAGE);
        HTTP_STATUS_CASE(HTTP_508_LOOP_DETECTED);
        HTTP_STATUS_CASE(HTTP_509_BANDWIDTH_LIMIT_EXCEEDED);
        HTTP_STATUS_CASE(HTTP_510_NOT_EXTENDED);
        HTTP_STATUS_CASE(HTTP_511_NETWORK_AUTHENTICATION_REQUIRED);
        HTTP_STATUS_CASE(HTTP_520_ORIGIN_ERROR);
        HTTP_STATUS_CASE(HTTP_522_CONNECTION_TIMED_OUT);
        HTTP_STATUS_CASE(HTTP_523_PROXY_DECLINED_REQUEST);
        HTTP_STATUS_CASE(HTTP_524_TIMEOUT_OCCURRED);
        HTTP_STATUS_CASE(HTTP_598_NETWORK_READ_TIMEOUT_ERROR);
        HTTP_STATUS_CASE(HTTP_599_NETWORK_CONNECT_TIMEOUT_ERROR);
#undef  HTTP_STATUS_CASE
        default: return false;
    }
}
const char* http::status_to_string(http::status s) {
    switch(s) {
#define HTTP_STATUS_CASE(X) case X: return #X
        HTTP_STATUS_CASE(HTTP_000_UNKNOWN);

        HTTP_STATUS_CASE(HTTP_100_CONTINUE);
        HTTP_STATUS_CASE(HTTP_101_SWITCHING_PROTOCOLS);
        HTTP_STATUS_CASE(HTTP_102_PROCESSING);

        HTTP_STATUS_CASE(HTTP_200_OK);
        HTTP_STATUS_CASE(HTTP_201_CREATED);
        HTTP_STATUS_CASE(HTTP_202_ACCEPTED);
        HTTP_STATUS_CASE(HTTP_203_NON_AUTHORITATIVE_INFORMATION);
        HTTP_STATUS_CASE(HTTP_204_NO_CONTENT);
        HTTP_STATUS_CASE(HTTP_205_RESET_CONTENT);
        HTTP_STATUS_CASE(HTTP_206_PARTIAL_CONTENT);
        HTTP_STATUS_CASE(HTTP_207_MULTI_STATUS);
        HTTP_STATUS_CASE(HTTP_208_ALREADY_REOPENED);
        HTTP_STATUS_CASE(HTTP_226_IM_USED);

        HTTP_STATUS_CASE(HTTP_300_MULTIPLE_CHOICES);
        HTTP_STATUS_CASE(HTTP_301_MOVED_PERMANENTLY);
        HTTP_STATUS_CASE(HTTP_302_FOUND);
        HTTP_STATUS_CASE(HTTP_303_SEE_OTHER);
        HTTP_STATUS_CASE(HTTP_304_NOT_MODIFIED);
        HTTP_STATUS_CASE(HTTP_305_USE_PROXY);
        HTTP_STATUS_CASE(HTTP_306_SWITCH_PROXY);
        HTTP_STATUS_CASE(HTTP_307_TEMPORARY_REDIRECT);
        HTTP_STATUS_CASE(HTTP_308_PERMANENT_REDIRECT);

        HTTP_STATUS_CASE(HTTP_400_BAD_REQUEST);
        HTTP_STATUS_CASE(HTTP_401_UNAUTHORIZED);
        HTTP_STATUS_CASE(HTTP_402_PAYMENT_REQUIRED);
        HTTP_STATUS_CASE(HTTP_403_FORBIDDEN);
        HTTP_STATUS_CASE(HTTP_404_NOT_FOUND);
        HTTP_STATUS_CASE(HTTP_405_METHOD_NOT_ALLOWED);
        HTTP_STATUS_CASE(HTTP_406_NOT_ACCECPTABLE);
        HTTP_STATUS_CASE(HTTP_407_PROXY_AUTHENTICATION_REQUIRED);
        HTTP_STATUS_CASE(HTTP_408_REQUEST_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_409_CONFLICT);
        HTTP_STATUS_CASE(HTTP_410_GONE);
        HTTP_STATUS_CASE(HTTP_411_LENGTH_REQUIRED);
        HTTP_STATUS_CASE(HTTP_412_PRECONDITION_FAILED);
        HTTP_STATUS_CASE(HTTP_413_REQUEST_ENTITY_TOO_LARGE);
        HTTP_STATUS_CASE(HTTP_414_REQUEST_URI_TOO_LONG);
        HTTP_STATUS_CASE(HTTP_415_UNSUPPORTED_MEDIA_TYPE);
        HTTP_STATUS_CASE(HTTP_416_REQUEST_RANGE_NOT_SATISFIABLE);
        HTTP_STATUS_CASE(HTTP_417_EXPECTATION_FAILED);
        HTTP_STATUS_CASE(HTTP_418_I_AM_A_TEAPOT);
        HTTP_STATUS_CASE(HTTP_419_AUTHENTICATION_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_420_METHOD_FAILURE);
        // HTTP_STATUS_CASE(HTTP_420_ENHANCE_YOUR_CALM);
        HTTP_STATUS_CASE(HTTP_422_UNPROCESSABLE_ENTITY);
        HTTP_STATUS_CASE(HTTP_423_LOCKED);
        HTTP_STATUS_CASE(HTTP_424_FAILED_DEPENDENCY);
        HTTP_STATUS_CASE(HTTP_425_UNORDERED_COLLECTION);
        HTTP_STATUS_CASE(HTTP_426_UPGRADE_REQUIRED);
        HTTP_STATUS_CASE(HTTP_428_PRECONDITION_REQUIRED);
        HTTP_STATUS_CASE(HTTP_429_TOO_MANY_REQUESTS);
        HTTP_STATUS_CASE(HTTP_431_REQUEST_HEADER_FIELDS_TOO_LARGE);
        HTTP_STATUS_CASE(HTTP_440_LOGIN_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_444_NO_RESPONSE);
        HTTP_STATUS_CASE(HTTP_449_RETRY_WITH);
        HTTP_STATUS_CASE(HTTP_450_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS);
        //HTTP_STATUS_CASE(HTTP_451_UNAVAILABLE_FOR_LEGAL_REASONS);
        HTTP_STATUS_CASE(HTTP_451_REDIRECTED);
        HTTP_STATUS_CASE(HTTP_494_REQUEST_HEADER_TOO_LARGE);
        HTTP_STATUS_CASE(HTTP_495_CERT_ERROR);
        HTTP_STATUS_CASE(HTTP_496_NO_CERT);
        HTTP_STATUS_CASE(HTTP_497_HTTP_TO_HTTPS);
        HTTP_STATUS_CASE(HTTP_499_CLIENT_CLOSED_REQUEST);

        HTTP_STATUS_CASE(HTTP_500_INTERNAL_SERVER_ERROR);
        HTTP_STATUS_CASE(HTTP_501_NOT_IMPLEMENTED);
        HTTP_STATUS_CASE(HTTP_502_BAD_GATEWAY);
        HTTP_STATUS_CASE(HTTP_503_SERVICE_UNAVAILABLE);
        HTTP_STATUS_CASE(HTTP_504_GATEWAY_TIMEOUT);
        HTTP_STATUS_CASE(HTTP_505_HTTP_VERSION_NOT_SUPPORTED);
        HTTP_STATUS_CASE(HTTP_506_VARIANT_ALSO_NEGOTIATES);
        HTTP_STATUS_CASE(HTTP_507_INSUFFICIENT_STORAGE);
        HTTP_STATUS_CASE(HTTP_508_LOOP_DETECTED);
        HTTP_STATUS_CASE(HTTP_509_BANDWIDTH_LIMIT_EXCEEDED);
        HTTP_STATUS_CASE(HTTP_510_NOT_EXTENDED);
        HTTP_STATUS_CASE(HTTP_511_NETWORK_AUTHENTICATION_REQUIRED);
        HTTP_STATUS_CASE(HTTP_520_ORIGIN_ERROR);
        HTTP_STATUS_CASE(HTTP_522_CONNECTION_TIMED_OUT);
        HTTP_STATUS_CASE(HTTP_523_PROXY_DECLINED_REQUEST);
        HTTP_STATUS_CASE(HTTP_524_TIMEOUT_OCCURRED);
        HTTP_STATUS_CASE(HTTP_598_NETWORK_READ_TIMEOUT_ERROR);
        HTTP_STATUS_CASE(HTTP_599_NETWORK_CONNECT_TIMEOUT_ERROR);
#undef  HTTP_STATUS_CASE
        default: return "unknown HTTP status code";
    }
}
