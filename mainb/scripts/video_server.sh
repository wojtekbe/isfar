#!/bin/sh
while true
do
	raspivid -t 999999 -w 1280 -h 720 -hf -fps 20 -o - | nc -l 9999
done
