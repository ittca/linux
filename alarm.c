/* simple Alarm for linux
   needs vlc installed or a change of the command to open your favorit music player (one of the last lines of code)
   to run this file run "gcc -o alarm alarm.c && ./alarm" on this file directory
   to run this file as a command, run "gcc -o alarm alarm.c && sudo cp alarm /user/bin/" on this file directory, then it's just "alarm"		*/
//    ______ __  ______  ______  ______       ______  ______  __      ______  _____   ______
//   /\__  _/\ \/\  __ \/\  ___\/\  __ \     /\  ___\/\  __ \/\ \    /\  __ \/\  __-./\  __ \
//   \/_/\ \\ \ \ \  __ \ \ \__ \ \ \/\ \    \ \ \___\ \  __ \ \ \___\ \  __ \ \ \/\ \ \ \/\ \
//      \ \_\\ \_\ \_\ \_\ \_____\ \_____\    \ \_____\ \_\ \_\ \_____\ \_\ \_\ \____-\ \_____\
//       \/_/ \/_/\/_/\/_/\/_____/\/_____/     \/_____/\/_/\/_/\/_____/\/_/\/_/\/____/ \/_____/

#include <stdio.h>									// printf()
#include <time.h>									// time_t, time(), localtime()
#include <stdlib.h>									// system()
#include <unistd.h>									// sleep()

int main(){
	int a=0, b=0, h, m, s, t;							// integers inicialization
	int tm, ts;		// debug code
	do {
		system("clear");							// clear screen
		printf("####################	Alarm	####################\n\n");	// title
		if (a < 0 || a > 23) printf("hours must be between 00 and 23\n\n");	// warning message about hours input
		if (b < 0 || b > 59) printf("minutes must be between 00 and 59\n\n");	// warning message about minutes input
		printf("Choose the Alarm time: ");					// asking for user input
		scanf("%i %i", &a, &b);							// getting user input
	} while (a < 0 || a > 23 || b < 0 || b > 59);					// if correct time was inserted the code go on

	time_t ct;
	time(&ct);
	struct tm *mt = localtime(&ct);
	h = mt->tm_hour;								// getting the hour in this moment
	m = mt->tm_min;									// getting the minutes in this moment
	s = mt->tm_sec;									// getting the seconds in this moment

	while (a != h || b != m){							// checking if it's time to set the alarm, while loop for each exact hours
		system("clear");							// clear screen
		printf("####################	Alarm	####################\n\nThe alarm is set to %i %i\n\n", a, b);	// Alarm user confirmation
		if (a == h && b > m) t = (b-m)*60 - s+2;				// calculation of the remain seconds
		else if ( a > h && b <= m) t = (60-m)*60 - s+2;				// calculation of the remain seconds until the next exact hour
		tm = t / 60;				// debug code
		ts = t - (60 * tm);			// debug code
		printf("O seu alarme vai soar dentro de %im %is num total de % is\n", tm, ts, t);	// debug code
		sleep(t);								// sleep in seconds until Alarm time or next exact hour
		time_t ct;
		time(&ct);
		struct tm *mt = localtime(&ct);
		h = mt->tm_hour;							// getting the hour in this moment
		m = mt->tm_min;								// getting the minutes in this moment
		s = mt->tm_sec;								// getting the seconds in this moment
	}

	system("cvlc /home/tiago/music/Metal_productivity.mp3 &");			// start vlc without gui with the desire sound choosen
	sleep(1);									// to get time to open cvlc before the next commands run throw
	system("clear");								// clear screen
	printf("\n\n\nHELLLLLOOOOOOOOOOOO, have a great day\n\n\n\n");			// user Alarm message on the screen
}
