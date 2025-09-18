/*
============================================================================
Name :15.c
Author : Rushil Khatri
Description :a program to display the environmental variable of the user
Date: 6th Sept, 2025.
============================================================================
*/
#include<stdio.h>
extern char **environ;
int main(void)
{
for(char ** tem=environ;*tem;++tem)
{
puts(*tem);
}
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
SHELL=/bin/bash
SESSION_MANAGER=local/rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:@/tmp/.ICE-unix/1537,unix/rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:/tmp/.ICE-unix/1537
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
GNOME_KEYRING_CONTROL=/run/user/1000/keyring
GNOME_SHELL_SESSION_MODE=ubunt
============================================================================
*/