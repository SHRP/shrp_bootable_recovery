#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include "gui/gui.h"
#include "gui/pages.h"
#include "twcommon.h"
using namespace std;

#include "SHRPTOOLS.hpp"

void processRefPlacement(int* var, bool isPlus, int refval){
    int tmp=*var;
    if(isPlus){
        *var = tmp + refval;
    }else{
        *var = tmp - refval;
    }
}
string getExtension(string str,string arg="."){
	int dotPos=str.find_last_of('.');
	if(dotPos == -1 || dotPos== (int) str.length()-1){
		return "none";
	}else{
		return (arg+str.substr(dotPos+1, str.length() - dotPos));
	}
}

vector<string> fetchExtn(string str){
    vector<string> extensions;
    string tmp;
    int pos;
    if( (int)str.find_first_of(',') != -1){
        do{
            pos=str.find_first_of(',');
            extensions.push_back(str.substr(0,pos));
            str=str.substr(pos+1,str.length());
        }while( (int)str.find_first_of(',') != -1);
        pos=str.find_first_of(',');
        extensions.push_back(str.substr(0,pos));
    }else{
        extensions.push_back(str);
    }
    return extensions;
}


bool isExtnMatched(vector<string> extn,string fileName){
    vector<string>::iterator ptr;
    string fileExtn=getExtension(fileName);
    //LOGINFO("File Extension : %s\n",fileExtn.c_str());
    for(ptr=extn.begin();ptr<extn.end();ptr++){
        //LOGINFO("Comparing %s with %c\n",fileExtn.c_str(),*ptr->c_str());
        if(minUtils::compare(fileExtn,*ptr)){
            return true;
        }
    }
    return false;
}