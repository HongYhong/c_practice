#include <ctype.h>
#include <math.h>

double atof2(char s[])
{
    int i = 0, sign, j;
    double val, power;
    /* skip white spaces */
    while (isspace(s[i]))
    {
        i++;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = val * 10.0 + (s[i] - '0');
    }
    power = 1.0;
    if (s[i] == '.')
    {
        i++;
        for (power = 1.0; isdigit(s[i]); i++)
        {
            val = val * 10.0 + (s[i] - '0');
            power *= 10.0;
        }
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        if (s[++i] == '-')
        {
            i++;
            for (j = 0; isdigit(s[i]); i++)
            {
                j = j * 10 + s[i] - '0';
            }
            power *= pow(10, j);
        }
        else
        {
            if (s[i] == '+')
                i++;
            for (j = 0; isdigit(s[i]); i++)
            {
                j = j * 10 + s[i] - '0';
            }
            power /= pow(10,j);
        }
    }

    return sign * val / power;
}