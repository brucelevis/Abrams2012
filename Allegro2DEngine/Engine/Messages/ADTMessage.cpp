/**************************************************************************************************
// file:	Engine\Messages\ADTMessage.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the adt message class
 **************************************************************************************************/
#include "ADTMessage.h"

A2DE_BEGIN

unsigned long Message::_current_index = 0;

Message::Message(StopWatch& gameTime) :
_message_index(++_current_index),
_creation_time(gameTime.GetElapsedTimeInMilliseconds()) { /* DO NOTHING */ }

Message::~Message() { /* DO NOTHING */ }

bool Message::operator<(const Message& rhs) {
    return this->_creation_time < rhs._creation_time;
}

bool Message::operator>(const Message& rhs) {
    return this->_creation_time > rhs._creation_time;
}

bool Message::operator>=(const Message& rhs) {
    return !(this->_creation_time < rhs._creation_time);
}

bool Message::operator<=(const Message& rhs) {
    return !(this->_creation_time > rhs._creation_time);
}

bool Message::operator==(const Message& rhs) {
    return this->_creation_time == rhs._creation_time;
}

bool Message::operator!=(const Message& rhs) {
    return !(this->_creation_time == rhs._creation_time);
}

unsigned long Message::GetMessageIndex() const {
    return _message_index;
}

unsigned long Message::GetMessageIndex() {
    return static_cast<const Message&>(*this).GetMessageIndex();
}

double Message::GetCreationTime() const {
    return _creation_time;
}

double Message::GetCreationTime() {
    return static_cast<const Message&>(*this).GetCreationTime();
}



A2DE_END