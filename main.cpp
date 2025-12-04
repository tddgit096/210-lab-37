#include <iostream>
#include <fstream>
using namespace std;

string INPUTFILE = "data.txt";

int sum_ascii(string);
int read_file(string);

int main() {
    cout<<"Grand Total sum: "<<read_file(INPUTFILE)<<endl;
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

//function reads input file and sums up the entire file.
int read_file(string inputfile){
    int sum = 0;
    fstream file(inputfile);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            sum+=sum_ascii(line);
        }
        file.close();
    }
    else{
        cout<<"File not found. Terminating.\n";
        return -1;
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


/*
    //test code for ascii summing
    string test = "Hello World";
    cout<<test <<" --> ascii sum:  "<<sum_ascii(test)<<endl;

    cout<<endl<<"Manual Confirmation: ";
    cout<<((int)'H' +(int)'e' +(int)'l' +(int)'l' +(int)'o' +(int)' ' +(int)'W' +(int)'o' +(int)'r' +(int)'l' +(int)'d'); 
    cout<<endl;

*/