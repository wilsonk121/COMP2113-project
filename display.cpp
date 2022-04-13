#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int size=3;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<"╔"<<"═"<<"═"<<"═"<<"╗";
        }
        cout<<endl;
        for(int j=0;j<size;j++){
            cout<<"║"<<" "  <<" "<<" "<<"║";
        }
        cout<<endl;
        for(int j=0;j<size;j++){
            cout<<"╚"<<"═"<<"═"<<"═"<<"╝";
        }
        cout<<endl;

    }
}
 