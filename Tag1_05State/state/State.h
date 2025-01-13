//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once



    class State {
    public :

        virtual ~State()=default;
        virtual void drucken() = 0;
        virtual void changeToA() = 0;
        virtual void changeToB() = 0;
    };


