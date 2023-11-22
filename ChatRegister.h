//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#ifndef PROGRAMMAZIONELABORATORIO_CHATREGISTER_H
#define PROGRAMMAZIONELABORATORIO_CHATREGISTER_H


#include <list>
#include "Chat.h"

class ChatRegister
{

    private:
        std::list<Chat*> chats;
        std::string title;

    public:
        explicit ChatRegister(const std::string& t);

        void addChat(Chat* c);
        bool deleteChat(const Chat &c);
        void ShowChats();
};


#endif //PROGRAMMAZIONELABORATORIO_CHATREGISTER_H
