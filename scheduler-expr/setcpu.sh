#!/bin/bash
nicepid=$(ps -eo pid,comm | grep nice | awk '{print $1}')
rudepid=$(ps -eo pid,comm | grep rude | awk '{print $1}')
taskset -cp 0 $nicepid
taskset -cp 0 $rudepid

