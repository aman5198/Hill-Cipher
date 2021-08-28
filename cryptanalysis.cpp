#include"input.h"
#include"matrixFunctions.h"
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
        //cout<<i<<" "<<frequency[i]<<endl;
        if(frequency[i]==0)
        {
            continue;
        }
        ic=ic+(frequency[i]*(frequency[i]-1));
    }
    ic=ic/(len*(len-1));
    return ic;
}

int main(){
    string s="VVQGYTVVVKALURWFHQACMMVLEHUCATWFHHIPLXHVUWSCIGINCMUHNHQRMSUIMHWZODXTNAEKVVQGYTVVQPHXINWCABASYYMTKSZRCXWRPRFWYHXYGFIPSBWKQAMZYBXJQQABJEMTCHQSNAEKVVQGYTVVPCAQPBSLURQUCVMVPQUTMMLVHWDHNFIKJCPXMYEIOCDTXBJWKQGAN";
    cout<<"IC value is: "<<indexOfCoincidence(s)<<endl;
    return 0;
}