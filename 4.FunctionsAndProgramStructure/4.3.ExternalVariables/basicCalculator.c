#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found
#define MAXVAL 100 // max depth of val stack
#define BUFSIZE 100

int sp = 0;         //next free stack position
double val[MAXVAL]; // value stack

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;      //next free position in buf

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);

// Reverse Polish calculator
int main(int argc, char const *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("ERROR: Zero divisor\n");
            }
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("ERROR: Unkown command %s\n", s);
            break;
        }
    }

    return 0;
}

// push: push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("ERROR: Stack full, can't push %g\n", f);
    }
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("ERROR: Stack empty\n");
        return 0.0;
    }
}

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i, c;

    //Skip blank spaces at the beginning
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }

    s[1] == '\0';

    if (!isdigit(c) && c != '.')
    {
        // Not a number
        return c;
    }

    i = 0;
    if (isdigit(c))
    {
        // Collect integer part
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }

    if (c == '.')
    {
        // Collect fraction part
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }

    s[i] = '\0';

    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

int getch(void) // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push char back on input
{
    if (bufp >= BUFSIZE)
    {
        printf("UNGETCH: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}