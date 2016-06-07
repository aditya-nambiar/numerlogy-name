

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

ofstream file;

set<string> allp;


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
        for(int k=0; k< str.size()-1; k++){
         string pr = str.substr(k,2);
         if( str[k] == str[k+1] && str[k] != 'a') return false;
         if( allp.find(pr) != allp.end())return false; 
        }
        return true;
    }

    
    return false;
}

int cnt = 1;

void  generate(string name,  int req, bool vowel){
    if( name.size() >= req){
        if( check(name) && vowel){
            file << name;
            file <<endl;
            cnt++;
        }
        return;
    }
    
    for(int k=0; k<26; k++){
        char let = (char)'a' + k;
        if ( let == 'u' || let == 'v' ||  let== 'w' || let== 'o' || let == 'z' || let == 'f' || let == 'p' || let =='x'){
            continue;
        }
        string s;
        stringstream ss;
        ss << let;
        ss >> s;
        string temp_name = name + s;
        bool temp_vow = false;
        if ( s == "a" || s == "i" || s == "e")temp_vow = true;
        generate(temp_name,  req, temp_vow || vowel);
    }
    
    
}


bool notVowel(int i){
			if( i == 0 || i == 4 || i == 8 || i == 14 || i == 20)return false;

			return true;

}
void getSet(){


for (int i=0; i<26; i++){
	for(int j=0; j<26; j++){
		char let1 = (char) 'a' + i;
		char let2 = (char) 'a' + j;
		if( notVowel(i) && notVowel(j)){
		  string s1, s2;
          stringstream ss1;
          ss1 << let1;
          stringstream ss2;
          ss2 << let2;
          ss1 >> s1;
          ss2 >> s2;
          string pr = s1 + s2; 
			allp.insert(pr);          
		}
	}
}

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
        if(  y++ == 0|| name.size() <=2  || name.size() >= 10)continue;

        string stripped_name = name.substr(1, name.size()-2);
        stripped_name[0] = stripped_name[0] -'A' + 'a';
		for(int k=0; k<stripped_name.size()-1; k++){
			 string temp = stripped_name.substr(k,2);
			 allp.erase(temp);
		}
 		break;;
    }    
}

}

int main(){
    getSet();
    string name;
    set<string> :: iterator it;
    for ( it = allp.begin(); it!= allp.end(); it++)cout<<*it<<endl;
    	cout<<allp.size() <<endl;
    file.open ("google_names.txt");
    for(int i=3; i<=6; i++){ //lenght of name
        string name = "";
        generate("", i, false);
    }
}