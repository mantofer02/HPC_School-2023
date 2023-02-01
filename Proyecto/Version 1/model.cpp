#include "model.h"
#include <iostream>

Model::Model(char decorator) {
  this->decorator = decorator;
  std::cout << "Model Creation with decorator: " << decorator << std::endl;
}

std::tuple<std::vector<float>, std::vector<std::string>> Model::create_model() {
    std::vector<float> transition;
    std::vector<std::string> sequences;

    std::string word_1 = "Hello";
    std::string word_2 = "World";


    std::vector<std::string> words;
    words.push_back(word_1);
    words.push_back(word_2);

    sequences = this->add_decorator(words, 2, this->decorator);
    for (auto &it:sequences) {
      std::cout << it << std::endl;
    }

    transition.push_back(9.0);
    sequences.push_back(word_1);

    return {transition, sequences};
}
std::vector<std::string> Model::add_decorator(std::vector<std::string> words, int num_decorators, char decorator){
    for(int i = 0; i < words.size(); i++){
          std::string decorator_str = "";
          for(int j = 0; j < num_decorators;j++){
              decorator_str += decorator; 
          }
          words[i] = decorator_str + words[i] + decorator_str;
          std::transform(words[i].begin(), words[i].end(), words[i].begin(),[](unsigned char c){ return std::tolower(c); });
      }

    return words;
};