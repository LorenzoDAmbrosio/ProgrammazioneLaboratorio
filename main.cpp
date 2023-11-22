#include <iostream>
#include "User.h"
#include "Chat.h"
#include "ChatRegister.h"

/*
 * 2023 09 20
 * Creato da Lorenzo D'Ambrosio 7050275
 *
 *
 *
 *
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
    chat->sendMessage(new Message(MainUser,"Hello World!"));
    chat->sendMessage(new Message(OtherUser,"I'm not World i'm Giovanni"));
    chat->sendMessage(new Message(MainUser,"Heo Giovanni!"));
    chat->sendMessage(new Message(MainUser,"*Hello"));
    chat->sendMessage(new Message(OtherUser,"That goes, Hello Marco"));
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