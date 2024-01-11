//
// Created by Lorenzo D'Ambrosio il 20/09/2023.
//

#include <iostream>
#include "Chat.h"

// Costruttore della classe Chat
Chat::Chat(User fUser,User sUser)
: firstUser(fUser), secondUser(sUser)
{
}

void Chat::init(){
    attach(&firstUser);
    attach(&secondUser);
}

// Implementazione del metodo GETTER per la proprietà firstUser
User Chat::getFirstUser() const {
    return firstUser;
}

// Implementazione del metodo GETTER per la proprietà secondUser
User Chat::getSecondUser() const {
    return secondUser;
}

const std::list<Observer*>& Chat::getObservers() const {
    return observers;
}

void Chat::attach(Observer* o) {
    observers.push_back(o);
}

void Chat::detach(Observer* o) {
    observers.remove(o);
}

void Chat::notify() {
    for (auto& observer : observers) {
        observer->update(this);
    }
}
// Print in console the messages that was received
// and then mark them as read
void Chat::showMessages(){
    if(messages.empty()){
        throw std::runtime_error("No messages to Display!");
    }

    std::cout << toString(false) << "@@@@@@@@@@@@@@@@@@@@@@@@";
    Message* last = nullptr;
    for (auto& message : messages) {
        bool differentToLatest=!message.sameSender(last);
        if(differentToLatest)
            std::cout<< std::endl;
        std::cout << message.toString(differentToLatest);
        message.setAsRead();
        last=&message;
    }
    std::cout<< std::endl <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<< std::endl;
}

int Chat::getTotalMessages() const {
    return messages.size();
}

bool Chat::equals(const Chat &other) const {
    return this->firstUser.equals(other.getFirstUser()) &&
           this->secondUser.equals(other.getSecondUser());
}

std::string Chat::toString(bool tabulation) const {
    std::string tabulationText= !tabulation ? "" : "\t\t";
    return "|C|"+tabulationText+firstUser.getUsername()
    + " => "+secondUser.getUsername()
    + " \t [no." + std::to_string(getTotalMessages()) + "]";
}

bool Chat::userIn(const User& user) const{
    return user.equals(this->getFirstUser())
    || user.equals(this->getSecondUser());
}

Chat::~Chat() {
    detach(&firstUser);
    detach(&secondUser);
    std::cout << "Chat con @" << secondUser.getUsername() << " eliminata" << std::endl;
}


void Chat::sendMessage(Message message){
    auto sender=message.getSender();
    if(!sender.equals(firstUser) && !sender.equals(secondUser))
        throw std::runtime_error("User not in chat!");

    message.prepareToSend();
    messages.push_back(message);
    notify();
}
void Chat::sendMessage(User sender,const std::string &content){
    Message message(sender,content);
    sendMessage(message);
}

const std::list<Message> &Chat::getMessages() const {
    return messages;
}

Message Chat::getLastMessage() const{
    if(getTotalMessages()==0){
        throw std::runtime_error("No messages sent yet");
    }

    Message lastMessage=messages.back();

    return lastMessage;
}

int Chat::getReadMessages() const {
    int count=0;
    for (const auto& message : messages) {
        if(message.getWasRead())
            count ++ ;
    }
    return count;
}