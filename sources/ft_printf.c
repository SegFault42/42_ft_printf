#include "./includes/ft_printf.h"
#include <stdio.h>

void afficher (const char *format, const char *espace, ...)
{
    /* Liste des arguments */
    va_list args;
    /* Initialisation, à partir du dernier paramètre connu */
    va_start (args,espace);

    /* Parcours de la chaîne de format et affichage des données */
    int i;
    for (i=0; format[i]; i++)
        switch (format[i])
        {
            /* Note au niveau des conversions :
             * – les arguments de type char ou short sont automatiquement convertis en int ;
             * – les arguments de type float sont automatiquement convertis en double.
             */
            case 'C' : case 'c' :
                printf ("%c%s",va_arg(args,int),espace);
                break;
            case 'D' : case 'd' :
                printf ("%d%s",va_arg(args,int),espace);
                break;
            case 'E' :
                printf ("%E%s",va_arg(args,double),espace);
                break;
            case 'e' :
                printf ("%e%s",va_arg(args,double),espace);
                break;
            case 'F' : case 'f' :
                printf ("%f%s",va_arg(args,double),espace);
                break;
            case 'G' :
                printf ("%G%s",va_arg(args,double),espace);
                break;
            case 'g' :
                printf ("%g%s",va_arg(args,double),espace);
                break;
            case 'H' :
                printf ("%X%s",va_arg(args,int),espace);
                break;
            case 'h' :
                printf ("%x%s",va_arg(args,int),espace);
                break;
            case 'O' : case 'o' :
                printf ("%o%s",va_arg(args,int),espace);
                break;
            case 'P' : case 'p' :
                printf ("%p%s",va_arg(args,void*),espace);
                break;
            case 'S' : case 's' :
                printf ("%s%s",va_arg(args,char*),espace);
                break;
            default : ;
        }
    /* Fermeture */
    va_end (args);
}

