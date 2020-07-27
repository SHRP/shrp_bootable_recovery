
//SHRP minUtils
class minUtils{
    public:
        static bool compare(string str1,string str2);
        static bool isFileEditable(string fileExtension);
        static bool find(std::string str,std::string sub);
		static bool find(std::string str,std::string sub,int dummy);
		static void remountSystem(bool display);
};