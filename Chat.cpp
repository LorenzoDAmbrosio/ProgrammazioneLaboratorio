//
// Created by Lorenzo D'Ambrosio il 20/09/2023.
//

#include <iostream>
#include "Chat.h"

// Costruttore della classe Chat
Chat::Chat(User* fUser,User* sUser)
: firstUser(fUser), secondUser(sUser),isOpen(false),totalMessages(0)
{
    attach(fUser);
    attach(sUser);
}

// Implementazione del metodo GETTER per la proprietà firstUser
User* Chat::getFirstUser() const {
    return firstUser;
}

// Implementazione del metodo GETTER per la proprietà secondUser
User* Chat::getSecondUser() const {
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

void Chat::showMessages(){
    std::cout << toString(false) << "@@@@@@@@@@@@@@@@@@@@@@@@";
    Message* latest = nullptr;
    for (auto message : messages) {
        bool differentToLatest=!message->sameSender(latest);
        if(differentToLatest)
            std::cout<< std::endl;
        std::cout << message->toString(differentToLatest);
        latest=message;
    }
    std::cout<< std::endl <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<< std::endl;
}

int Chat::getTotalMessages() const {
    return messages.size();
}

bool Chat::equals(const Chat &other) const {
    if (&other == nullptr)
        return false;
    return this->firstUser->equals(other.getFirstUser()) &&
           this->secondUser->equals(other.getSecondUser());
}

std::string Chat::toString(bool tabulation) const {
    std::string tabulationText= !tabulation ? "" : "\t\t";
    return "|C|"+tabulationText+firstUser->getUsername()
    + " => "+secondUser->getUsername()
    + " \t [no." + std::to_string(getTotalMessages()) + "]";
}

Chat::~Chat() {
    detach(firstUser);
    detach(secondUser);
    std::cout << "Chat con @" << secondUser->getUsername() << " eliminata" << std::endl;
}


void Chat::sendMessage(Message* message) {
    auto sender=message->getSender();
    if(!sender->equals(firstUser) && !sender->equals(secondUser))
        throw std::runtime_error("User not in chat!");

    message->prepareToSend();
    messages.push_back(message);
    notify();
}
void Chat::sendMessage(User* sender,std::string content) {
    Message* message=new Message(sender,content);
    if(!sender->equals(firstUser) && !sender->equals(secondUser))
        throw std::runtime_error("User not in chat!");

    message->prepareToSend();
    messages.push_back(message);
    notify();
}

const std::list<Message *> &Chat::getMessages() const {
    return messages;
}
