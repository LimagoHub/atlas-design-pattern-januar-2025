//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once

namespace processor::handler {

    class CharacterHandler{
    public:
        virtual void init()=0 ;

        virtual void process(char c)= 0;

        virtual void dispose() = 0;
    };

} // handler
