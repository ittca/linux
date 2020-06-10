#!/bin/bash
# this bash file if with executable permissions is placed in /usr/bin/ will creat a new terminal command "t"
# t has some options that run my personal most executed commands with just a 2 or 3 caracters
# this file can be modified, for example to remove, add or edit commands
# to check options just enter on the terminal "t h"

if [ -n "$1" ]; then
	for arg
	do
		case "$arg" in
			a)
				sudo apt autoremove
				break
				;;
			c)
				if [ -n "$2" ]; then
					rm a.out
					clear
					gcc $2
					./a.out
					break
				else
					echo "please enter the file name"
				fi
				;;
			i)
				if [ -n "$2" ]; then
					sudo apt install $2
					break
				else
					echo "please enter a program to install"
				fi
				;;
			m)
				clear
				neofetch
				free -m
				break
				;;
			r)
				if [ -n "$2" ]; then
					sudo apt remove $2
					break
				else
					echo "please enter a program to remove"
				fi
				;;
			s)
				if [ -n "$2" ]; then
					apt search $2
					break
				else
					echo "please enter a program to search"
				fi
				;;
			u)
				clear
				sudo apt update
				sudo apt upgrade
				break
				;;
			*)
				echo ""
				echo "options:"
				echo "a	sudo apt autoremove -y"
				echo "c	gcc program_name.c && ./a.out"
				echo "i	sudo apt install 'program_name'"
				echo "m	neofetch && free -m"
				echo "r	sudo apt remove 'program_name'"
				echo "s	apt search 'program_name'"
				echo "u	sudo apt update && sudo apt upgrade"
				echo "h	this help menu"
				echo ""
				break
				;;
		esac
	done

else
	echo ""
	echo "please enter a valid option, h for help"
	echo ""
fi
