#include <iostream>
#include "User.h"
#include "Chat.h"
#include "ChatRegister.h"

/*
 * 2023 09 20
 * Creato da Lorenzo D'Ambrosio 7050275
 *
 *Il codice sviluppato deve essere tenuto sotto versionamento con Github o servizio simile.
 *Si deve scrivere codice di Unit Testing per tutte le classi principali.
 *
 * Classi che rappresentano chat tra utenti.
 * Si deve rappresentare un utente di un sistema,
 * un messaggio di chat da un utente ad un altro,
 * una classe che rappresenta una chat tra due utenti,
 * un registro di tutte le chat fatte.
 *
 * */

int main() {
    ChatRegister* MainRegister= new ChatRegister("Marco's Chats");

    // registered users
    User* MainUser= new User("Marco");
    User* OtherUser= new User("Giovanni");
    User* thirdUser= new User("Alice");

    // registered chats
    Chat* chat= new Chat(MainUser,OtherUser);
    Chat* secondChat= new Chat(MainUser,thirdUser);

    // Adding chats to Register and then show them
    MainRegister->addChat(chat);
    MainRegister->addChat(secondChat);
    MainRegister->ShowChats();

    std::cout<< std::endl;

    // Sending Messages between Marco and Giovanni
    chat->sendMessage(Message(MainUser,"Hello World!"));
    chat->sendMessage(Message(OtherUser,"I'm not World i'm Giovanni"));
    chat->sendMessage(Message(MainUser,"Heo Giovanni!"));
    chat->sendMessage(Message(MainUser,"*Hello"));
    chat->sendMessage(Message(OtherUser,"That goes, Hello Marco"));
    std::cout<< std::endl;

    // showing resume of the chat
    chat->showMessages();
    std::cout<< std::endl;

    // Sending Messages between Marco and Alice
    secondChat->sendMessage(MainUser,"Hello Alice!");
    secondChat->sendMessage(thirdUser,"Hi Mark");
    secondChat->sendMessage(thirdUser,"How are you doing?");
    std::cout<< std::endl;

    // showing resume of the chat
    secondChat->showMessages();
    std::cout<< std::endl;

    // showing register with the updated chats
    MainRegister->ShowChats();

    return 0;
}
/*
 *
 * ***************
 *
 *
 *
 *
 * */