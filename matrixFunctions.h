#include <iostream>
#include<stdio.h>
#include <cmath>
#define M 1000
using namespace std;

class matrixFunctions
{
    int N;

    public:
    void print(float mat[][M], int a, int b){
        int i,j;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void multiply(int a, int b, int d, float first[][M], float second[][M], float result[][M]){
        int i,j,k;
        for(i=0;i<a;i++){
            for(j=0;j<d;j++){
                result[i][j]=0;
                for(k=0;k<b;k++){
                    result[i][j]+=first[i][k]*second[k][j];
                }
            }
        }
    }

    void fillAndMultiply(){
        cout<<"Enter first array dimension:"<<endl;
        int a,b,c,d;
        cin>>a;
        cin>>b;
        cout<<"Enter second array dimension:"<<endl;
        cin>>c;
        cin>>d;
        if (b!=c)
            return;
        float first[a][M];
        int i,j;
        cout<<"Enter first array:"<<endl;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                cin>>first[i][j];
            }
        }
        float second[c][M];
        cout<<"Enter second array:"<<endl;
        for(i=0;i<c;i++){
            for(j=0;j<d;j++){
                cin>>second[i][j];
            }
        }
        float result[a][M];
        multiply(a,b,d,first,second, result);
    }
    
    void cofactor(float mat[][M], float cofac[][M], int a, int b, int row, int col){
        int i,j;
        int r,c;
        r=0;
        for(i=0;i<a;i++){
            if(i==row){
                continue;
            }
            c=0;
            for(j=0;j<b;j++){
                if(j==col){
                    continue;
                }
                cofac[r][c]=mat[i][j];
                c++;  
            }
            r++;
        }
    }

    int findDeterminant(float mat[][M], int a, int b)
    {
        if(a==1 && b==1){
            return mat[0][0];
        }
        int d=0;
        int i;
        int s=1;
        float cofac[a][M];
        for(i=0;i<b;i++){
            cofactor(mat, cofac, a, b, 0, i);
            d=d+s*mat[0][i]*(findDeterminant(cofac,a-1,b-1));
            s=s*(-1);
        }
        return d;
    }

    void adjoint(float mat[][M], int a, int b, float adj[][M]){
        if(a==1 && b==1){
            adj[0][0]=1;
        }
        int i,j;
        int s=1;
        float cofac[a][M];
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                cofactor(mat, cofac, a, b, i, j);
                s=((i+j)%2)==0?1:-1;
                adj[j][i]=s*(findDeterminant(cofac, a-1, b-1));
                adj[j][i]=fmod(adj[j][i],26.0f);
                if(adj[j][i]<0){              //negative numbers are not allowed in adjoint for hill cipher.
                    adj[j][i]=adj[j][i]+26;    
                }
            }
        }

    }


    int modInverse(int x, int y){
        for(int i=1;i<y;i++){
            if(((x%y)*(i%y) % y)==1){
                return i;
            }
        }
        cerr << "Key not valid.";
        return 0;
    }
    void inverse(float mat[][M], int a, int b, float inv[][M]){
        int i,j;
        adjoint(mat,a ,b ,inv);
        print(inv ,a ,b);
        int d=findDeterminant(mat, a, b);
        d=modInverse(d,26); //find the multiplicative inverse of deteminant
        cout << d << endl;
        cout<<"Multiplicative inverse of Determinant: "<<d<<endl;
        if(d==0){
            cout<<"Can not find inverse."<<endl;
            return;
        }
        for(int i=0;i<a;i++){
            for(j=0;j<b;j++){
                inv[i][j]=inv[i][j]*d;
            }
        }
    }

    void modAndCeil(float mat[][M], int a, int b, int converted[][M]){
        int i,j;
        for(int i=0;i<a;i++){
            for(j=0;j<b;j++){
                converted[i][j]=int(ceil(mat[i][j]))%26;
            }
        }
    }
};
