#include <iostream>

class Session {
public:
    int id = 42;
};

void leakyFunction() {
    Session* s = new Session();
    std::cout << "Session Id:" << s->id << std::endl;
}

int main() {
    leakyFunction();
    return 0;
}