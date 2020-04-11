#!/bin/sh
# Backup script for SHRP injection
# Part of this code belongs to TWRP's update-binary

# Let's set a quick escape room in case of errors.
set -e;

# target partition without the slot suffix
target=/dev/block/bootdevice/by-name/boot;
# tmp folder, in order to not mess up
tmp=/dev/tmp/shrpinj;
rm -rf $tmp;
mkdir -p $tmp;

# let's cd into tmp
cd $tmp;

# Let's make some other folders
mkdir old_a;
mkdir old_b;
mkdir new_a;
mkdir new_b;

# cd into old dirs firstly, and run everything that's necessary, plus delete unnecessary files
for slot in a b; do
  slot=_$slot;
  cd old$slot;
  dd if=$target$slot of=boot.img;
  magiskboot unpack -h boot.img;
  rm -rf header kernel kernel_dtb boot.img;
  cd $tmp;
done;
