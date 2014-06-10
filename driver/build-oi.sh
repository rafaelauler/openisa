#!/bin/bash
if [ x"$1" == x"" ]; then
    echo Missing db file.
    #echo Usage: $0 "<dbfile> [<resume iteration number>]"
    #echo ""
    exit
fi
export IFS=$'\n\r'
export GLOBIGNORE='*' 
db=($(cat $1))
if [ x"$2" == x"" ]; then
    beg=0
else
    beg=$2
fi
for var in $(seq $beg ${#db[@]}); do
    cur=${db[$var]}
    if [ x"${cur:0:3}" == x"cd " ] || 
       [ x"${cur:0:3}" == x"oi-" ] ||
       [ x"${cur:0:3}" == x"ln " ] ||
       [ x"${cur:0:3}" == x"rm " ] ||
       [ x"${cur:0:3}" == x"mkd" ] ||
       [ x"${cur:0:3}" == x"mip" ] ||
       [ x"${cur:0:3}" == x"exi" ]; then
        if [ x"${cur:0:28}" == x"mipsel-unknown-linux-gnu-gcc" ]; then
            cur=${cur/mipsel-unknown-linux-gnu-gcc/oi-cc}
        fi
        while [ x"${cur:$(expr length "$cur" - 1 )}" == x"\\" ]; do
            (( var = var + 1 ))
            cur=${cur:0:$(expr length "$cur" - 1)}${db[$var]}
            echo ...expanded to "$cur"
        done
        echo -ne -ne "\e[1;31m[\e[1;37m$(expr $var * 100 / ${#db[@]} )%\e[1;31m]\e[0m \e[1;32m[\e[1;37m@${var}\e[1;32m]\e[0m "$cur"\n"
        export GLOBIGNORE='' 
        eval $cur
        if [ $? -ne '0' ]; then
            echo Error @$var
            exit $?
        fi
        export GLOBIGNORE='*' 
        #make[5]: Entering directory `/l/home/rafael/disco2/rafael/archc/openisa/newlib/build-oi/oi-elf/newlib/libc/stdio'
    elif [ x"${cur:0:27}" == x"make[1]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[2]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[3]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[4]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[5]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[6]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[7]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[8]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[9]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[10]: Entering directory" ] ||
         [ x"${cur:0:27}" == x"make[11]: Entering directory" ]; then
        cur="cd '"${cur:29}
        echo "$cur"
        eval $cur
        if [ $? -ne '0' ]; then
            echo Error @$var
            exit $?
        fi
    else
        echo "Skipping: $cur"
    fi
done

