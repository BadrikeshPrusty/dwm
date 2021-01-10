#! /bin/bash


while true
do
    BAT_PERC=$(cat /sys/class/power_supply/BAT0/capacity)
    BAT_STAT=$(cat /sys/class/power_supply/BAT0/status)
    DATE=$(date +"%a, %b %-d %Y, %H:%M") 

    case "$BAT_STAT" in
        "Charging") BAT_STAT="⚡ " ;;
        "Not charging") BAT_STAT="⚡ " ;;
        *) BAT_STAT="";;
    esac

    xsetroot -name "   $BAT_STAT$BAT_PERC% | $DATE |"

    sleep 10
done
