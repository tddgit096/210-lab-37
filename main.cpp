#include <iostream>
using namespace std;

int sum_ascii(string);

int main() {
    string test = "Hello World";
    cout<<test <<" --> ascii sum:  "<<sum_ascii(test)<<endl;

    cout<<endl<<"Manual Confirmation: ";
    cout<<((int)'H' +(int)'e' +(int)'l' +(int)'l' +(int)'o' +(int)' ' +(int)'W' +(int)'o' +(int)'r' +(int)'l' +(int)'d'); 
    cout<<endl;
    return 0;
}

//function recieves a string and returns the sum of the string's character's ascii values
int sum_ascii(string s){
    int sum=0;
    for(char c : s){ //range based loop, for every char in the string
        sum+=(int)c; //type cast each char into int.
    }
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
