#!/bin/bash

NORM=$(norminette cmd game utils | grep -w Error)
ERRS=$( echo "${NORM}" | grep -w Error:)
ERRS_COUNT=$( echo "${ERRS}" | wc -l)
ERRS_LEN=$( echo "${NORM}" | wc -c)

if [[ $ERRS_LEN -eq 1 ]]
then
  	echo "\nPROJECT CHECK SUCCESS!\n"
else
	echo "\nERRORS CHECKER ${ERRS_COUNT}\n"
	echo "${NORM}"
fi
