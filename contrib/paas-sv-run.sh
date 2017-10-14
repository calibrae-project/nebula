#!/bin/bash

# if all of the reader nodes die, kill runsv causing the container to exit
if [[ "$USE_MULTICORE_READONLY" ]]; then
  NEBULA_READONLY_PIDS=`pgrep -f read-only`
  if [[ ! $? -eq 0 ]]; then
  	echo NOTIFYALERT! nebula reader nodes have quit unexpectedly, starting a new instance..
    RUN_SV_PID=`pgrep -f /etc/service/nebula`
    kill -9 $RUN_SV_PID
  fi
fi

# if the writer node dies, kill runsv causing the container to exit
NEBULA_PID=`pgrep -f p2p-endpoint`
if [[ ! $? -eq 0 ]]; then
  echo NOTIFYALERT! nebula has quit unexpectedly, checking for core dump and then starting a new instance..
  sleep 30
  SAVED_PID=`cat /tmp/nebulapid`
  if [[ -e /tmp/core.$SAVED_PID ]]; then
    gdb --batch --quiet -ex "thread apply all bt full" -ex "quit" /usr/local/nebula-full/bin/nebula /tmp/core.$SAVED_PID >> /tmp/stacktrace
    STACKTRACE=`cat /tmp/stacktrace`
    echo NOTIFYALERT! nebulasync stacktrace from coredump:
    for ((i=0;i<${#STACKTRACE};i+=120)); do
      echo "${STACKTRACE:i:120}"
    done
    CORE_FILE_NAME=coredump-`date '+%Y%m%d-%H%M%S'`.$SAVED_PID
    aws s3 cp /tmp/core.$SAVED_PID s3://$S3_BUCKET/$CORE_FILE_NAME
  fi
  RUN_SV_PID=`pgrep -f /etc/service/nebula`
  kill -9 $RUN_SV_PID
fi

# check on this every 10 seconds
sleep 10
