#include<stdio.h>
#include<signal.h>
  
void handle()
{
    printf("^    ryi7\n");
}
int main()
{
    signal(SIGINT, handle);
    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }
    return 0;
}