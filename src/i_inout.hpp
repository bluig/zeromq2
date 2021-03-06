/*
    Copyright (c) 2007-2010 iMatix Corporation

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the Lesser GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Lesser GNU General Public License for more details.

    You should have received a copy of the Lesser GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_I_INOUT_HPP_INCLUDED__
#define __ZMQ_I_INOUT_HPP_INCLUDED__

#include "../include/zmq.h"

#include "stdint.hpp"

namespace zmq
{

    struct i_inout
    {
        virtual ~i_inout () {}

        //  Engine asks to get a message to send to the network.
        virtual bool read (::zmq_msg_t *msg_) = 0;

        //  Engine sends the incoming message further on downstream.
        virtual bool write (::zmq_msg_t *msg_) = 0;

        //  Flush all the previously written messages downstream.
        virtual void flush () = 0;
    
        //  Drop all the references to the engine. The parameter is the object
        //  to use to reconnect. If reconnection is not required, the argument
        //  is set to NULL.
        virtual void detach (class owned_t *reconnecter_) = 0;

        //  Returns least loaded I/O thread.
        virtual class io_thread_t *get_io_thread () = 0;

        //  Return pointer to the owning socket.
        virtual class socket_base_t *get_owner () = 0;

        //  Return ordinal number of the session.
        virtual uint64_t get_ordinal () = 0;
    };

}

#endif
