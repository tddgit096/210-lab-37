// Lab 38 | Toma Dimov | COMSC210
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

string INPUTFILE = "data.txt";
int HASHSIZE = 70 , TESTRUN = 100;

int gen_hash_index(string);
int read_file(string, map<int,list<string>>&);
void print(map<int,list<string>>, int);
void menu(map<int,list<string>>);

int main() {
    map <int,list<string>> hash_table; // a map of int-keys storing string-lists
    read_file(INPUTFILE,hash_table);
    //print(hash_table,TESTRUN);
    menu(hash_table);
    return 0;
}

void menu(map<int,list<string>> H){
    while(true){
        string strInput;
        //Menu Display for user
        cout<<"============ Main Menu ============\n";
        cout<<"  [1]Print first 100 entries.\n";
        cout<<"  [2]Search for a key.\n";
        cout<<"  [3]Add a key.\n";
        cout<<"  [4]Remove a key.\n";
        cout<<"  [5]Modify a key.\n";
        cout<<"  [0]Exit.\n";

        getline(cin,strInput);
        int input = stoi(strInput);
        switch (input)
        {
        case 0: //exit
            return;
        case 1: //display
            print(H,TESTRUN);
            break;
        case 2:{
            string searchKey;
            cout<<"Which key would you like to search for (case sensitive)?\n";
            getline(cin, searchKey);
            int hash_index = gen_hash_index(searchKey);
            bool keyfound = false;
            for(auto element : H[hash_index]){
                if(searchKey == element){
                    cout<<"Target key: "<<searchKey<<" found.\n";
                    keyfound = true;
                    break;
                }
            }
            if(!keyfound){
                cout<<"Target key: "<<searchKey<<" not found.\n";
            }
            break;
        }
        case 3:{
            string newKey;
            cout<<"Enter the new key to add (case sensitive):\n";
            getline(cin, newKey);
            H[gen_hash_index(newKey)].push_back(newKey);
        }
        default:
            break;
        }
    }
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
int read_file(string inputfile, map<int,list<string>> &table){
    int sum = 0;
    fstream file(inputfile);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            pair<int, string> hash_pair = {gen_hash_index(line), line}; //store hash and string into pair
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
    cout<<"Displaying the first "<<limit<<" entries to the console:\n";
    int count = 0; //counter for limiting the iteration
    for(auto pair : table){
        for(string s: pair.second){
            if(count>=limit)
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