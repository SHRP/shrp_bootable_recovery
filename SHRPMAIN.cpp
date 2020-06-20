#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include "twcommon.h"
#include "twrp-functions.hpp"
#include "SHRPMAIN.hpp"
#include "data.hpp"
#include "gui/gui.hpp"

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
	}
	TWFunc::Exec_Cmd("mount -w "+PartitionManager.Get_Android_Root_Path(),display);
	if(display){
		gui_msg("remount_system_rw=[i] Remounted system as R/W!");
	}
}


//Text Editor Funcs()
int textEditor::getLineNo(string path){
	int line=1;
	string tmp;
	fstream file;
	file.open(path.c_str(),ios::in);
	if(file){
		while(getline(file, tmp)){
			line++;
		}
	}else{
		return 0;
	}
	file.close();
	return line-1;
}

string textEditor::handleTab(string str){
	int tmp1=str.find_first_of('\t');
	while(tmp1!=-1){
		str[tmp1]=' ';
		str.insert(tmp1,"  ");
		tmp1=str.find_first_of('\t');
	}
	return str;
}

void textEditor::disp_file(string path){
	fstream file;
	string tmp;
	int line_no=1;
	file.open(path.c_str(),ios::in);
	if(file){
		tmp="Text File - "+path;
		gui_msg(Msg(tmp.c_str(),0));
		while(getline(file, tmp)){
			{
      	stringstream guun;
        string t;
        guun<<line_no;
        guun>>t;
				tmp=handleTab(tmp);
        tmp=t+" "+tmp;
				gui_msg(Msg(tmp.c_str(),0));
      }
      line_no++;
    }
	}
	file.close();
}

void textEditor::getdString(string path,string &text1,string &text2,int line,int arg){
	fstream file;
	string tmp;
	int line_no=1;
	int fileLineNo=getLineNo(path);
	int swt=1;
	if(line>fileLineNo){
		swt=0;
	}else if(line<line_no){
		line=1;
	}
	file.open(path.c_str(),ios::in);
	if(file&&swt){
		while(getline(file,tmp)){
			if(line_no<line){
				text1+=tmp+"\n";
			}
			if(arg==1&&line_no==line){
				text2+=tmp+"\n";
			}
			if(line_no>line){
				text2+=tmp+"\n";
			}
			line_no++;
		}
	}else if(file){
		while(getline(file,tmp)){
			text1+=tmp+"\n";
		}

	}
	file.close();
}

void textEditor::getReplacebleLine(string path,int line){
	fstream file;
	string tmp;
	int line_no=1;
	if(line<=line_no){
		line=1;
	}
	file.open(path.c_str(),ios::in);
	if(file){
		while(getline(file,tmp)){
			if(line_no==line){
				break;
			}
			line_no++;
		}
		if(line_no<line){
				tmp=" ";
		}else{
				tmp=handleTab(tmp);
		}
		DataManager::SetValue("replaceText",tmp.c_str());
	}
	file.close();
}

void textEditor::pushString(string path,string text){
	fstream file;
	file.open(path.c_str(),ios::out);
	file<<text;
	file.close();
}

void textEditor::replaceLine(string path,string rtext,int line){
	string up,down;
	getdString(path,up,down,line,0);
	rtext=up+rtext+"\n"+down;
	pushString(path,rtext);
}

void textEditor::addLine(string path,string rtext,int line){
	string up,down;
	getdString(path,up,down,line,1);
	rtext=up+rtext+"\n"+down;
	pushString(path,rtext);
}

void textEditor::removeLine(string path,int line){
	string up,down;
	getdString(path,up,down,line,0);
	up=up+down;
	pushString(path,up);
}



//Theme Parser
void ThemeParser::pushValues(){
	DataManager::SetValue("c_white",bgColor.c_str());
	DataManager::SetValue("nav_bg",navBgColor.c_str());
	DataManager::SetValue("c_black",textColor.c_str());
	DataManager::SetValue("c_acc_color_val",accColor.c_str());
}
void ThemeParser::processValue(string line,int arg){
	line=line.substr(line.find_last_of("=")+1,line.length());
	switch(arg){
		case 0:themeName=line;
		break;
		case 1:bgColor=line;
		break;
		case 2:navBgColor=line;
		break;
		case 3:accColor=line;
		break;
		case 4:textColor=line;
		break;
	}
	LOGINFO("SHRP THEME PARSHER: %s\t %s\t %s\t %s\t %s\n",themeName.c_str(),bgColor.c_str(),navBgColor.c_str(),accColor.c_str(),textColor.c_str());
}
void ThemeParser::fetchInformation(string path){
	string tmp;
	fstream file;
	LOGINFO("SHRP THEME PARSHER: Theme Path %s\n",path.c_str());
	file.open(path.c_str(),ios::in);
	if(file){
		int i=0;
		while(getline(file,tmp)){
			processValue(tmp,i++);
		}
	}
}
bool ThemeParser::verifyColor(string arg){
	int tmp=arg.length();
	if((tmp==7||tmp==9)&&arg[0]=='#'){
	}else{
		LOGINFO("SHRP THEME PARSHER: Incorrect Hex Format..(#)\n");
		return false;
	}
	tmp--;
	//tmp=-2;
	while(tmp!=0){
		if(!(arg[tmp]=='1'||arg[tmp]=='2'||arg[tmp]=='3'||arg[tmp]=='4'||arg[tmp]=='5'||arg[tmp]=='6'||arg[tmp]=='7'||arg[tmp]=='8'||arg[tmp]=='9'||arg[tmp]=='0'||arg[tmp]=='A'||arg[tmp]=='a'||arg[tmp]=='B'||arg[tmp]=='b'||arg[tmp]=='C'||arg[tmp]=='c'||arg[tmp]=='D'||arg[tmp]=='d'||arg[tmp]=='E'||arg[tmp]=='e'||arg[tmp]=='F'||arg[tmp]=='f')){
			LOGINFO("SHRP THEME PARSHER: Incorrect Hex Format..(value)\n");
			return false;
		}
		tmp--;
	}
	return true;
}

bool ThemeParser::verifyInformation(){
	LOGINFO("SHRP THEME PARSHER: Verifing theme data..\n");
	if(verifyColor(bgColor)&&verifyColor(accColor)&&verifyColor(textColor)){
		return true;
	}else{
		return false;
	}
}