//
// Created by Lorenzo D'Ambrosio on 26/11/2023.
//
#include "gtest/gtest.h"
#include "../chat.h"

//test showMessages
TEST(Chat, showMessages) {
    auto* us1=new User("Alice");
    auto* us2=new User("Bob");
    auto* us3=new User("Test");

    Message msg1(us1,"test");
    Message msg2(us3,"test exception");

    Chat* chat=new Chat(us1,us2);

    // La chat se è vuota dovrebbe restituire eccezione
    ASSERT_ANY_THROW(chat->showMessages());
    // testo se un utente esterno alla chat
    // può inviare un messaggio
    ASSERT_ANY_THROW(chat->sendMessage(msg2));
    // la chat continua ad essere vuota
    ASSERT_ANY_THROW(chat->showMessages());
    // aggiungo un nuovo messaggio, questa volta inerente
    ASSERT_NO_THROW(chat->sendMessage(msg1));
    // riprovo a mostrare i messaggi
    ASSERT_NO_THROW(chat->showMessages());
}
//test SendMessage
TEST(Chat, SendMessage) {
    auto* us1=new User("Alice");
    auto* us2=new User("Bob");

    Message msg1(us1,"test");


    Chat* chat=new Chat(us1,us2);


    ASSERT_NO_THROW(chat->sendMessage(msg1));
    ASSERT_EQ(1,chat->getTotalMessages());
    Message latestMsg=chat->getMessages().back();
    ASSERT_EQ(msg1,latestMsg);
    ASSERT_EQ(us1,latestMsg.getSender());
    ASSERT_NE(us2,latestMsg.getSender());
}