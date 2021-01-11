# DWM(Dynamic Window Manager)
My build and config of DWM(Dynamic Window Manager). Fork from git://git.suckless.org/dwm + applied patches.

Patches applied:
1. activetagindicatorbar: To display rectangle on the tags if a window is opened on that tag.
2. actualfullscreen: To toggle fullscreen for a window without changing to monocle layout with a key-binding.
3. attachasideandbelow: To open a newly spawned window in stack area instead of master and also to spawn new window below the currently stack window instead of top.
4. cfacts-vanitygaps: To add all the layouts, resize stack windows, inner and outer gaps.
5. cool-autostart: To autostart the applications on startup.
6. cyclelayouts: To cycle through all the layouts with a key-binding.
7. fixborders: To make the transparent borders of a window opaque for better visibility.
8. pertag: For not to change the layout and config of other tags(workspaces) if changed on current.
9. restartsig: To restart dwm on the fly with a key-binding.
10. systray: To add systray capability on the panel.


Dependencies:
1. dmenu(for run prompt, screenshot, power menu, and display fonts) (My build of dmenu: https://github.com/BadrikeshPrusty/dmenu)
2. rofi(To run .desktop files and emoji-picker)
3. libxft-bgra-git(color emoji support for dmenu and dwm panel)
4. alacritty(terminal emulator)
5. picom(compositor for transparency)
6. scrot(screenshot application)
7. network-manager-applet(to configure network connections)
8. volumeicon(systray icon to change volume)
9. feh(to set wallpapers)
10. xfce4-power-manager(to manager power settings)
11. xfce4-screensaver(for lock screen)
12. redshift(to change color temperature of the display)
13. dunst(for notifications)
14. polkit, polkit-gnome, gnome-keyring
15. Thunar(file manager)
16. Fonts: nerd-fonts-mononoki, ttf-hack, ttf-joypixels.
17. imagemagick(to display fonts)


Important Key-bindings:
1. Super + Enter          : Open a terminal(alacritty)
2. Super + q              : To close a window
3. Super + Shift + Enter  : To open file manager(thunar)
4. Super + r              : Run prompt(dmenu)
5. Super + d              : Run .desktop files(rofi)
6. Super + b              : Open browser (firefox)
7. Super + g              : Open Google-chrome
8. Super + Print          : Screenshot menu
9. Super + Shift + p     : Power menu
10. Super + Shift + r     : Restart Window manager
11. Super + Shift + x     : Exit window manager


To Install:
1. git clone https://github.com/BadrikeshPrusty/dwm.git
2. cd dwm
3. make
4. sudo make clean install
