#include<iostream>
#include<fstream>
#include<string.h>
#include"decrpytFunction.h"
#include"cryptanalysis.cpp"

int main(){
    string filePath;
    filePath="message.txt";
    string message=inputMessage(filePath);
   // cout << message;
    filePath="cipher.txt";
    string cipher=inputCipher(filePath);
    //cout << cipher;

    for(int i=1;i<11;i++){ 
        float mes[i][10],cip[i][10];  
        int x=0;
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                mes[k][j]=message[x]-65;
                cip[k][j]=cipher[x]-65;
                x++;
            }
        }

        matrixFunctions obj;
        float inv[i][10],result[i][10];
        int key[i][10];
        obj.inverse(mes,i,i,inv);
        obj.multiply(i,i,i,cip,inv,result);
        obj.modAndCeil(result,i,i,key);

       /* for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                cout << key[j][k] << " " ;
            }
            cout << endl;
        }
        */
        string keyFile="key.txt";
        ofstream output_file(keyFile);

        output_file << i << endl;

        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                output_file << key[k][j] << " ";
            }
            output_file << endl;
        }
        
        string analysis;

        analysis=decrypt();

        float ic;
        float arr[10];

        ic=indexOfCoincidence(analysis);

        cout << "index of coincidence for size " << i << " is :" << ic << endl;

        arr[i-1]=abs(ic - 0.065);
        float min=1;
        int k=0;
        for(int j=0;j<10;j++){
            if(arr[j]<min){
                min=arr[j];
                k=j;
            }
        }

        cout << "Key size is : " << k+1;
    }

    return 0;
}