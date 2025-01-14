#include <iostream>
#include "processor/handler/CharacterCounter.h"
#include "processor/handler/LineCounter.h"
#include "processor/FileProcessor.h"


using Processor = processor::FileProcessor;

int main() {

    auto counter = processor::handler::CharacterCounter{};
    auto lineCounter = processor::handler::LineCounter{};

    Processor fileProcessor {};
    fileProcessor.addHandler(counter);
    fileProcessor.addHandler(lineCounter);

    fileProcessor.run("..\\data\\blind.txt");

    return 0;
}
