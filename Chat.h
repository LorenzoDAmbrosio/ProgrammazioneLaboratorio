//
// Created by Lorenzo D'Ambrosio il 20/09/2023.
//

#ifndef PROGRAMMAZIONELABORATORIO_CHAT_H
#define PROGRAMMAZIONELABORATORIO_CHAT_H

#include <string>
#include <list>
#include "Subject.h"
#include "Message.h"
#include "User.h"

class Chat : public Subject {
private:
    User* firstUser;
    User* secondUser;
    std::list<Message*> messages;
    std::list<Observer*> observers;

public:
    // Costruttore
    explicit Chat(User* fUser,User* sUser);

    // Metodi GETTER per le proprietà firstUser e secondUser
    User* getFirstUser() const;
    User* getSecondUser() const;

    const std::list<Observer*>& getObservers() const;

    void sendMessage(Message* message);
    void sendMessage(User* sender,std::string content);

    const std::list<Message*>& getMessages() const;

    void showMessages();

    int getTotalMessages() const;

    // Override dei metodi del pattern Observer
    void attach(Observer* o) override;
    void detach(Observer* o) override;
    void notify() override;

    bool equals(const Chat &other) const;

    std::string toString(bool tabulation) const;

    // Distruttore
    ~Chat();

    bool userIn(User *user) const;

    Message * getLatestMessage();
};

#endif //PROGRAMMAZIONELABORATORIO_CHAT_H
