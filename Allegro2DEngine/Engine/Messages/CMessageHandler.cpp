/**************************************************************************************************
// file:	Engine\Messages\CMessageHandler.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the message handler class
 **************************************************************************************************/
#include "CMessageHandler.h"

#include "ADTMessage.h"

A2DE_BEGIN

MessageHandler* MessageHandler::_instance = nullptr;

typedef std::set<IMessageReceiver*> Entities;
typedef Entities::iterator EntitiesIter;

void MessageHandler::SendMessage() {
    if(_message_queue.empty()) return;
    std::for_each(_message_recipients.begin(), _message_recipients.end(), std::bind2nd(std::mem_fun1<void, IMessageReceiver, Message*>(&IMessageReceiver::ReceiveMessage), _message_queue.front()));
    _message_queue.pop();
}

void MessageHandler::ReceiveMessage(Message* msg) {
    _message_queue.push(msg);
}

Message* MessageHandler::PeekMessage() {
    Message* n_msg = _message_queue.empty() ? nullptr : _message_queue.front();
    return n_msg;
}

Message* MessageHandler::Next() {
    Message* n_msg = nullptr;
    if(_message_queue.empty() == false) {
        n_msg = _message_queue.front();
        _message_queue.pop();
    }
    return n_msg;
}

MessageHandler::MessageHandler() :
_message_recipients(),
_message_queue() { }

MessageHandler* MessageHandler::CreateMessageHandler() {
    if(_instance) return _instance;
    _instance = new MessageHandler();
    return _instance;
}

MessageHandler::~MessageHandler() {
    _instance = nullptr;
    _message_recipients.clear();
    while(_message_queue.empty() == false) {
        delete _message_queue.front();
        _message_queue.pop();
    }
}

void MessageHandler::RegisterRecipient(IMessageReceiver* recipient) {
    _message_recipients.insert(recipient);
}

void MessageHandler::UnRegisterRecipient(IMessageReceiver* recipient) {
    EntitiesIter _iter = _message_recipients.find(recipient);
    if(_iter == _message_recipients.end()) return;
    _message_recipients.erase(_iter);
}

void MessageHandler::SendMessage(MessageHandler* /*handler*/, Message* /*msg*/) { /* DO NOTHING */ }

std::size_t MessageHandler::Size() {
    return _message_queue.size();
}

bool MessageHandler::IsEmpty() {
    return _message_queue.empty();
}


A2DE_END