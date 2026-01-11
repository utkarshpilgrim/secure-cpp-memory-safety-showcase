#include <iostream>
#include <cstring>

void vulnerableFunction(char* input){
    char buffer[16];
    int importantVar = 42;
    strcpy(buffer, input);
    std::cout << "Buffer : " << buffer << std::endl;
    std::cout << "Important Var : " << importantVar << std::endl;
}

int main(){
    
    char maliciousInput[32] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    vulnerableFunction(maliciousInput);
    return 0;
}