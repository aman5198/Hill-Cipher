#include "decrpytFunction.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
    string message=decrypt();
    cout << "message is - " << message << endl;
    string messagePath;
    messagePath="message.txt";
    ofstream messageFile(messagePath);
    messageFile << message;
    messageFile.close();
    return 0;
}
