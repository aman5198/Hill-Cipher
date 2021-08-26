#include"input.h"
#include"matrixFunctions.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;

string encrypt(string message, string key){
    
}

int main(){
    string message,messagePath,keyPath,cipher;
    messagePath="message.txt";
    keyPath="key.txt";
    message=inputMessage(messagePath);
    cout<<"The message found is: "<<message;
    int ** key;
    key=inputKey(keyPath);
    cout<<"The key found is: "<<key;
}