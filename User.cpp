//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#include <iostream>
#include "User.h"
#include "Chat.h"


User::User(const std::string &u)
: username(u)
{
}


std::string User::getUsername() const {
    return username;
}
std::string User::toString() const{
    return username;
}

bool User::equals(User other) const{
    return this->username==other.getUsername();
}
bool User::operator==(User other) const{
    return this->equals(other);
}
bool User::operator!=(User other) const{
    return !this->equals(other);
}
void User::update(Chat *c){
    if(!c->userIn(*this)){
        throw std::runtime_error("Chat unrelated with this user");
    }
    Message lastMessage= c->getLastMessage();
    User sender=lastMessage.getSender();

    std::string senderText= this->equals(c->getFirstUser())
        ? "You" : sender.toString();

    std::string actionText= this->equals(sender)
        ? "|M|>> "+senderText+" Sent >> "
        : "|M|<< " +senderText+" Received << ";

    std::cout << actionText << lastMessage.getContent()<<std::endl;
}


User::~User() {

}
