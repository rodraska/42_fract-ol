#include "/home/rodrigo/Documents/42/fract-ol/fract_ol.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

// float   putnbr_base(int n, char *base)
// {
//     int size;

//     size = ft_strlen(base);
//     if (n >= size)
//         putnbr_base(n / 16, base);
// }

int add_shade(int color, float ratio)
{
    int final;
    int red;
    int blue;
    int green;

    ratio = 1 / ratio;
    red = (color / (int)pow(16, 4)) / ratio;
    green = ((color % (int)pow(16 ,4)) / (int)pow(16 ,2)) / ratio;
    blue = ((color % (int)pow(16, 4)) % (int)pow(16 , 2)) / ratio;
    final = red * pow(16, 4) + green * pow(16, 2) + blue;

    return (final);
}

// int main(void)
// {
//     printf("%d\n", add_shade(0x00FF0000, 0.23));
// }