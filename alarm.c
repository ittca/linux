/* simple Alarm for linux
   needs vlc installed or a change of the command to open your favorit music player (on the music function)
   to run this file run "gcc -o alarm alarm.c && ./alarm" on this file directory
   to run this file as a command, run "gcc -o alarm alarm.c && sudo cp alarm /user/bin/" on this file directory, then it's just "alarm", if when doing "alarm" ask for administrator privileges, do a "sudo chmod +x /usr/bin/alarm" first		*/
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

int h, m, s, inp1, inp2, msc = 1;
int v = 4;
int t = 45;
int i = 15;

void timer(){
	time_t ct;
	time(&ct);
	struct tm *mt = localtime(&ct);
	h = mt->tm_hour;
	m = mt->tm_min;
	s = mt->tm_sec;
}

void music(){
	switch(msc)
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
int str_size(char *str){
  int n;
  for (n = 0; str[n] != '\0'; n++);
  return n;
}
int is_int(char *str){
  int a = str_size(str);
  for (int n = 0; str[n] < a; n++){
    if (str[n] < 48 || str[n] > 57){
      if(str[n] == 45 && n == 0){
      } else { return 0;}
    }
  }
  return 1;
}
int input_int(){
  int b = 1;
  char *msg_err = malloc(256);
  strcat(msg_err,"");
  while (b){
    char str[100];
    char str2[100];
    system("clear");							// clear screen
    printf("####################	Alarm	####################\n");	// title
    if (inp1 < 0 || inp1 > 23) printf("\t\thours must be between 00 and 23");	// warning message about hours input
    if (inp2 < 0 || inp2 > 59) printf("\t\tminutes must be between 00 and 59");	// warning message about minutes input
    if (msg_err != "")printf("%s\n", msg_err);
    inp1 = 0;
    inp2 = 0;
    printf("\nChoose the Alarm time: ");					// asking for user input
    scanf(" %s %s", str,str2);
    if (is_int(str) && is_int(str2)){
      inp1 = atoi(str);
      inp2 = atoi(str2);
      if (inp1 < 0 || inp1 > 23) inp1 = atoi(str);	// warning message about hours input
      if (inp2 < 0 || inp2 > 59) inp2 = atoi(str2);	// warning message about minutes input
      b = 0;
    } else {
      strcat(msg_err,"\t\tPlease input only numbers like  07 15");
    }
  }
  return 0;
}

int main(int argc,char *argv[]){
  int t;
	int a = 1;
	int b = 0;
	while (a != 0){
		if (argc == 1){
			system("clear");
			printf("   ############ My alarm ############\n");
			printf("\n\n\t1. Pomodoro\n");
			printf("\t2. Alarm\n");
			printf("\t3. definitions\n");
			printf("\t4. Exit\n\n\t»» ");
			scanf(" %d",&b);
		} else {
			inp1 = atoi(argv[1]);
			inp2 = atoi(argv[2]);
			b = 3;
		}
		if(b == 1){
			int vv = v;
			while (vv != 0){
				system("cvlc http://www.shinsen-radio.org:8000/shinsen-radio.64.ogg &");
				sleep(1);
				system("clear");
				printf("\n\n##################################################################################\n");
				printf("\t\t\t\t\tPomodoro");
				printf("\n##################################################################################\n");
				sleep(t*60);
				system("killall vlc");
				system("cvlc /home/tiago/Música/Metal_productivity.mp3 &");
				sleep(1);
				if (vv != 1){
					system("clear");
					printf("\n\n##################################################################################\n");
					printf("\t\t\ttime for a pause, Break!");
					printf("\n##################################################################################\n");
					sleep(22);
					system("killall vlc");
					sleep(i*60);
				} else {
					system("clear");
					printf("\n\n###########################################################################################\n");
					printf("  Pomodoro's time had finnish!, go breed fresh air, have fun, repite whenever you want!");
					printf("\n###########################################################################################\n");
					sleep(22);
					system("killall vlc");
				}
				vv--;
			}
		}
		else if (b == 2){
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\ttime for a pause, Break!");
			printf("\n##################################################################################\n");
			printf("\nChoose the number of times for the pomodoro time\n»» ");
			scanf(" %d",&v);
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\t\t\tPomodoro");
			printf("\n##################################################################################\n");
			printf("\nChoose the pomodoro's time in minutes\n»» ");
			scanf(" %d",&t);
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\t\t\tPomodoro");
			printf("\n##################################################################################\n");
			printf("\nChoose the break time in minutes\n»» ");
			scanf(" %d",&i);
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\tYour definitions had been saved with success!");
			printf("\n##################################################################################\n");
		}
		else if(b == 3){
			do {
				input_int();
			} while (inp1 < 0 || inp1 > 23 || inp2 < 0 || inp2 > 59);					// if correct time was inserted the code go on
			timer();
			while ( inp1!=h || inp2 != m){
				if (inp1 == h && inp2 > m) t = (inp2-m)*60 - s+2;
				else t = (60-m)*60 - s+2;
		    system("clear");
		    printf("####################	Alarm	set to     %d : %d   ####################\n\n",inp1,inp2);	// title
				sleep(t);
				timer();
			}
			const char *c;
			int r = 1;
			while (r){
				music();
				sleep(4);
				system("clear");
				printf("\n\n\n\n\tGood Morning!\n\n\tPress r to turn off Alarm, Any Key to more 10 minutes\n\n\t\t\t\t");
				system("killall vlc");
				sleep(5);
				r = 0;

			}
		}
		else if(b == 4){a = 0;}
	}
	printf("\n\tSee you next time!.\n");
  sleep(3);
	return 0;
}
