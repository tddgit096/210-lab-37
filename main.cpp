#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

string INPUTFILE = "data.txt";
int HASHSIZE = 70 , TESTRUN = 100;

int gen_hash_index(string);
int read_file(string, map<int,list<string>>);
void print(map<int,list<string>>, int);

int main() {
    map <int,list<string>> hash_table; // a map of int-keys storing string-lists
    read_file(INPUTFILE,hash_table);
    cout<<"TEST "<<hash_table[8].front()<<endl;
    print(hash_table,TESTRUN);
    return 0;
}

//function recieves a string and returns the hash index
int gen_hash_index(string s){
    int sum=0;
    for(char c : s){ //range based loop, for every char in the string
        sum+=(int)c; //type cast each char into int.
    }
    return sum % HASHSIZE;
}

//function reads input file and sums up the entire file.
int read_file(string inputfile, map<int,list<string>> table){
    int sum = 0;
    fstream file(inputfile);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            pair<int, string> hash_pair = {gen_hash_index(line), line}; //store hash and string into pair
            cout<<"inputting: key "<<hash_pair.first<<" with val"<<hash_pair.second<<endl;
            table[hash_pair.first].push_back(hash_pair.second);       //access map by hash key. insert the string into that key's list.
        }
        file.close();
    }
    else{
        cout<<"File not found. Terminating.\n";
        return -1;
    }
    return sum;
}

//print the outputs
void print(map<int,list<string>> table, int limit =-1){
    if(limit == -1) //defaults to unlimited size
        limit = table.size();
    cout<<"Displaying the first "<<TESTRUN<<" entries to the console:\n";
    int count = 0; //counter for limiting the iteration
    for(auto pair : table){
        for(string s: pair.second){
            if(count>=TESTRUN)
                return;
            cout<<s<<endl;
            count++;
        }
    }
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