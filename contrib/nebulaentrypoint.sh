#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start NEBULA traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/NEBULA
  cp /usr/local/bin/steem-sv-run.sh /etc/service/NEBULA/run
  chmod +x /etc/service/NEBULA/run
  runsv /etc/service/NEBULA
else
  /usr/local/bin/startpaasnebula.sh
fi
