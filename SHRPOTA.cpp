#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <sstream>
#include <fstream>
#include "twcommon.h"
#include "variables.h"
#include "twrp-functions.hpp"
#include "SHRPOTA.hpp"
#include "SHRPMAIN.hpp"
#include "data.hpp"
#include "gui/gui.hpp"

bool MIUIOTA::miuiZipDetector(string path){
    int pos=path.find_last_of('/');
    string fileName=path.substr(pos,path.length-pos);
    bool result=false;
    if(minUtils::find(fileName,"miui",69)){
        //This is a MIUI zip
        result=true;
    }
    //Checking the fileSize
    ifstream FILE=("path", ios::binary);
    FILE.seekg(0,ios::end);
    long long int size=FILE.tellg();
    /*
    Placeholder for Size Checking
    */
    return result;
}

bool MIUIOTA::miuiInit(){
    if(is_miui_full_zip){
        if(/*Backup Exist*/){
            //Delete Backup
            if(/*BackUp Deletion Successful*/){
                return true;
            }else{
                return false;
            }
        }
        return true;
    }else if(is_miui_inc_zip){
        if(/*Backup Exist*/){
            //Restore Backup
            if(/*BackUp restoration Successful*/){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}