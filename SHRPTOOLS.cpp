//#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
//#include <sstream>
//#include <fstream>
#include "twcommon.h"
//#include "variables.h"
#include "twrp-functions.hpp"
//#include "data.hpp"
#include "gui/gui.hpp"

#include "SHRPTOOLS.hpp"

//SHRP minUtils
bool minUtils::compare(string str1,string str2){
    transform(str1.begin(),str1.end(),str1.begin(), ::tolower);
    transform(str2.begin(),str2.end(),str2.begin(), ::tolower);
    return (str1==str2) ? true : false;
}

bool minUtils::isFileEditable(string fileExtension){
    string extensions[]={".txt",".xml",".prop",".sh"};
    int sizeArr=sizeof(extensions)/sizeof(extensions[0]);
    for(int i=0;i<sizeArr;i++){
        if(compare(fileExtension,extensions[i])){
            return true;
        }
    }
    return false;
}

bool minUtils::find(std::string str,std::string sub){
	if(str.find(sub)>str.length()){
		return false;
	}else{
		return true;
	}
}
bool minUtils::find(std::string str,std::string sub,int dummy){
	transform(str.begin(),str.end(),str.begin(), ::tolower);
	if(str.find(sub)>str.length()){
		return false;
	}else{
		return true;
	}
}

void minUtils::remountSystem(bool display){
	if(PartitionManager.Is_Mounted_By_Path(PartitionManager.Get_Android_Root_Path())){
	  	PartitionManager.UnMount_By_Path(PartitionManager.Get_Android_Root_Path(),false);
	  	unlink("/system");
		mkdir("/system", 0755);
	}
	TWFunc::Exec_Cmd("mount -w "+PartitionManager.Get_Android_Root_Path(),display);
	if(display){
		gui_msg("remount_system_rw=[i] Remounted system as R/W!");
	}
}