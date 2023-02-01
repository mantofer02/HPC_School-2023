#ifndef MODEL
#define MODEL


class Model {
  private:
    int n;
  public:
    Model();
    void createModel();
    void addDecorator();
    void calculateTransitions();
    int* getSequences();
    char* generateWord();
    float getProbability();
};

#endif