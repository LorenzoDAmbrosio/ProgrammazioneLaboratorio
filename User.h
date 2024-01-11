//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#ifndef PROGRAMMAZIONELABORATORIO_USER_H
#define PROGRAMMAZIONELABORATORIO_USER_H


#include <string>
#include "Observer.h"

class User : public Observer{
    private:
        std::string username;
    public:
        User(const std::string &u);

        //GETTER ChatRegister Method :
        //returns the property username
        std::string getUsername() const;

        //Observer Pattern update method override
        void update(Chat *c) override;

        std::string toString() const;

        bool equals(User other) const;
        bool operator==(User other) const;
        bool operator!=(User other) const;

        //User Deconstructor
        ~User() override;
};


#endif //PROGRAMMAZIONELABORATORIO_USER_H
