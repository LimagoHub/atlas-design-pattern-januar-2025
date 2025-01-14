//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "handler/CharacterHandler.h"

namespace processor {
    class FileProcessor {
        std::vector < std::reference_wrapper<handler::CharacterHandler>> handlers;


        void init() {
            for (auto const handler: handlers) {
                handler.get().init();
            }
        }

        void dispose() {
            for (auto const handler: handlers) {
                handler.get().dispose();
            }
        }

        void process(char c) {
            for (auto const handler: handlers) {
                handler.get().process(c);
            }
        }

       public:
        void addHandler(handler::CharacterHandler &handler){
            handlers.push_back(std::ref(handler));
        }

        void run(std::string filename) {
            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }

            int ch;

            init();
            while (EOF != (ch = fin.get()))
            {
                process(static_cast<char>( ch)) ;
            }
            dispose();

        }




    };
}
