#!/bin/bash

DMENU="dmenu -i -p "Power:""
choice=$(echo -e "Lock\nSuspend\nHibernate\nLogout\nReboot\nShutdown\n" | $DMENU)

case "$choice" in
    Logout)
        killall dwm
        ;;
   
    Shutdown)
        systemctl poweroff
        ;;
      
    Reboot)
        systemctl reboot
        ;;
      
    Suspend)
        systemctl suspend
        ;;
      
    Hibernate) 
        systemctl hibernate
        ;;

    Lock)
        xfce4-screensaver-command --lock
        ;;
esac
