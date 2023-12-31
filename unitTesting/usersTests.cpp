//
// Created by Lorenzo D'Ambrosio on 26/11/2023.
//
#include "gtest/gtest.h"
#include "../User.h"
#include "../Chat.h"

//Constructor Test
TEST(User, constructor) {
    User u("Marco");
}

//test update
TEST(User, update) {
    User u1("Alice");
    User u2("Bob");
    User u3("Carl");
    Chat* chat=new Chat(&u1,&u2);

    // ancora non sono stati inviati messaggi
    ASSERT_THROW(u1.update(chat),std::runtime_error);

    chat->sendMessage(&u1,"test");

    ASSERT_NO_THROW(u2.update(chat));
    ASSERT_NO_THROW(u1.update(chat));
    // l'utente 3 non partecipa alla chat,
    // quindi viene restituito errore
    ASSERT_ANY_THROW(u3.update(chat));
}