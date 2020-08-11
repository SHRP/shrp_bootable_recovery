//Text Editor Class
class textEditor{
	private:
		void pushString(string,string);									//push the processed strings into the file
	public:
		void disp_file(string);													//displays the content of the file in the console
		void replaceLine(string,string,int);						//replaces specific line into the file
		void addLine(string,string,int);								//adds specific line into the file
		void removeLine(string,int);										//removes specific line from the file
		void getdString(string,string&,string&,int,int);//divides the file in two strings according to the parameter
		void getReplacebleLine(string,int);							//finds the line which are going to be replace
		string handleTab(string str);										//handles Tab character
		int getLineNo(string path);											//process total line of text file
};

//Parse Theme
class ThemeParser{
	private:
		string themeName;
		string bgColor;
		string navBgColor;
		string accColor;
		string textColor;
		void processValue(string,int);
		bool verifyColor(string);
	public:
		void fetchInformation(string);
		bool verifyInformation();
		void pushValues();
};

//JSON_Genarator
class JSON{
	public:
		static string getVar(string,string);
		static string getVar(string,int);
		static string getVar(string,float);
		static string genarateRAWJson();
		static void storeShrpInfo();
};

//EXPRESS Class
class Express{
	public:
#ifdef SHRP_EXPRESS
		static bool shrpResExp(string inPath,string outpath,bool display = true);
		static void flushSHRP();
		static void init(string basePath);
#endif
		static void updateSHRPBasePath();
};

#define BUFFER_SIZE_SLT 16
#define BUFFER_SIZE_PW 64

//Hasher Class
class Hasher{
	private:
		std::string arg,fsalt,fhash,chash;
		char getlp[1];
		char getfs[BUFFER_SIZE_SLT];
		char gethp[BUFFER_SIZE_PW];
	public:
		string lock_pass;
		static string create_sha256(const string str);
		static string create_salt( size_t length );
		bool LockPassInit(string str);
		bool isPassCorrect();
		static string doHash(string str);
};

//SIG Helpers
struct storageInfo{
	string storageLocation;
	string freeStrVar;
	string freePercentageVar;
};

void process_space(int size,int free,storageInfo storage);