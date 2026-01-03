#include<stdio.h>
char STR[100],PAT[100],REP[100],ANS[100];
int s, p, r, a, flag = 0;

void read()
{
printf("Enter the MAIN string: \n");
scanf("%[^\n]s",STR);
printf("Enter a PATTERN string: \n");
scanf("%s",PAT);
printf("Enter a REPLACE string: \n");
scanf("%s",REP);
}
void replace ()
{
s = p = a = 0;
while ( STR[s] != '\0')
{
// Checking for Match
if ( STR[s] == PAT[p] )
{
p++;
s++;
//if the first character is matched check for entire PAT string
if ( PAT[p] == '\0')
{
flag=1;
for(r = 0; REP[r] != '\0';r++, a++)
ANS[a] = REP[r];
p = 0;
}
}
else //Mismatch
{
ANS[a] = STR[s];
s++;
a++;
p = 0;
}
}
}
void print()
{
if(flag==0)
printf("Pattern doesn't found!!!");

else
{
    ANS[a] = '\0';
    printf("\nThe RESULTANT string is:\n%s\n" ,ANS);
}
}

