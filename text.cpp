#include <iostream>
#include <fstream> 
#include <sstream>
using namespace std;
 
void text(){
    char word[1024] = {};
    ifstream file;
    file.open("text.txt", ios::in);

    string s;
    stringstream ssIn, ssOut;

    while(getline(file, s)){
        ssIn << s;
        while (ssIn >> word){
            if (word[0] == 'e' || word[0] == 'y' || word[0] == 'u' || word[0] == 'i' || word[0] == 'o' || word[0] == 'a')
                word[0] = toupper(word[0]);
            ssOut << word << " ";
        }
        cout << ssOut.str() << endl;
        ssOut.str("");
        ssIn.clear();
    }           
   
    file.close();
}
