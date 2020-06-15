/* simple Alarm for linux, after the alarm goes off, cvlc will start, to stop it run "killall vlc"
   needs vlc installed or a change of the command to open your favorit music player (one of the last lines of code)
   to run this file run "gcc -o alarm alarm.c && ./alarm" on this file directory
   to run this file as a command, run "gcc -o alarm alarm.c && sudo cp alarm /user/bin/" on this file directory, then it's just "alarm"		*/
//    ______ __  ______  ______  ______       ______  ______  __      ______  _____   ______
//   /\__  _/\ \/\  __ \/\  ___\/\  __ \     /\  ___\/\  __ \/\ \    /\  __ \/\  __-./\  __ \
//   \/_/\ \\ \ \ \  __ \ \ \__ \ \ \/\ \    \ \ \___\ \  __ \ \ \___\ \  __ \ \ \/\ \ \ \/\ \
//      \ \_\\ \_\ \_\ \_\ \_____\ \_____\    \ \_____\ \_\ \_\ \_____\ \_\ \_\ \____-\ \_____\
//       \/_/ \/_/\/_/\/_/\/_____/\/_____/     \/_____/\/_/\/_/\/_____/\/_/\/_/\/____/ \/_____/ 2020

#include <stdio.h>									// printf(), scanf()
#include <stdlib.h>									// system()
#include <string.h>

int main(int argc,char *argv[]){
	int a=0, b=0, t;								// integers inicialization
	do {
		system("clear");							// clear screen
		printf("####################	Alarm	####################\n\n");	// title
		if (a < 0 || a > 23) printf("hours must be between 00 and 23\n\n");	// warning message about hours input
		if (b < 0 || b > 59) printf("minutes must be between 00 and 59\n\n");	// warning message about minutes input
		printf("Choose the Alarm time: ");					// asking for user input
		scanf("%i %i", &a, &b);							// getting user input
	} while (a < 0 || a > 23 || b < 0 || b > 59);					// if correct time was inserted the code go on									// to get time to open cvlc before the next commands run throw
	char c[8];
	char d[8];
	sprintf(c, "%d", a);
	sprintf(d, "%d", b);
	char msg[] = "gcc -o alarm_waitting alarm_waitting.c && exec ./alarm_waitting ";
	strcat(msg, c);
	strcat(msg, " ");
	strcat(msg, d);
	system(msg);
}
