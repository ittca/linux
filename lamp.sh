#!bash
sudo apt update -y
sudo apt upgrade -y
sudo apt autoremove -y
echo ''
echo sistema atualizado
echo Este script vai instalar LAMP em sistemas Debian
echo -n "deseja continuar (s/n)? "
read resp
if [ "$resp" != "${resp#[Ss]}" ] ;then
 sudo apt install apache2 -y
 sudo apt install mariadb-server -y
 echo ''
 echo Apache2 e mariadb-server foram instalados corretamente?
 echo -n "deseja continuar (s/n)? "
 read resp
 echo ''
 echo Ao entrar na base de dados use estes comandos:
 echo ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'nova-password';
 echo exit;
 echo ''
 if [ "$resp" != "${resp#[Ss]}" ] ;then
    sudo mariadb -u root
    echo ''
    echo A criação de password root para a base de dados foi bem sucedida?
    echo -n "deseja continuar (s/n)? "
    read resp
    if [ "$resp" != "${resp#[Ss]}" ] ;then
      mysql_secure_installation
      sudo apt install php libapache2-mod-php php-mysql -y
      sudo systemctl disable apache2
      sudo systemctl disable mariadb
      php -v
      mariadb --version
      echo ''
      echo Parabéns!, o servidor LAMP foi instalado corretamente.
      echo ''
    else
      echo ''
      echo Apache2 e mariadb possivelmente já estão instalados.
      echo Verifique a password root da base de dados e volte a correr o script
    fi
 else
    echo ''
    echo Houve uma tentativa de instalação do apache2 e mariadb-server
    echo Por favor verifique o seu sistema.
 fi
else 
 echo O sistema foi atualizado, LAMP não foi instalado
fi

