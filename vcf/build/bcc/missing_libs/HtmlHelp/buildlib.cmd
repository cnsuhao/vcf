@echo off
@del HHCtrl.obj
@del HtmlHelp.lib
@bcc32 -tWD -6 -v- -O2 -a8 -DWIN32;_LIB -c HHctrl.c 
@tlib HtmlHelp.lib /a HHCtrl.obj