#include <unistd.h>	// sleep()
#include <stdlib.h>	// atoi(), system()
#include <time.h>	// time_t, time(), localtime()


int h, m, s;

void timer(){
	time_t ct;
	time(&ct);
	struct tm *mt = localtime(&ct);
	h = mt->tm_hour;
	m = mt->tm_min;
	s = mt->tm_sec;
}


int main(int argc, char *argv[]){
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int t;
	timer();
	while (a != h || b != m){
		if (a == h && b > m) t = (b-m)*60 - s+2;
		else t = (60-m)*60 - s+2;
		sleep(t);
		timer();
	}
	system("gcc -o alarm_goes_off alarm_goes_off.c && exec ./alarm_goes_off");
	return 0;
}
