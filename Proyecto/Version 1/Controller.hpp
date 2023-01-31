#ifndef CONTROLLER
#define CONTROLLER
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Controller {
    public:
        Controller();
        ~Controller();
    private:
        vector<string> word_array;
        void read_csv();
        vector<string> get_word_array();
        void set_word_array(vector<string>);
};
#endif