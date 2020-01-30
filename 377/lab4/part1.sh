#!/bin/bash
printf "%5s %-9s %5s %s\n" "PID" "USER" "RSS" "COMMAND"
for p in `ls -vd /proc/[0-9]*`; do
    if [ ! -f $p/status ]; then
        continue
    fi
    PID=${p/\/proc\//}
    USER=`stat -c %U $p`
    RSS=`grep "VmRSS" $p/status`
    if [ -n "$RSS" ]; then
        RSS=${RSS/'VmRSS:'/}
        RSS=${RSS/'kB'/}
    else
        RSS="0"
    fi
    CMD="$(cat $p/cmdline | tr '\000' ' ')"
    if [ -z "$CMD" ]; then
        CMD=`grep "Name" $p/status | tr -d '\t '`
	CMD=${CMD#"Name:"}
	CMD='['$CMD']'
    fi
    printf "%5s %-9s %5s " $PID $USER $RSS
    echo $CMD
done
