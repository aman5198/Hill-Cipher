#include "input.h"
#include "matrixFunctions.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#define M 1000

string decrypt(){
    string keyPath,cipher,cipherPath;
    int** k;
    matrixFunctions obj;
    keyPath="key.txt";
    cipherPath="cipher.txt";
    k=inputKey(keyPath);
    cipher=inputCipher(cipherPath);
    cout << "Cipher Text is : "<< cipher << endl;
/* Transforming key to send it to inverse function */
    float key[keyLength][M],inv[keyLength][M];

    for(int i=0;i<keyLength;i++){
        for(int j=0;j<keyLength;j++){
            key[i][j]=k[i][j];
        }
    }
    cout << "Key Length is : " << keyLength << endl;
    int valid;
    valid=obj.inverse(key,keyLength,keyLength,inv);
    if(valid==0){
        return "";
    }
   

    for(int i=0;i < keyLength ; i++){
        for(int j=0;j<keyLength; j++){
            key[i][j]=int(inv[i][j]);
        }
    }

    cout << "Key after is inverse is : " << endl;
  /*  for(int i=0;i<keyLength;i++){
        for(int j=0;j<keyLength;j++){
            for (int x = 1; x < 26; x++)
                if ((key[i][j]%26 * (key[i][j]%26)) % 26 == 1){
                    key[i][j]=x;
                    break;
                }
        }
    }


    for(int i=0;i<keyLength;i++){
        for(int j=0;j<keyLength;j++){
            cout << inv[i][j] << " ";
        }
        cout << endl;
    }

*/

    int row=keyLength;
    int col=strlen(cipher.c_str())/keyLength;

    int x=0;
    float plain[row][M];
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            plain[j][i]=int(cipher[x]-65);
            x++;
        }
    }


  /* for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout << plain[j][i] << " ";
        }
        cout << endl;
    }
    */



    float result [row][M];
    obj.multiply(row,row,col,inv, plain, result);
    int messageText[row][M];
    string mText="";
    obj.modAndCeil(result, row, col, messageText);
   /* for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout << messageText[j][i] << " ";
        }
        cout << endl;
    }
    */



    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            mText=mText+(char(messageText[j][i]+65));
        }
    }

 /* Removing extra characters*/
    for(int i=mText.length()-1;i>0;i--){
        if(mText[i]=='Z'){
            mText[i]='\0';
        }
        else{
            break;
        }
    }   
    return mText;

}