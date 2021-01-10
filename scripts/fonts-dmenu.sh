#!/bin/bash

DMENU="dmenu -i -l 20 -p "Fonts:""

choice=$(fc-list | cut -d ":" -f 1 | rev | cut -d '/' -f 1 | rev | $DMENU)

if [ -n "$choice" ]
then
    display "$(fc-list | cut -d ":" -f 1 | grep "$choice")"
fi
