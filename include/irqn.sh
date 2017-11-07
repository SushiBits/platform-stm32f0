#!/bin/bash

LIST="$(cat | egrep "_IRQn *=" | sed -E "s/^  ([A-Za-z0-9_]*)_IRQn *= ([0-9\\-]*).*$/\2 \1/" | sort -n)"
COUNT=$(echo "$LIST" | tail -n1 | cut -d " " -f1)

for idx in $(seq -14 $COUNT); do
    LINE="$(echo "$LIST" | egrep -- "^$idx ")"
    if [ "$LINE" != "" ]; then
        echo $LINE | sed -E "s/([0-9\-]*) (.*)/IRQN_HANDLER(\1, \2_IRQn)/"
    else
        echo SKIP_HANLDER\($idx\)
    fi
done
