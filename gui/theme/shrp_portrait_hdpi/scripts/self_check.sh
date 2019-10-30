#!/bin/bash
OUTFD=$2
ui_print() 
{
echo -n -e "ui_print $1\n" >> /proc/self/fd/$OUTFD
echo -n -e "ui_print\n" >> /proc/self/fd/$OUTFD
}
if [ -d "/sdcard" ]; 
then
	if [ -d "sdcard/SHRP" ]; 
	then
		ui_print "SHRP Folder Found"
		if [ -d "sdcard/SHRP/cookies" ]; 
		then
			ui_print "AIK Found"
			if [ -f "sdcard/SHRP/recovey.img" ]; 
			then
				ui_print "Recovery Found"
				exit 0;
			else
				ui_print "Backed Up Rec Not Found. Please Install Your SHRP Zip."
				exit 1;
			fi
		else
			ui_print "AIK Not Found. Please Install Your SHRP Zip."
			exit 1;
		fi
	else
		ui_print "SHRP Folder Not Found. Please Install Your SHRP Zip."
		exit 1;
	fi
else
	ui_print "Data Maybe Encrypted\nFailed While Init"
	exit 1;
fi