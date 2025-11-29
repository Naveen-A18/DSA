#include <stdio.h>
#define SIZE 20
char s[SIZE];
int top = -1;
void push(char elem)
{
s[++top] = elem;
}
char pop()
{
return (s[top--]);
}
int precedence(char elem) /* Function for precedence */
{
switch (elem)
{
case '#': return 0; case '(': return 1; case '+':
case '-': return 2; case '*':
case '/':
case '%': return 3; case '$':
case '^': return 4;
}
return elem;
}
void main()
{
char infix[50], postfix[50], ch, elem; int i = 0, k = 0;
printf("\n\nEnter the Infix Expression: "); scanf("%s", infix);
push('#');
while ((ch = infix[i++]) != '\0')
{
if (ch == '(') push(ch);
else if (isalnum(ch)) postfix[k++] = ch;
else if (ch == ')')
{
while (s[top] != '(') postfix[k++] = pop();
elem = pop(); /* Remove ( */
}
else /* Operator */
{
while (precedence(s[top]) >= precedence(ch)) postfix[k++] = pop();
push(ch);
}
}
while (s[top] != '#'){ /* Pop from stack till empty */ postfix[k++] = pop();
}
postfix[k] = '\0'; /* Make pofx as valid string */ printf("\nGiven Infix Expression is: %s\n",infix); printf("\nPostfix Expression is: %s\n", postfix);
}
