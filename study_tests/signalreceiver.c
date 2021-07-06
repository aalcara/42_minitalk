
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void say_pid(void)
{
	printf("\nPID = %d\n", getpid());
}
void ft_print()
{
	write(1, "SIGUSR1 sign received!\n", 24);
}

void ft_print2()
{
	write(1, "SIGUSR2 sign received!\n", 24);
}

void receiver(void)
{
	usleep(500);
	signal(SIGUSR1, ft_print);
	signal(SIGUSR2, ft_print2);
	// receiver();
}

int main (void)
{
	say_pid();
	receiver();
	while (1);
		// pause();
}