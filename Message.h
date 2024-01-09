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
        bool WasRead = false;
    public:

        Message(User* sender,const std::string &content);

        //GETTER Content Method :
        // returns the value of property Content
        std::string getContent() const;
        //SETTER Content Method :
        // sets the property Content
        void setContent(const std::string &c);

        //GETTER Sender Method :
        // returns the value of property Sender
        User* getSender() const;
        //SETTER Sender Method :
        // sets the property Sender
        void setSender(User* s);

        //GETTER Sender Method :
        // returns the value of property Sender
        bool getWasRead() const;
        //SETTER Sender Method :
        // sets the value of the property WasRead as true
        void setAsRead();

        std::string toString(bool showHeader) const;
        bool sameSender(Message* other) const;

        void prepareToSend();
};


#endif //PROGRAMMAZIONELABORATORIO_MESSAGE_H
