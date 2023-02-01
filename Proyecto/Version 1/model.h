#ifndef MODEL_N
#define MODEL_N

#include <tuple>
#include <vector>
#include <string>
#include <algorithm>

class Model {
  private:
    char decorator;

  public:
    Model(char);
    std::tuple<std::vector<float>, std::vector<std::string>> create_model();
    std::vector<std::string> add_decorator(std::vector<std::string>,int num_decorators,char decorator);

};

#endif