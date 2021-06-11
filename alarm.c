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
#include <unistd.h>               // sleep()

int h, m, s, inp1, inp2, msc = 1;
int v = 4;
int t = 45;
int i = 15;
char os_return[100];

void system_hour();
void system_return(char *a);
void music();
int str_size(char *str);
int is_int(char *str);
int sti(char *str);
void str_replace(char *str, char *str2);
void input_int();


int main(int argc,char *argv[]){
  int t;
	int a = 1;
	int b = 0;
	while (a != 0){
		if (argc == 1){
			system("clear");
			printf("   ############ My timer ############\n");
			printf("\n\n\t1. Pomodoro\n");
			printf("\t2. Alarm\n");
			printf("\t3. Settings\n");
			printf("\t4. Exit\n\n\t»» ");
			scanf(" %d",&b);
		} else {
			inp1 = sti(argv[1]);
			inp2 = sti(argv[2]);
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
			do {
				input_int();
			} while (inp1 < 0 || inp1 > 23 || inp2 < 0 || inp2 > 59);					// if correct time was inserted the code go on
			system_hour();
			int t = 1;
			while(t){
				while ( inp1!=h || inp2 != m){
					if (inp1 == h && inp2 > m) t = (inp2-m)*60 - s+2;
					else t = (60-m)*60 - s+2;
			    system("clear");
			    printf("####################	Alarm	set to     %d : %d   ####################\n\n",inp1,inp2);	// title
					sleep(t);
					system_hour();
				}
				const char *c;
				int r = 1;
				while (r){
					music();
					sleep(4);
					char str3[100];
					system("clear");
					printf("\n\n\n\n\tGood Morning!\n\n\tPress r to turn off the Alarm, Any Key to more 10 minutes\n\n\t\t\t\t");
					scanf(" %s", str3);
					system("killall vlc");
					if (str3[0] == 'r'){r = 0; t = 0;}
					else{
						inp2 = inp2 + 10;
						if(inp2 > 59){
							inp2 = inp2 - 60;
							inp1++;
							if (inp1 > 23)inp1 = 0;
						}
						r = 0;}
				}
			}
		}
		else if(b == 3){
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\t\t\tPomodoro settings");
			printf("\n##################################################################################\n");
			printf("\nChoose the number of times for the pomodoro time\n»» ");
			scanf(" %d",&v);
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\t\t\tPomodoro settings");
			printf("\n##################################################################################\n");
			printf("\nChoose the pomodoro's time in minutes\n»» ");
			scanf(" %d",&t);
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\t\t\tPomodoro settings");
			printf("\n##################################################################################\n");
			printf("\nChoose the break time in minutes\n»» ");
			scanf(" %d",&i);
			system("clear");
			printf("\n\n##################################################################################\n");
			printf("\t\t\tYour definitions had been saved with success!");
			printf("\n##################################################################################\n");
			sleep(3);
		}
		else if(b == 4){a = 0;}
	}
	printf("\n\tSee you next time!.\n");
  sleep(3);
	return 0;
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
int sti(char *str){
  int a = 0, b = 1, i = 0;
  if(str[0] == '-'){
    b = -1;
    i++;
  }
  for(;str[i];++i) a = a*10 + str[i] - '0';
  return b*a;
}
void str_replace(char *str, char *str2){
  int b = str_size(str);
  int c = str_size(str2);
  int n;
  for(n = 0; n < b; n++)str[n]='\0';
  for(n = 0; n < c; n++)str[n]=str2[n];
  str[n]='\0';
}

void input_int(){
  int b = 1;
  char *msg_err = malloc(256);
  str_replace(msg_err,"");
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
      inp1 = sti(str);
      inp2 = atoi(str2);
      if (inp1 < 0 || inp1 > 23) inp1 = atoi(str);	// warning message about hours input
      if (inp2 < 0 || inp2 > 59) inp2 = atoi(str2);	// warning message about minutes input
      b = 0;
    } else {
      str_replace(msg_err,"\t\tPlease input only numbers like  07 15");
    }
  }
}

void system_return(char *a){ // needs 1 global variable char os_return[100];
  int b = str_size(a);
  char c[b];
  mkstemp("tmp543765");
  sprintf(c, "%s > tmp543765", a);
  system(c);
  FILE *d = fopen("tmp543765", "r");
  while (fgets(os_return, 1000, d) != NULL);
  fclose(d);
  system("rm tmp543765");
}
void system_hour(){  // needs 4 global variables char os_return[100];
  system_return("date");
  int n = 0;
  int nn = 0;
  int nnn = 0;
  char hh[3] = "  ";
  char mm[3] = "  ";
  char ss[3] = "  ";
  for(int i = 0; i < str_size(os_return);i++){
    if (n == 4 && os_return[i] != ' '){
      if(os_return[i]==':'){nn++;nnn = 0;}
      else{
        if(nn==0){ hh[nnn] = os_return[i];nnn++;}
        else if(nn==1){mm[nnn] = os_return[i];nnn++;}
        if(nn==2){ss[nnn] = os_return[i];nnn++;}
      }
    }
    if (os_return[i] == ' ')n++;
  }
  h = sti(hh);
  m = sti(mm);
  s = sti(ss);
}
