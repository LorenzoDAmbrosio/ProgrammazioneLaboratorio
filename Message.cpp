//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#include <chrono>
#include "Message.h"

Message::Message(User* sender,const std::string &content)
: sender(sender), content(content){
    sendDate = "undefined";
}

std::string Message::getContent() {
    return content;
}

void Message::setContent(const std::string &c) {
    content=c;
}
User* Message::getSender() {
    return sender;
}

void Message::setSender(User* s) {
    sender=s;
}

std::string Message::toString(bool showHeader) {
    std::string header= ! showHeader ? ""
            : "|M|["+sendDate+"] "+sender->toString();
    return header+"\n| |\t "+content;
}

void Message::prepareToSend() {
    std::time_t tm = std::time(nullptr);
    std::tm* lt = std::localtime(&tm);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%c", lt);
    sendDate= buffer;
}
bool Message::sameSender(Message* other) {
    if(other == nullptr) return false;
    return this->sender->equals(other->getSender());
}