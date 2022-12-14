#include <stdio.h>

void remplire(int nbr, float tb[])
{

    int i;
    for (i = 0; i < nbr; i++)
    {
        if (tb[i - 1] > 20 || tb[i - 1] < 0)
        {
            printf("vous devez entrer un nembre entre 0 et 20 \n");
            break;
        }
        else
        {
            printf("entrer nombre numero %d \n", i + 1);
            scanf("%f", &tb[i]);
        }
    }
}

void affichage(int nbr, float tb[])
{

    int i;
    for (i = 0; i < nbr; i++)
    {
        printf("case numero %d :%.2f \n", i + 1, tb[i]);
    }
}

float max(int nbr, float tb[])
{

    int i;
    float max = tb[0];
    for (i = 0; i < nbr; i++)
    {
        if (tb[i] > max)
        {
            max = tb[i];
        }
    }
    return max;
}

float min(int nbr, float tb[])
{

    int i;
    float min = tb[0];
    for (i = 0; i < nbr; i++)
    {
        if (tb[i] < min)
        {
            min = tb[i];
        }
    }
    return min;
}

int superieur10(int nbr, float tb[])
{

    int i;
    float n = 0;
    for (i = 0; i < nbr; i++)
    {
        if (tb[i] >= 10)
        {
            n++;
        }
    }
    return n;
}

void tri(int nbr1, int nbr2, float tb1[], float tb2[], float tb[])
{

    int i, k = nbr1, j, nbr3 = nbr1 + nbr2;
    float tmp;
    if (nbr1 != 0)
    {
        for (i = 0; i < nbr1; i++)
        {
            tb[i] = tb1[i];
        }
    }
    if (nbr2 != 0)
    {
        for (i = 0; i < nbr2; i++)
        {
            tb[k] = tb2[i];
            k++;
        }
    }
    for (i = 0; i < nbr3 - 1; i++)
    {
        for (j = i + 1; j < nbr3; j++)
        {
            if (tb[i] > tb[j])
            {
                tmp = tb[i];
                tb[i] = tb[j];
                tb[j] = tmp;
            }
        }
    }
    for (i = 0; i < nbr3; i++)
    {
        printf("case numero %d :%.2f \n", i + 1, tb[i]);
    }
}

int empty_check(int nbr, float tb[])
{
    int i, n = 0;
    for (i = 0; i < nbr; i++)
    {
        if (i > 0)
        {
            n = nbr;
            break;
        };
    }
    if (n == 0)
    {
        return 0;
    }
    else if (n == nbr)
    {
        return 1;
    }
}

int main()
{
    int a, nbr1, nbr2, nbr3 = nbr1 + nbr2;
    float tb1[nbr1], tb2[nbr2], tb[nbr3];

    printf("entrer le numero de l'operation \n ");
    scanf("%d", &nbr1);
    printf("entrer le numero de l'operation \n ");
    scanf("%d", &nbr2);
    do
    {

        printf("***********************\n");
        printf("pour remplire les moyennes des eleves de classe 1 clique sur 1 \n");
        printf("pour remplire les moyennes des eleves de classe 2 clique sur 2 \n ");
        printf("pour avoir le max des moyennes des eleves de classe 1 clique sur 3 \n ");
        printf("pour avoir le min des moyennes des eleves de classe 2 clique sur 4 \n ");
        printf("pour avoir le nombre des eleves de classe 1 ayons une moyenne superieur de 10 clique sur 5 \n ");
        printf("pour avoir le max des moyennes des eleves de classe 1 clique sur 6 \n ");
        printf("pour avoir le min des moyennes des eleves de classe 2 clique sur 7 \n ");
        printf("pour avoir le nombre des eleves de classe 1 ayons une moyenne superieur de 10 clique sur 8 \n ");
        printf("pour avoir tout les moyennes des eleves de classe 1 et 2 en ordre croissant clique sur 9 \n ");
        printf("pour afficher les moyennes des eleves de classe 1 clique sur 10 \n");
        printf("pour afficher les moyennes des eleves de classe 2 clique sur 11 \n ");
        printf("pour terminer le programme entrer 0 \n ");
        printf("entrer le numero de l'operation \n ");
        scanf("%d", &a);
        printf("***********************\n");

        switch (a)
        {
        case 1:
            remplire(nbr1, tb1);
            break;
        case 2:
            remplire(nbr2, tb2);
            break;
        case 3:
            printf("%.2f \n", max(nbr1, tb1));
            break;
        case 4:
            printf("%.2f \n", min(nbr1, tb1));
            break;
        case 5:
            printf("%d\n", superieur10(nbr1, tb1));
            break;
        case 6:
            printf("%.2f \n", max(nbr2, tb2));
            break;
        case 7:
            printf("%.2f \n", min(nbr2, tb2));
            break;
        case 8:
            printf("%d\n", superieur10(nbr2, tb2));
            break;
        case 9:
            if (empty_check(nbr1, tb1) == 1)
            {
                tri(0, nbr2, tb1, tb2, tb);
            }
            else if (empty_check(nbr2, tb2) == 1)
            {
                tri(nbr1, 0, tb1, tb2, tb);
            }
            else if (empty_check(nbr2, tb2) == 1 && empty_check(nbr1, tb1) == 1)
            {
                printf("vous devez remplire un des deux tableaux de classe 1 ou 2 \n");
            }
            break;
        case 10:
            affichage(nbr1, tb1);
            break;
        case 11:
            affichage(nbr2, tb2);
            break;
        case 12:
            if (empty_check(nbr3, tb) == 0)
            {
                printf("%.2f \n", max(nbr3, tb));
            }
            break;
        case 13:
            if (empty_check(nbr3, tb) == 0)
            {
                printf("%.2f \n", min(nbr3, tb));
            }
            break;
        case 14:
            if (empty_check(nbr3, tb) == 0)
            {
                printf("%.2f \n", superieur10(nbr3, tb));
            }
            break;
        default:
            printf("enter un de les numeros suivants");
            break;
        }
    } while (a != 0);

    return 0;
}