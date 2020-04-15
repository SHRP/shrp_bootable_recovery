#!/bin/sh
# Restore script for SHRP injection
# Part of this code belongs to TWRP's update-binary

# Let's set a quick escape room in case of errors.
set -e;

# target partition without the slot suffix
target=/dev/block/bootdevice/by-name/boot;
# tmp folder, in order to not mess up
tmp=/dev/tmp/shrpinj;

# let's cd into tmp
cd $tmp;

# Check that every dir still exist
test "$tmp/new_a";
test "$tmp/new_b";
test "$tmp/old_a";
test "$tmp/old_b";

# Let's backup new boot imgs firstly
for slot in a b; do
  slot=_$slot;
  cd new$slot;
  dd if=$target$slot of=boot.img;
  magiskboot unpack -h boot.img;
  cd $tmp;
done

# Fun part: replace every ramdisk.cpio, then reflash everything
for slot in a b; do
  slot=_$slot;
  rm -rf new$slot/ramdisk.cpio;
  mv old$slot/ramdisk.cpio new$slot/ramdisk.cpio;

  # kernel string want_initramfs -> skip_initramfs (Magisk)
  $tool hexpatch kernel 77616E745F696E697472616D6673 736B69705F696E697472616D6673;
  # kernel string trip_initramfs -> skip_initramfs (SuperSU)
  $tool hexpatch kernel 747269705F696E697472616D6673 736B69705F696E697472616D6673;

  # boot.img header cmdline remove skip_override (flar2 patch)
  sed -i "s|$(grep '^cmdline=' header | cut -d= -f2-)|$(grep '^cmdline=' header | cut -d= -f2- | sed -e 's/skip_override//' -e 's/  */ /g' -e 's/[ \t]*$//')|" header;

  $tool repack boot.img;
  cat new-boot.img /dev/zero > $target$slot 2>/dev/null || true;
  $tool cleanup;
  rm -f new-boot.img;
done;

# Cleanup!
cd /;
rm -rf /dev/tmp;
