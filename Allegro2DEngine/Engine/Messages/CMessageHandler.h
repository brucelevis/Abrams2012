/**************************************************************************************************
// file:	Engine\Messages\CMessageHandler.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the message handler class
 **************************************************************************************************/
#ifndef A2DE_CMESSAGEHANDLER_H
#define A2DE_CMESSAGEHANDLER_H

#include "../a2de_vals.h"
#include <queue>
#include <list>
#include <set>
#include <functional>

#include "IMessageReceiver.h"
#include "IMessageSender.h"

A2DE_BEGIN

class Message;

class MessageHandler : public IMessageReceiver, public IMessageSender {

public:

    /**************************************************************************************************
     * <summary>Creates the message handler.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <returns>null if it fails, else.</returns>
     **************************************************************************************************/
    static MessageHandler* CreateMessageHandler();

    /**************************************************************************************************
     * <summary>Receive message.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="msg">[in,out] If non-null, the message.</param>
     **************************************************************************************************/
    void ReceiveMessage(Message* msg);

    /**************************************************************************************************
     * <summary>Sends the message.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     **************************************************************************************************/
    void SendMessage();

    /**************************************************************************************************
     * <summary>Peeks a message without removing it from the queue.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <returns>null if it fails, else the message.</returns>
     **************************************************************************************************/
    Message* PeekMessage();

    /**************************************************************************************************
     * <summary>Removes the next message from the queue and returns it.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <returns>null if it fails, else the next message.</returns>
     **************************************************************************************************/
    Message* Next();

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     **************************************************************************************************/
    virtual ~MessageHandler();

    /**************************************************************************************************
     * <summary>Registers the recipient described by recipient.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="recipient">[in,out] If non-null, the recipient.</param>
     **************************************************************************************************/
    void RegisterRecipient(IMessageReceiver* recipient);

    /**************************************************************************************************
     * <summary>Un register recipient.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="recipient">[in,out] If non-null, the recipient.</param>
     **************************************************************************************************/
    void UnRegisterRecipient(IMessageReceiver* recipient);

    /**************************************************************************************************
     * <summary>Gets the size.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <returns>.</returns>
     **************************************************************************************************/
    std::size_t Size();

    /**************************************************************************************************
     * <summary>Query if this object is empty.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <returns>true if empty, false if not.</returns>
     **************************************************************************************************/
    bool IsEmpty();

protected:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     **************************************************************************************************/
    MessageHandler();

    /**************************************************************************************************
     * <summary>Sends a message.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="handler">[in,out] If non-null, the handler.</param>
     * <param name="msg">    [in,out] If non-null, the message.</param>
     **************************************************************************************************/
    void SendMessage(MessageHandler* handler, Message* msg);
private:
    /// <summary> The instance </summary>
    static MessageHandler* _instance;
    /// <summary> Queue of messages </summary>
    std::queue<Message*, std::list<Message*> > _message_queue;
    /// <summary> The message recipients </summary>
    std::set<IMessageReceiver*> _message_recipients;

};

A2DE_END

#endif