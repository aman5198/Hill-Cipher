#include"input.h"
#include"matrixFunctions.h"
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define M 1000

string encrypt(){
    string message,messagePath,keyPath,cipher;
    messagePath="message.txt";
    keyPath="key.txt";
    message=inputMessage(messagePath);
    cout<<endl<<"Message recieved is: "<<message<<endl;
    int ** k;
    k=inputKey(keyPath);

    cout<<"Key length is: "<<keyLength<<endl;
    cout<<"Message length is: "<<strlen(message.c_str())<<endl;
    /* Transforming key to send it to multiply function */
    float key[M][M];
    for(int i=0;i<keyLength;i++){
        for(int j=0;j<keyLength;j++){
            key[i][j]=k[i][j];
        }
    }

    /* Appending message with extra characters */
    //message.erase(remove(message.begin(), message.end(), '\n'), message.end());
    //message.erase(remove(message.begin(), message.end(), '\0'), message.end());
    int row=keyLength;
    int col=strlen(message.c_str())/keyLength;
    int l=strlen(message.c_str());
    if(strlen(message.c_str())%keyLength!=0){
        col=col+1;
        int extra=keyLength-strlen(message.c_str())%keyLength;
        for(int i=0;i<extra;i++){
            message[i+l]='Z';
        }
        message[extra+l]='\0';
    }

   cout<<"Message after conversion: "<<message<<endl;
    /* Converting message to 2-D array */
    int x=0;
    float plain[row][M];
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            plain[j][i]=int(message[x]-65);
            x++;
        }
    }
    
    float result[row][M];
    matrixFunctions obj;
    obj.multiply(row,row,col,key, plain, result);
    //obj.print(result,row, col);
    int cipherText[row][M];
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