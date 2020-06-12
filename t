#!/bin/bash
# this bash file if with executable permissions is placed on /usr/bin/ will creat a new terminal command "t"
# t has some options that run my personal most executed commands with just a 2 or 3 caracters
# this file can be modified, for example to remove, add or edit commands
# to check options just enter on the terminal "t h"

#   ______ __  ______  ______  ______       ______  ______  __      ______  _____   ______
#  /\__  _/\ \/\  __ \/\  ___\/\  __ \     /\  ___\/\  __ \/\ \    /\  __ \/\  __-./\  __ \
#  \/_/\ \\ \ \ \  __ \ \ \__ \ \ \/\ \    \ \ \___\ \  __ \ \ \___\ \  __ \ \ \/\ \ \ \/\ \
#     \ \_\\ \_\ \_\ \_\ \_____\ \_____\    \ \_____\ \_\ \_\ \_____\ \_\ \_\ \____-\ \_____\
#      \/_/ \/_/\/_/\/_/\/_____/\/_____/     \/_____/\/_/\/_/\/_____/\/_/\/_/\/____/ \/_____/


if [ -n "$1" ]; then
	for arg
	do
		case "$arg" in
			a)
				clear
				sudo apt autoremove
				break
				;;
			c)
				if [ -n "$2" ]; then
					clear
					gcc -o $2 $2.c
					./$2
					rm $2
					break
				else
					echo "please enter the file name"
				fi
				;;
			cp)
				if [ -n "$2" ]; then
					clear
					g++ -o $2 $2.cpp
					./$2
					rm $2
					break
				else
					echo "please enter the file name"
				fi
				;;
			e)
				if [ -n "$2" ]; then
					for arg2
					do
						case "$arg2" in
							*.zip)
								unzip $2
								break
								;;
							*.rar)
								unrar $2
								break
								;;
							*.tar.xz)
								tar -xvf $2
								break
								;;
						esac
					done
					break
				else
					echo "please enter a file to extract"
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
			g)
				if [ -n "$2" ]; then
					git add *
					git status
					git commit -m "$2" *
					git push -u origin master
					break
				else
					echo "Please enter a comment"
				fi
				;;
			gr)
				if [ -n "$2" ]; then
					git rm $2
					git status
					git commit -m "$2 deleted"
					git push -u origin master
					break
				else
					echo "Please enter a filename to remove"
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
			t)
				## ascii art  , available for example in http://patorjk.com/software/taag/#p=display&f=Chiseled&t=Type%20Something%20
				clear
				echo ""
				echo ""
				echo "    ███      ▄█     ▄████████    ▄██████▄   ▄██████▄  ";
				echo "▀█████████▄ ███    ███    ███   ███    ███ ███    ███ ";
				echo "   ▀███▀▀██ ███▌   ███    ███   ███    █▀  ███    ███ ";
				echo "    ███   ▀ ███▌   ███    ███  ▄███        ███    ███ ";
				echo "    ███     ███▌ ▀███████████ ▀▀███ ████▄  ███    ███ ";
				echo "    ███     ███    ███    ███   ███    ███ ███    ███ ";
				echo "    ███     ███    ███    ███   ███    ███ ███    ███ ";
				echo "   ▄████▀   █▀     ███    █▀    ████████▀   ▀██████▀  ";
				echo "                                                      ";
				echo ""
				;;
			u)
				clear
				sudo apt update
				sudo apt upgrade
				break
				;;
			*)
				echo ""
				echo "                  ___"
				echo "                ,--.'|"
				echo "                |  | :,'"
				echo "                :  : ' |"
				echo "              .;__,'  /"
				echo "              |  |   |"
				echo "              :__,'| :"
				echo "                '  : |__"
				echo "                |  | '.'|"
				echo "                ;  :    ;"
				echo "                |  '   /"
				echo "                 ---'-'"
				echo "options:"
				echo ""
				echo "	a   sudo apt autoremove -y"
				echo "	c   gcc program_name.c && ./program_name && rm program_name"
				echo "	cp  g++ program_name.cpp && ./program_name && rm program_name"
				echo "	e   unrar 'file_name' , this can extract .zip .rar .tar.xz"
				echo "	g   git add * && git status && git commit -m 'comment' * && git push -u origin master"
				echo "	gr  git rm 'file_name' && git status && git commit -m 'file_name deleted' * && git push -u origin master"
				echo "	i   sudo apt install 'program_name'"
				echo "	m   neofetch && free -m"
				echo "	r   sudo apt remove 'program_name'"
				echo "	s   apt search 'program_name'"
				echo "	u   sudo apt update && sudo apt upgrade"
				echo "	h   this help menu"
				echo ""
				echo "example:"
				echo "	t i vlc"
				echo ""
				break
				;;
		esac
	done

else
	echo ""
	echo "please enter valid option, h for help"
	echo ""
fi
