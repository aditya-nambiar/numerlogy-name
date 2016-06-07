//
//  main.cpp
//  samarth
//
//  Created by Aditya Nambiar on 6/3/16.
//  Copyright © 2016 Aditya Nambiar. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int getval(char a){
	if ( a >= 'A'  && a <= 'Z' )
		a = a - 'A' + 'a';

	if ( a == 'a' || a == 'i' || a == 'j' || a == 'q' || a == 'y') return 1;
	else if ( a == 'b' || a == 'k' || a == 'r' )return 2;
	else if( a == 'c' || a == 'g' || a == 'l' || a == 's') return 3;
	else if ( a== 'd' || a == 'm' || a == 't')  return 4;
	else if (a == 'e' || a == 'h' || a == 'n' || a== 'x')  return 5; 
	else if(a == 'u' || a == 'v' || a =='w') return 6;
	else if (a == 'o' || a =='z') return 7;
	else if (a == 'f' || a == 'p') return 8;

    return 0;
 }
bool check(string str){

	int val = 0;
	for(int i=0; i< str.size(); i++){
		val += getval(str[i]);
	}

	if( val == 7) {
        bool double_let = false;
        for(int k=0; k< str.size()-1; k++){
            if( str[k] == str[k+1] && str[k] != 'a' ){
                return false
            }
        }

        return true;
    }

	return false;
}

int main(int argc, const char * argv[]) {
  
    ifstream myfile;
    myfile.open ("names1.csv");
    string line;
    int cnt  = 0;
    while (std::getline(myfile, line))
    {
        std::istringstream ss(line);
  
        string name;
        int y =0;
       while(std::getline(ss, name, ',')) {
        if( y++ == 0|| name.size() <=2 )continue;

        string stripped_name = name.substr(1, name.size()-2);
        //cout<<stripped_name<<endl;
        //cout<<"---------------\n";
           if (check(name)) {
                cout <<stripped_name<<endl;
            }  
        break;
        }
 		  
    }

    cout<<"Total names " <<cnt <<endl;
}
