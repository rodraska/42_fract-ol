#include "../fract_ol.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int get_opposite(int color)
{
    int final;
    int red;
    int blue;
    int green;

    red = abs((color / (int)pow(16, 4)) - 255);
    green = abs(((color % (int)pow(16 ,4)) / (int)pow(16 ,2)) - 255);
    blue = abs(((color % (int)pow(16, 4)) % (int)pow(16 , 2)) - 255);
    final = red * pow(16, 4) + green * pow(16, 2) + blue;

    return (final);
}

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