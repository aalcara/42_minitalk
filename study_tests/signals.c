
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


int	main(void)
{
	int num = 100;
	int pid = 32555;


	printf("PID = %d\n", pid);
	while (num >= 0)
	{
		printf("\nnum = %d", num);
		if (num%10 == 0)
		{
			printf("????");
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		num = num - 5;
		usleep(10000);
	}
}