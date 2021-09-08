#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

float indexOfCoincidence(string s){
    int len=strlen(s.c_str());
    int frequency[26];
    for(int i=0;i<26;i++){
        frequency[i]=0;
    }
    for(int i=0;i<len;i++){
        frequency[s[i]-65]+=1;
        
    }
    float ic=0;
    for(int i=0;i<26;i++){
        if(frequency[i]==0)
        {
            continue;
        }
        ic=ic+(frequency[i]*(frequency[i]-1));
    }
    ic=ic/(len*(len-1));
    return ic;
}
