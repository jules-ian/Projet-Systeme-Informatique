#!/bin/bash

TMP=`mktemp`

trap "exit 1" TERM
export SPID=$$ # Script PID

function err() {
  echo $1
  rm -rf lex.c lex $TMP
  kill -s TERM $SPID
  #exit 1
}

flex -o lex.c lex.l || (err "step invalid: flex")
gcc -Wall -Werror lex.c -o lex || (err "step invalid: gcc")
rm lex.c

for f in samples/*.c; do
  ./lex $f > $TMP
  diff $TMP $f.out || err "invalid test $f"
done

