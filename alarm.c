
/* simple Alarm for linux
   needs vlc installed or a change of the command to open your favorit music player (on the music function)
   to run this file run "gcc -o alarm alarm.c && ./alarm" on this file directory
   to run this file as a command, run "gcc -o alarm alarm.c && sudo cp alarm /user/bin/" on this file directory, then it's just "alarm"		*/
//    ______ __  ______  ______  ______       ______  ______  __      ______  _____   ______
//   /\__  _/\ \/\  __ \/\  ___\/\  __ \     /\  ___\/\  __ \/\ \    /\  __ \/\  __-./\  __ \
//   \/_/\ \\ \ \ \  __ \ \ \__ \ \ \/\ \    \ \ \___\ \  __ \ \ \___\ \  __ \ \ \/\ \ \ \/\ \
//      \ \_\\ \_\ \_\ \_\ \_____\ \_____\    \ \_____\ \_\ \_\ \_____\ \_\ \_\ \____-\ \_____\
//       \/_/ \/_/\/_/\/_/\/_____/\/_____/     \/_____/\/_/\/_/\/_____/\/_/\/_/\/____/ \/_____/ 2020

#include <stdio.h>									// printf(), scanf()
#include <stdlib.h>									// system()
#include <time.h>									// time_t, time(), localtime()
#include <unistd.h>
#include <string.h>

int h, m, s, d=3;

void timer(){
	time_t ct;
	time(&ct);
	struct tm *mt = localtime(&ct);
	h = mt->tm_hour;
	m = mt->tm_min;
	s = mt->tm_sec;
}

void music(){
	switch(d)
	{
	case 1:
		system("cvlc https://soundcloud.com/nocopyrightsounds/unknown-brain-matafaka-feat-marvin-divine &");
		break;
	case 2:
		system("cvlc https://soundcloud.com/nathan-due/nightcore-alone-tonight-digital-daggers &");
		break;
	case 3:
		system("cvlc https://soundcloud.com/nightcorenocopyright-434283379/nightcore-wrecking-ball-metal &");
		break;
	case 4:
		system("cvlc https://soundcloud.com/sarahjcmusic/i-dont-know-demo &");
		break;
	}
}

int main(int argc,char *argv[]){
	int a, b, t;
	if (argc == 1){
		a=0;
		b=0;										// integers inicialization
		do {
			system("clear");							// clear screen
			printf("####################	Alarm	####################\n\n");	// title
			if (a < 0 || a > 23) printf("hours must be between 00 and 23\n\n");	// warning message about hours input
			if (b < 0 || b > 59) printf("minutes must be between 00 and 59\n\n");	// warning message about minutes input
			printf("Choose the Alarm time: ");					// asking for user input
			scanf("%i %i", &a, &b);							// getting user input
		} while (a < 0 || a > 23 || b < 0 || b > 59);					// if correct time was inserted the code go on									// to get time to open cvlc before the next commands run throw
	} else {
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	}
	timer();
	while ( a!=h || b != m){
		if (a == h && b > m) t = (b-m)*60 - s+2;
		else t = (60-m)*60 - s+2;
		sleep(t);
		timer();
	}
	const char *c;
	while (1 == 1){
		music();
		sleep(4);
		system("clear");
		printf("\n\n\n\n\tGood Morning!\n\n\tPress r to turn off Alarm, Any Key to more 10 minutes\n\n\t\t\t\t");
		scanf("%s", c);
		if (strcmp(c, "r")== 0){
			system("killall vlc");
			int z = 5;
			while (z > 0){
				system("clear");
				printf("\n\n\n\n\t Have a great day!\n");
				sleep(1);
				z--;
			}
			return 0;
		}
		system("clear");
		printf("\n\n\n\n\tMake your own time, your own life, your own staff,\n\t\t be glad and sad, poor and rich, have a great day love!\n");
		system("killall vlc");
		sleep(10);
	}
	return 1;
}
