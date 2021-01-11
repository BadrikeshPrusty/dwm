/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const unsigned int gappih    = 3;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 3;       /* vert inner gap between windows */
static const unsigned int gappoh    = 3;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 3;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]     = {"Mononoki Nerd Font:style=Bold:size=12:antialias=true:autohint=true",
                                  "Hack:size=12:antialias=true:autohint=true",
                                  "JoyPixels:size=12:antialias=true:autohint=true"};

static const char dmenufont[]       = "NotoMonoRegular:bold:pixelsize=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_white[]       = "#ffffff";
static const char col_cyan[]        = "#005577";
static const char col_red[]         = "#ff0d0d";
//static const char col_brown[]       = "#b55b00";
static const char col_brown[]       = "#c76400";

static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_white, col_brown, col_brown },
};

static const char *const autostart[] = {
    "feh", "--bg-fill", "/home/badrikesh/Pictures/wallpapers/moon_orbiting_earth-wallpaper-3840x2160.jpg", NULL,
//    "dwmblocks", NULL,
    "nm-applet", NULL,
    "volumeicon", NULL,
    "xfce4-power-manager", NULL,
    "picom", "-b", "--config", "/home/badrikesh/.config/qtile/scripts/picom.conf", NULL,
    "/home/badrikesh/.config/dwm/scripts/date-bat-status.sh", NULL,
    "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
    "dunst", NULL,
    "redshift", "-P", "-O", "3500", NULL,
    "xinput", "set-prop", "Elan Touchpad", "libinput Tapping Enabled", "1", NULL,
    "xinput", "set-prop", "Elan Touchpad", "libinput Natural Scrolling Enabled", "1", NULL,
    NULL /* terminate */
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            1,           -1 },
  //{ "firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
    { "firefox",  NULL,       NULL,       0,            0,           -1 },
    { "Sxiv",     NULL,       NULL,       0,            1,           -1 },
    { "Pavucontrol",   NULL,       NULL,       0,            1,           -1 },
    { "Qalculate-gtk", NULL,       NULL,       0,            1,           -1 },
    { "Display",  NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "TTT",      bstack },
	{ "[M]",      monocle },
//	{ "[@]",      spiral },
//	{ "[\\]",     dwindle },
//	{ "H[]",      deck },
//	{ "===",      bstackhoriz },
//	{ "HHH",      grid },
//	{ "###",      nrowgrid },
//	{ "---",      horizgrid },
//	{ ":::",      gaplessgrid },
//	{ "|M|",      centeredmaster },
//	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-i", "-p", "Run: ", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *filemanager[] = {"thunar", NULL};
static const char *browser[] = {"firefox", NULL};
static const char *browser2[] = {"google-chrome-stable", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = filemanager } },
    { MODKEY,                       XK_b,      spawn,          {.v = browser} },
    { MODKEY,                       XK_g,      spawn,          {.v = browser2} },
//  { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
    { MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
    { MODKEY,                       XK_Down,   focusstack,     {.i = +1 } },
    { MODKEY,                       XK_Up,     focusstack,     {.i = -1 } },
//  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//  { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY|ControlMask,           XK_Left,   setmfact,       {.f = -0.05} },
    { MODKEY|ControlMask,           XK_Right,  setmfact,       {.f = +0.05} },
    { MODKEY|ControlMask,           XK_Up,     setcfact,       {.f = +0.25} },
    { MODKEY|ControlMask,           XK_Down,   setcfact,       {.f = -0.25} },

    { MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
    { MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
    { MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
    { MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
    { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
    { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
    { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
    { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_y,      incrohgaps,     {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_o,      incrohgaps,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },

    //  { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
    { MODKEY|ShiftMask,             XK_Up,     zoom,           {0} },
    { MODKEY|ShiftMask,             XK_Left,   zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { Mod1Mask,                     XK_Tab,    view,           {0} },
    { MODKEY,                       XK_q,      killclient,     {0} },
    { MODKEY,                       XK_t,      spawn,          {.v = termcmd} },
//  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
//  { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
//  { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
//  { MODKEY|ControlMask,           XK_comma,  cyclelayout,    {.i = -1 } },
//  { MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
    { MODKEY,                       XK_space,  cyclelayout,    {.i = +1 } },
//  { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
//  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
//  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
//  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
//  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
//  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
//  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_x,      quit,           {0} },
    { MODKEY|ShiftMask,             XK_r,      quit,           {1} },

    { MODKEY,                       XK_d,      spawn,          SHCMD("rofi -show drun") },
//  { MODKEY,                       XK_w,      spawn,          SHCMD("rofi -show window") },

    { MODKEY,                       XK_h,      spawn,          SHCMD("alacritty -e htop") },

    { MODKEY,                       XK_p,      spawn,          SHCMD("~/.config/dwm/scripts/picom-toggle.sh") },
    { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("~/.config/dwm/scripts/power-menu.sh") },
    { MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("~/.config/dwm/scripts/fonts-dmenu.sh") },
    { MODKEY,                       XK_e,      spawn,          SHCMD("~/.config/dwm/scripts/emoji-rofi.sh") },

    { 0, XK_Print, spawn, SHCMD("scrot -f '%d-%m-%y@%H-%M-%S.png' -e 'mv $f ~/Pictures/screenshots/' && notify-send 'Entire screen captured'") },
    { MODKEY,                       XK_Print,  spawn,             SHCMD("~/.config/dwm/scripts/scrot-dmenu.sh") },

    { 0,                       XF86XK_MonBrightnessUp,    spawn,  SHCMD("xbacklight -inc 5") },
    { 0,                       XF86XK_MonBrightnessDown,  spawn,  SHCMD("xbacklight -dec 5") },
    { 0,                       XF86XK_AudioMute,          spawn,  SHCMD("amixer -q set Master toggle") },
    { 0,                       XF86XK_AudioLowerVolume,   spawn,  SHCMD("amixer -q set Master 5%-") },
    { 0,                       XF86XK_AudioRaiseVolume,   spawn,  SHCMD("amixer -q set Master 5%+") },

    { 0,                       XF86XK_AudioPlay,          spawn,  SHCMD("playerctl play-pause") },
    { 0,                       XF86XK_AudioNext,          spawn,  SHCMD("playerctl next") },
    { 0,                       XF86XK_AudioPrev,          spawn,  SHCMD("playerctl previous") },
    { 0,                       XF86XK_AudioStop,          spawn,  SHCMD("playerctl stop") },

    { 0,                       XF86XK_TouchpadToggle,     spawn,  SHCMD("~/.config/dwm/scripts/touchpad-toggle.sh") },
    { 0,                       XF86XK_ScreenSaver,        spawn,  SHCMD("xfce4-screensaver-command --lock") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

