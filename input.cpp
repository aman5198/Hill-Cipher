#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>

std::string inputMessage(std::string p){
    std::ifstream input_file(p);
    if(!input_file.is_open()){
        std::cerr << "Can't Read Message " << std::endl;
        exit(EXIT_FAILURE);
    }

    p=std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>()); 

    int j=0;
    for(int i=0;i<p.size();i++){
        if ((p[i] >='A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z')){
            p[j]=p[i];
            j++;
        }
    }
    p[j]='\0';

    return p;
}

int** inputKey(std::string k){
    int keySize;
    std::ifstream input_file(k);
    if(!input_file.is_open()){
        std::cerr << "Can't read Key" << std::endl;
        exit(EXIT_FAILURE);
    }

    input_file >> keySize ;
    
    int **mat=(int **)malloc(keySize*sizeof(int*));
    for(int i=0;i<keySize;i++){
        mat[i]=(int *)malloc(keySize*sizeof(int));
    }
    for(int i=0;i<keySize;i++){
        for(int j=0;j<keySize;j++){
            input_file >> mat[i][j];
        }
    }
    return mat; 
}

std::string inputCipher(std::string c){
    std::ifstream input_file(c);
        if(!input_file.is_open()){
        std::cerr << "Can't Read Cipher" << std::endl;
        exit(EXIT_FAILURE);
    }

    return (std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>())); 

}

int  main(){
    std::string message,messagePath,keyPath,cipher,cipherPath;
    messagePath="message.txt";
    keyPath="key.txt";
    cipherPath="cipher.txt";
    message=inputMessage(messagePath);
    int ** key;
    key=inputKey(keyPath);
    cipher=inputCipher(cipherPath);
    return 0;
}