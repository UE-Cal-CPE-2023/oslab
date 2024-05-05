#include<stdio.h>

int fr[3];

void display()
{
    for (int i = 0; i < 3; i++)
    {
        if (fr[i] != -1)
        {
            printf("%d ", fr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int p[12] = {2,3,2,1,5,2,4,5,3,2,5,2}, i, j, fs[3];
    int index = 0, flag1 = 0, flag2 = 0, pf = 0, frsize = 3;

    for (i = 0; i < frsize; i++)
    {
        fr[i] = -1;
    }

    for (j = 0; j < 12; j++)
    {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < frsize; i++)
        {
            if (fr[i] == p[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (i = 0; i < frsize; i++)
            {
                if (fr[i] == -1)
                {
                    fr[i] = p[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }    
        }

        if (flag2 == 0)
        {
            fr[index] = p[j];
            index = (index + 1) % frsize;
            pf++;
        }

        display();
    }

    printf("No of page faults: %d\n", pf);

    return 0;
}