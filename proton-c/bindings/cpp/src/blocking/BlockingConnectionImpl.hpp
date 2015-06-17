#ifndef PROTON_CPP_CONNECTIONIMPL_H
#define PROTON_CPP_CONNECTIONIMPL_H

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
#include "proton/ImportExport.hpp"
#include "proton/Endpoint.hpp"
#include "proton/Container.hpp"
#include "proton/types.h"
#include <string>

struct pn_connection_t;

namespace proton {
namespace reactor {

class Handler;
class Container;
class SslDomain;

 class BlockingConnectionImpl : public MessagingHandler
{
  public:
    PN_CPP_EXTERN BlockingConnectionImpl(std::string &url, Duration d, SslDomain *ssld, Container *c);
    PN_CPP_EXTERN ~BlockingConnectionImpl();
    PN_CPP_EXTERN void close();
    PN_CPP_EXTERN void wait(WaitCondition &condition);
    PN_CPP_EXTERN void wait(WaitCondition &condition, std::string &msg, Duration timeout);
    PN_CPP_EXTERN pn_connection_t *getPnBlockingConnection();
    Duration getTimeout() { return timeout; }
    static void incref(BlockingConnectionImpl *);
    static void decref(BlockingConnectionImpl *);
  private:
    friend class BlockingConnection;
    Container container;
    Connection connection;
    std::string url;
    Duration timeout;
    int refCount;
};


}} // namespace proton::reactor

#endif  /*!PROTON_CPP_CONNECTIONIMPL_H*/