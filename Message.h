//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#ifndef PROGRAMMAZIONELABORATORIO_MESSAGE_H
#define PROGRAMMAZIONELABORATORIO_MESSAGE_H


#include <string>
#include "User.h"

class Message {
    private:
        std::string content;
        std::string sendDate;
        User* sender;
    public:
        explicit Message(User* sender,const std::string &content);

        //GETTER Content Method :
        // returns the value of property Content
        std::string getContent();
        //SETTER Content Method :
        // sets the property Content
        void setContent(const std::string &c);

        //GETTER Sender Method :
        // returns the value of property Sender
        User* getSender();
        //SETTER Sender Method :
        // sets the property Sender
        void setSender(User* s);
        std::string toString(bool showHeader);
        bool sameSender(Message* other);

    void prepareToSend();
};


#endif //PROGRAMMAZIONELABORATORIO_MESSAGE_H
