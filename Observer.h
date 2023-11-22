//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#ifndef PROGRAMMAZIONELABORATORIO_OBSERVER_H
#define PROGRAMMAZIONELABORATORIO_OBSERVER_H

class Chat;

// Observer Design Pattern Implementation
class Observer {
    public:
        virtual void update(Chat* c) = 0;
        virtual ~Observer() = default;
};

#endif //PROGRAMMAZIONELABORATORIO_OBSERVER_H
