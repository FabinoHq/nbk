////////////////////////////////////////////////////////////////////////////////
//              ________           ______________________________________     //
//             // .    /   _______/ . . . . . . . . . . . . . . . . .   /     //
//            // .    /   // . . . .    _______________________________/      //
//           // .     |  //      ______/ \\      |  // .   /_/     __/        //
//          // .      | //    __// .   \_//     /  // .   /     __/           //
//         // .       |//    / // .   _________/  // .       __/              //
//        // .   /|   |/    / // .   /  \\    \  // .        \                //
//       // .   /||        / // .    \__//    / // .   /\     \               //
//      // .   / ||       / //  .            / // .   /  \     \              //
//     //_____/  ||______/  \\______________/ //_____/    \____/              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//   This is free and unencumbered software released into the public domain.  //
//                                                                            //
//   Anyone is free to copy, modify, publish, use, compile, sell, or          //
//   distribute this software, either in source code form or as a compiled    //
//   binary, for any purpose, commercial or non-commercial, and by any        //
//   means.                                                                   //
//                                                                            //
//   In jurisdictions that recognize copyright laws, the author or authors    //
//   of this software dedicate any and all copyright interest in the          //
//   software to the public domain. We make this dedication for the benefit   //
//   of the public at large and to the detriment of our heirs and             //
//   successors. We intend this dedication to be an overt act of              //
//   relinquishment in perpetuity of all present and future rights to this    //
//   software under copyright law.                                            //
//                                                                            //
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          //
//   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       //
//   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   //
//   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR        //
//   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,    //
//   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    //
//   OTHER DEALINGS IN THE SOFTWARE.                                          //
//                                                                            //
//   For more information, please refer to <https://unlicense.org>            //
////////////////////////////////////////////////////////////////////////////////
//    NBK : Network Backend                                                   //
//     Network/Http.h : Http management                                       //
////////////////////////////////////////////////////////////////////////////////
#ifndef NBK_NETWORK_HTTP_HEADER
#define NBK_NETWORK_HTTP_HEADER

    #include "../System/System.h"
    #include "TCPSocket.h"


    ////////////////////////////////////////////////////////////////////////////
    //  HttpMethod enumeration                                                //
    ////////////////////////////////////////////////////////////////////////////
    enum HttpMethod
    {
        HttpConnect = 0,                // Connect mode (TCP tunneling, SSL)
        HttpOptions = 1,                // Options mode (Communication options)
        HttpHead = 2,                   // Head mode (Get header)
        HttpGet = 3,                    // Get mode (Get resource)
        HttpPost = 4,                   // Post mode (Send resource)
        HttpPut = 5,                    // Put mode (Send and replace resource)
        HttpPatch = 6,                  // Patch mode (Partial modifications)
        HttpTrace = 7,                  // Trace mode (Communication test)
        HttpDelete = 8                  // Delete mode (Delete resource)
    };

    ////////////////////////////////////////////////////////////////////////////
    //  HttpStatus enumeration                                                //
    ////////////////////////////////////////////////////////////////////////////
    enum HttpStatus
    {
        HttpContinue = 100,             // Server status is ok
        HttpSwitchingProtocols = 101,   // Server is switching protocol

        HttpOk = 200,                   // Request successfull
        HttpCreated = 201,              // Resource created
        HttpAccepted = 202,             // Request accepted but still processing
        HttpNonAuthoritative = 203,     // Request successfull but altered
        HttpNoContent = 204,            // Request successfull, no update needed
        HttpResetContent = 205,         // Reset content request (clear view)
        HttpPartialContent = 206,       // Partial request successfull
        HttpMultiStatus = 207,          // Potential multiple responses
        HttpAlreadyReported = 208,      // Resource already reported

        HttpMultipleChoices = 300,      // Multiple responses for the request
        HttpMovedPermanently = 301,     // Resource moved permanently
        HttpFound = 302,                // Resource moved temporarily
        HttpSeeOther = 303,             // Redirect to another resource page
        HttpNotModified = 304,          // No update need for resource
        HttpTemporaryRedirect = 307,    // Resource moved temporarily
        HttpPermanentRedirect = 308,    // Resource moved permanently

        HttpBadRequest = 400,           // Invalid request
        HttpUnauthorized = 401,         // Unauthorized request
        HttpPaymentRequired = 402,      // Request need payment before process
        HttpForbidden = 403,            // Forbidden request
        HttpNotFound = 404,             // Resource not found
        HttpMethodNotAllowed = 405,     // Invalid request method
        HttpNotAcceptable = 406,        // Request is not acceptable
        HttpProxyAuthRequired = 407,    // Proxy authentication required
        HttpRequestTimeout = 408,       // Server connection timed out
        HttpConflict = 409,             // Request conflicts with server state
        HttpGone = 410,                 // Resource not found
        HttpLengthRequired = 411,       // Length header required
        HttpPreconditionFailed = 412,   // Access to resource refused
        HttpContentTooLarge = 413,      // Length too large to be handled
        HttpURITooLong = 414,           // URI too long to be handled
        HttpUnsupportedMediaType = 415, // Unsupported resource media type
        HttpRangeNotSatisfiable = 416,  // Content range not available
        HttpExpectationFailed = 417,    // Invalid expect header
        HttpImATeapot = 418,            // Server does not want to answer
        HttpMisdirectedRequest = 421,   // Request is misdirected
        HttpUnprocessableContent = 422, // Request content is not processable
        HttpLocked = 423,               // Content is locked
        HttpFailedDependency = 424,     // Failed dependency request action
        HttpTooEarly = 425,             // Too early to process the request
        HttpUpgradeRequired = 426,      // Server is asking for a client upgrade
        HttpPreconditionRequired = 428, // Request need to be conditional
        HttpTooManyRequests = 429,      // User has sent too many requests
        HttpHeaderTooLarge = 431,       // Request http header fields too large
        HttpUnavailableForLegal = 451,  // Unavailable for legal reasons

        HttpInternalServerError = 500,  // Unexpected server error
        HttpNotImplemented = 501,       // Server does not handle the request
        HttpBadGateway = 502,           // Invalid upstream response
        HttpServiceUnavailable = 503,   // Server is not ready to respond
        HttpGatewayTimeout = 504,       // Upstream response timed out
        HttpVersionNotSupported = 505,  // Http version not supported
        HttpVariantNegotiates = 506,    // Internal server configuration error
        HttpInsufficientStorage = 507,  // Insufficient server storage
        HttpLoopDetected = 508,         // Server encountered an infinite loop
        HttpNotExtended = 510,          // Extension not supported
        HttpNetworkAuthRequired = 511   // Client needs to authenticate
    };


    ////////////////////////////////////////////////////////////////////////////
    //  Http class definition                                                 //
    ////////////////////////////////////////////////////////////////////////////
    class Http
    {
        public:
            ////////////////////////////////////////////////////////////////////
            //  Http default constructor                                      //
            ////////////////////////////////////////////////////////////////////
            Http();

            ////////////////////////////////////////////////////////////////////
            //  Http destructor                                               //
            ////////////////////////////////////////////////////////////////////
            ~Http();


        private:
            ////////////////////////////////////////////////////////////////////
            //  Http private copy constructor : Not copyable                  //
            ////////////////////////////////////////////////////////////////////
            Http(const Http&) = delete;

            ////////////////////////////////////////////////////////////////////
            //  Http private copy operator : Not copyable                     //
            ////////////////////////////////////////////////////////////////////
            Http& operator=(const Http&) = delete;


        private:
            TCPSocket               m_socket;               // Http socket
    };


#endif // NBK_NETWORK_HTTP_HEADER
