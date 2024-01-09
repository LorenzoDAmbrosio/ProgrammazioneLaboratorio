//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#include <chrono>
#include "Message.h"

Message::Message(User* sender,const std::string &content)
: sender(sender), content(content){
    sendDate = "undefined";
}

std::string Message::getContent() const{
    return content;
}

void Message::setContent(const std::string &c){
    content=c;
}
User* Message::getSender() const{
    return sender;
}

void Message::setSender(User* s){
    sender=s;
}


bool Message::getWasRead() const {
    return getWasRead();
}

void Message::setAsRead() {
    WasRead=true;
}

std::string Message::toString(bool showHeader) const{
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
// mettere const
bool Message::sameSender(Message* other) const{
    if(other == nullptr) return false;
    return this->sender->equals(other->getSender());
}