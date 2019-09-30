#!/bin/bash


rm -rf BUILD
cd ~/gap_sdk
#source init.sh
source sourceme.sh
cd -

#make dis > prova.s
x-terminal-emulator -e python3 plot.py
make clean all run 

