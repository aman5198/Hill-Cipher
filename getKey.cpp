#include<iostream>
#include<fstream>
#include<string.h>
#include"decrpytFunction.h"
#include"calculateIC.h"

void messageMatrix(string message,float mes[][M],int i,int x){  
    for(int j=0;j<i;j++){
        for(int k=0;k<i;k++){
            mes[k][j]=message[x]-65;
            x++;
        }
    }
    return;
}

void cipherMatrix(string cipher,float cip[][M],int i,int x){ 
    for(int j=0;j<i;j++){
        for(int k=0;k<i;k++){
            cip[k][j]=cipher[x]-65;
            x++;
        }
    }
    return;

}

int main(){
    string filePath;
    filePath="message.txt";
    string message=inputMessage(filePath);
    filePath="cipher.txt";
    string cipher=inputCipher(filePath);
    
    float arr[10];
    for(int i=1;i<11;i++){ 
        float mes[i][M],cip[i][M];  
        int x=-1,valid;
        matrixFunctions obj;
        float inv[i][M],result[i][M];
         do{ 
            x=x+1;
            messageMatrix(message,mes,i,x);
            valid=obj.inverse(mes,i,i,inv);
        }
        while (valid==0&&x<(message.length()-i));
        cipherMatrix(cipher,cip,i,x);
        obj.multiply(i,i,i,cip,inv,result);
        
        int key[i][M];

        obj.modAndCeil(result,i,i,key);

        string keyFile="key.txt";
        ofstream output_file(keyFile);

        output_file << i << endl;

        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                output_file << key[j][k] << " ";
            }
            output_file << endl;
        }
        
        string analysis;

        analysis=decrypt();
        if(analysis == ""){
            cout << "Invalid Key for size " << i << endl;
            arr[i-1]=1;
            cout << endl ;
            continue;
        }

        float ic;

        ic=indexOfCoincidence(analysis);
        arr[i-1]=abs(ic - 0.065);
        cout << "index of coincidence for size " << i << " is :" << ic << endl;
        cout << endl ;
    }
    float min=1;
    int k=0;

    for(int j=0;j<10;j++){
        if(arr[j]<min){
            min=arr[j];
            k=j;
        }
    }

    cout << "Key size is : " << k+1<<endl;
    return 0;
}