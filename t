#!/bin/bash
# Estes são os meus comandos mais usados para que possa facilitar o meu uso do dia a dia

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
					echo "insira o programa C para compilar"
				fi
				;;
			i)
				if [ -n "$2" ]; then
					sudo apt install $2
					break
				else
					echo "insira o programa a instalar"
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
					echo "insira o programa a remover"
				fi
				;;
			s)
				if [ -n "$2" ]; then
					apt search $2
					break
				else
					echo "insira o programa a procurar"
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
				echo "opções:"
				echo "a sudo apt autoremove -y"
				echo "c	compila os programas .c, é necessário indicar o nome do ficheiro a seguir"
				echo "i sudo apt install 'nome do programa'"
				echo "m	neofetch && free -m"
				echo "r	sudo apt remove 'nome do programa'"
				echo "s	apt search 'nome do programa'"
				echo "u	sudo apt update && sudo apt upgrade"
				echo "h	menu ajuda"
				echo ""
				break
				;;
		esac
	done

else
	echo "introduza uma opção, ou h para ajuda"
fi
