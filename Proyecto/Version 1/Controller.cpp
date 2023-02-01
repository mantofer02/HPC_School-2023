#include "Controller.hpp"

Controller::Controller(){

};
Controller::~Controller(){

};

void Controller::read_csv(){
    ifstream file("pokemon.csv");
    vector<string> data;
    string line;
  
    while (getline(file, line)) {
        data.push_back(line);
    }
    file.close();
    this->set_word_array(data);
};
vector<string> Controller::get_word_array(){
    return this->word_array;
};

void Controller::set_word_array(vector<string> data){
    this->word_array = data;
};