//
// Created by Lorenzo D'Ambrosio on 26/11/2023.
//
#include "gtest/gtest.h"
#include "../chat.h"

//test showMessages
TEST(Chat, showMessages) {
    User us1("Alice");
    User us2("Bob");
    User us3("Test");

    Message msg1(us1,"test");
    Message msg2(us3,"test exception");

    Chat* chat=new Chat(us1,us2);

    // La chat se è vuota dovrebbe restituire eccezione
    ASSERT_THROW(chat->showMessages(),std::runtime_error);
    // testo se un utente esterno alla chat
    // può inviare un messaggio
    ASSERT_THROW(chat->sendMessage(msg2),std::runtime_error);
    // la chat continua ad essere vuota
    ASSERT_THROW(chat->showMessages(),std::runtime_error);
    // aggiungo un nuovo messaggio, questa volta inerente
    ASSERT_NO_THROW(chat->sendMessage(msg1));
    // riprovo a mostrare i messaggi
    ASSERT_NO_THROW(chat->showMessages());
}
//test SendMessage
TEST(Chat, SendMessage) {
    User us1("Alice");
    User us2("Bob");

    Message msg1(us1,"test");

    Chat chat(us1,us2);

    ASSERT_NO_THROW(chat.init());

    ASSERT_NO_THROW(chat.sendMessage(msg1));

    ASSERT_EQ(1,chat.getTotalMessages());
    Message lastMsg=chat.getLastMessage();
    
    ASSERT_EQ(us1, lastMsg.getSender());
    ASSERT_NE(us2, lastMsg.getSender());
}
//test ReadMessages
TEST(Chat, ReadMessages) {
    User us1("Alice");
    User us2("Bob");

    Message msg1(us1,"test lettura");


    Chat* chat=new Chat(us1,us2);

    ASSERT_NO_THROW(chat->sendMessage(msg1));
    ASSERT_EQ(0,chat->getReadMessages());
    ASSERT_NE(1,chat->getReadMessages());

    ASSERT_NO_THROW(chat->showMessages());
    ASSERT_EQ(1, chat->getReadMessages());
}