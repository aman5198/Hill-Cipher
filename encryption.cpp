#include"input.h"
#include"matrixFunctions.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;

string encrypt(){
    string message,messagePath,keyPath,cipher;
    messagePath="message.txt";
    keyPath="key.txt";
    message=inputMessage(messagePath);
    cout<<endl<<"Message recieved is: "<<message<<endl;
    int ** k;
    k=inputKey(keyPath);

    /* Transforming key to send it to multiply function */
    float key[10][10];
    for(int i=0;i<keyLength;i++){
        for(int j=0;j<keyLength;j++){
            key[i][j]=k[i][j];
        }
    }

    /* Appending message with extra characters */
    message.erase(remove(message.begin(), message.end(), '\n'), message.end());
    message.erase(remove(message.begin(), message.end(), '\0'), message.end());
    int row=keyLength;
    int col=strlen(message.c_str())/keyLength;
    if(strlen(message.c_str())%keyLength!=0){
        col=col+1;
        int extra=keyLength-strlen(message.c_str())%keyLength;
        for(int i=0;i<extra;i++){
            message=message.append("Z");
        }
    }

    /* Converting message to 2-D array */
    int x=0;
    float plain[row][10];
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            plain[j][i]=message[x]-65;
            x++;
        }
    }

    float result[row][10];
    matrixFunctions obj;
    obj.multiply(row,row,col,key, plain, result);
    int cipherText[row][10];
    string cText="";
    obj.modAndCeil(result, row, col, cipherText);
    
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cText=cText+(char(cipherText[j][i]+65));
        }
    }
    return cText;
}

int main(){
    string cipherText=encrypt();
    cout<<"The cipher text is: "<<cipherText<<endl;
    string cipherPath;
    cipherPath="cipher.txt";

    ofstream cipherFile(cipherPath);
    cipherFile << cipherText;
    cipherFile.close();
}   