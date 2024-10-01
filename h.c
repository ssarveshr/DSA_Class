#include<stdio.h>
#include<string.h>
struct p_details
{
    int age;
    char name[10];
    float s_rate;
} player={31,"VIRAT",116.9},player1,player2;
int main()
{
    printf("%d %s %.2f\n",player.age,player.name,player.s_rate);
    player1.age=34;
    strcpy(player1.name,"rohit");
    player1.s_rate=147.11;
    printf("%d %s %.2f\n",player1.age,player1.name,player1.s_rate);
    player2=player1;
    printf("%d %s %.2f",player2.age,player2.name,player2.s_rate);
    return 0;
}