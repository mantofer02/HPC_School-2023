#ifndef MODEL_N
#define MODEL_N

#include <tuple>
#include <vector>
#include <string>

class Model {
  private:
    char decorator;

  public:
    Model(char);
    std::tuple<std::vector<float>, std::vector<std::string>> create_model();

};

#endif