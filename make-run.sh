#!/bin/sh

# 実行ファイル作成
make

START=0
END=$START

# 対象ファイルを指定できる
while getopts p:s:e: OPT
do
    case $OPT in
        "p" ) START="$OPTARG"; END=$START;;
        "s" ) START="$OPTARG";;
        "e" ) END="$OPTARG";;
    esac
done

# 指定がないなら、存在するファイルすべて対象
if [ $START = 0 ]; then
    count=0
    i=0
    while :
    do
        i=`expr $i + 1`
        if [ ! -e test-data/test$i ]; then
            break;
        fi
        if [ ! -e test-data/ans$i ]; then
            break;
        fi
        count="$i"
    done

    if [ $count != 0 ]; then
        START=1
        END="$count"
        echo "START:$START END:$END"
    fi
fi

# 指定範囲のファイルを入力して、出力を評価する
for i in `seq $START $END`
do
    echo "----- test$i -----"
    OUT=`cat test-data/test$i | ./main`
    EXPECT=`cat test-data/ans$i`

    echo "- INPUT -"
    cat test-data/test$i
    if test "$OUT" = "$EXPECT" ; then
        printf "\e[36m%s\n\e[m" "- RESULT: OK -"
        echo "OUT: $OUT"
    else
        printf "\e[31m%s\n\e[m" "- RESULT: NG -"
        echo "OUT: $OUT"
        echo "EXPECT: $EXPECT"
    fi
done

