#include "model.h"
#include <iostream>

Model::Model(char decorator) {
  this->decorator = decorator;
  std::cout << "Model Creation with decorator: " << decorator << std::endl;
}

std::tuple<std::vector<float>, std::vector<std::string>> Model::create_model() {
    std::vector<float> transition;
    std::vector<std::string> sequences;

    std::string word = "Hello";
    transition.push_back(9.0);
    sequences.push_back(word);

    return {transition, sequences};
}