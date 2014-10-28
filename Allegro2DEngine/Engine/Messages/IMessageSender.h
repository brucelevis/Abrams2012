/**************************************************************************************************
// file:	Engine\Messages\IMessageSender.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the IMessageSender interface
 **************************************************************************************************/
#ifndef A2DE_IMESSAGESENDER_H
#define A2DE_IMESSAGESENDER_H

#include "../a2de_vals.h"

A2DE_BEGIN

class Message;
class MessageHandler;

class IMessageSender {
public:

    /**************************************************************************************************
     * <summary>Sends a message.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="handler">[in,out] If non-null, the handler.</param>
     * <param name="msg">    [in,out] If non-null, the message.</param>
     **************************************************************************************************/
    virtual void SendMessage(MessageHandler* handler, Message* msg) = 0;
    virtual ~IMessageSender() { /* DO NOTHING */ }
};

A2DE_END

#endif