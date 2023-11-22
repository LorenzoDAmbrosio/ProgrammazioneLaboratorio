//
// Created by Lorenzo D'Ambrosio on 20/09/2023.
//

#ifndef PROGRAMMAZIONELABORATORIO_SUBJECT_H
#define PROGRAMMAZIONELABORATORIO_SUBJECT_H


#include <list>
#include "Observer.h"

class Subject {

    public:
        //metodo per aggiungere un observer alla lista degli observer
        virtual void attach(Observer *o) = 0;

        //metodo per rimuovere un observer dalla lista degli observer
        virtual void detach(Observer *o) = 0;

        //metodo per notificare gli observer
        virtual void notify() = 0;


        virtual ~Subject() = default;
};


#endif //PROGRAMMAZIONELABORATORIO_SUBJECT_H
