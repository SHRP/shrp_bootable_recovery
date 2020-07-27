class MIUIOTA{
    public:
        //Variables
        bool is_miui_full_zip;
        bool is_miui_inc_zip;
        bool is_miui_bak_exists;
        //Functions
        bool miuiZipDetector(string path);
        bool miuiInit();
        bool miuiFinal();
};