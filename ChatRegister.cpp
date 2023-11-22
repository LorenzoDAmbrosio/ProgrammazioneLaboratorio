//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#include <iostream>
#include "ChatRegister.h"

ChatRegister::ChatRegister(const std::string &t)
: title(t) {

}
void ChatRegister::addChat(Chat* c) {
    chats.push_back(c);
}

bool ChatRegister::deleteChat(const Chat &c) {
    bool found = false;
    if(chats.empty())
        return found;
    for(auto it = chats.begin();
        it != chats.end() && !found;
        it++)
    {
        if((*it)->equals(c)){
            chats.remove(*it);
            found = true;
        }
    }
    return found;
}

void ChatRegister::ShowChats() {
    std::cout << "|R|" << title << " "<<"[no."<<chats.size()<<"]"<< "@@@@@@@@@@@@@@@@@@@@@@@@" <<  std::endl;
    for(auto chat : chats)
    {
        std::cout << chat->toString(true) << std::endl;
    }
    std::cout <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<< std::endl;
};