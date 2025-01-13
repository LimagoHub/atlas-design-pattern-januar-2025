//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once


#include <vector>
#include <memory>

class AttributedCharacter {

    static std::vector< std::shared_ptr<AttributedCharacter> > characters;

    const char c;
    const bool bold;
    AttributedCharacter(const char c, const bool bold) : c(c), bold(bold) {}

public:
    AttributedCharacter(const AttributedCharacter& other) = delete;
    void operator = (const AttributedCharacter& other) = delete;
    AttributedCharacter(AttributedCharacter&& other) = delete;
    void operator = (AttributedCharacter&& other) = delete;

    virtual ~AttributedCharacter() = default;

    static std::shared_ptr<AttributedCharacter>  get_instance(const char c, const bool bold)
    {
        for(auto ac: characters)
        {
            if (ac->c == c && ac->bold == bold) return ac;

        }
        auto result = std::shared_ptr<AttributedCharacter>(new AttributedCharacter{c,bold});
        characters.push_back(result);
        return result;
    }

    const char getC() const {
        return c;
    }

    const bool isBold() const {
        return bold;
    }
};
std::vector<std::shared_ptr<AttributedCharacter>> AttributedCharacter::characters;