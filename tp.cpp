#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;
bool notVowel(int i){
			if( i == 0 || i == 4 || i == 8 || i == 14 || i == 20)return false;

			return true;

}
int main(){

set<string> allp;
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
    myfile.open ("names.csv");
    string line;
    int cnt  = 0;
    while (std::getline(myfile, line))
    {
        std::istringstream ss(line);
  
        string name;
        int y =1;
       while(std::getline(ss, name, ',')) {
        if( ++y < 3|| name.size() <=2  || name.size() >= 10)continue;

        string stripped_name = name.substr(1, name.size()-2);
		for(int k=0; k<stripped_name.size()-1; k++){
			 string temp = stripped_name.substr(k,2);
			 allp.erase(temp);
		}
 		break;;
    }



    
}
    set<string> :: iterator it;

for(it = allp.begin(); it!= allp.end(); it++){
    	cout<<*it<<endl;
    }

cout<<allp.size()<<endl;
}
