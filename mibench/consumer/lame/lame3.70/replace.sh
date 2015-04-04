#!/bin/bash
OLD="fprintf(ofile,"
NEW="printf("
DPATH="/home/rafael/p/openisa/mibench/consumer/lame/lame3.70/*.c"
BPATH="/home/rafael/backup"
TFILE="/tmp/out.tmp.$$"
[ ! -d $BPATH ] && mkdir -p $BPATH || :
for f in $DPATH
do
  echo $f
  if [ -f $f -a -r $f ]; then
    /bin/cp -f $f $BPATH
   sed "s/$OLD/$NEW/g" "$f" > $TFILE && mv $TFILE "$f"
  else
   echo "Error: Cannot read $f"
  fi
done
/bin/rm $TFILE
