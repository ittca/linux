#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char a;
	while (a != 'r'){
		system("cvlc /home/tiago/music/Metal_productivity.mp3 &");
		sleep(1);
		system("clear");
		printf("\n\n\tPress R to turn off Alarm, Any key to more 10 minutes ");
		scanf(" %c", &a);
		if (a == 'r') {
			system("killall vlc");
			return 0;
		}
		system("killall vlc");
		sleep(5);
	}
	return 1;
}
