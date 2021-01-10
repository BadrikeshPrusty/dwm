# DWM(Dynamic Window Manager)
My build and config of DWM(Dynamic Window Manager). Fork from git://git.suckless.org/dwm + applied patches.

Patches applied:
1. activetagindicatorbar: To display rectangle on the tags if a window is opened on that tag.
2. actualfullscreen: To toggle fullscreen for a window without changing to monocle layout with a key-binding.
3. attachasideandbelow: To open a newly spawned window in stack area instead of master and also to spawn new window below the currently stack window instead of top.
4. cfacts: To add ability to resize stacked windows.
5. cfacts_bottomstack: To add a buttomstack(wide) layout with stacked windows resize capability.
6. cool-autostart: To autostart the applications on startup.
7. cyclelayouts: To cycle through all the layouts with a key-binding.
8. ewmhtags: To add a workspace like feature to tags so that other panels such as polybar can be used instead of inbuilt-panel.
9. fancybar: To display all the opened window names on the panel.
10. fixborders: To make the transparent borders of a window opaque for better visibility.
11. focusonnetactive: To add switch between windows from rofi menu.
12. pertag: For not to change the layout and config of other tags(workspaces) if changed on current.
13. restartsig: To restart dwm on the fly with a key-binding.
14. systray: To add systray capability on the panel.
15. uselessgap: To add empty gaps between the windows.


Dependencies:
1. dmenu(for run prompt, screenshot, power menu, and display fonts) (My build of dmenu: https://github.com/BadrikeshPrusty/dmenu)
2. rofi(To run .desktop files, switch between active windows and emoji-picker)
3. libxft-bgra-git(color emoji support for dmenu and dwm panel)
4. alacritty(terminal emulator)
5. picom(compositor for transparency)
6. scrot(screenshot application)
7. dwmblocks(to display time and other information on the panel)
8. network-manager-applet(to configure network connections)
9. volumeicon(systray icon to change volume)
10. feh(to set wallpapers)
11. xfce4-power-manager(to manager power settings)
12. xfce4-screensaver(for lock screen)
13. redshift(to change color temperature of the display)
14. dunst(for notifications)
15. polkit, polkit-gnome, gnome-keyring
16. Thunar(file manager)
17. Fonts: nerd-fonts-mononoki, ttf-hack, ttf-joypixels.
18. imagemagick(to display fonts)


Important Key-bindings:
1. Super + Enter          : Open a terminal(alacritty)
2. Super + q              : To close a window
3. Super + Shift + Enter  : To open file manager(thunar)
4. Super + r              : Run prompt(dmenu)
5. Super + d              : Run .desktop files(rofi)
6. Super + b              : Open browser (firefox)
7. Super + g              : Open Google-chrome
8. Super + w              : Open Window Swicher(rofi)
9. Super + Print          : Screenshot menu
10. Super + Shift + p     : Power menu
11. Super + Shift + r     : Restart Window manager
12. Super + Shift + x     : Exit window manager


To Install:
1. git clone https://github.com/BadrikeshPrusty/dwm.git
2. cd dwm
3. make
4. sudo make clean install
