#!/bin/sh
printf "\r\n--Executing tunnel script--\r\n"
printf "\r\nrequired sshpass to execute oracle-sql-developer-ssh-tunnel.sh\r\n"
sshpass -p HaeJ7Aiy ssh -L 1521:localhost:1521 tunnel_ext_simbirsoft@178.170.172.149 -N &
printf "\n\rdone\r\n"
printf "\n\ruse this to kill process:\r\nps sudo kill -9 <pid>\r\n"