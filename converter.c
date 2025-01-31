#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t main(int32_t argc, char *argv[])
{
    if (argc < 4 || argc > 5)
    {
        return EXIT_FAILURE;
    }

    int32_t color_hue = strtol(argv[1], NULL, 10);

    if (color_hue < 0 || color_hue > 360)
    {
        return EXIT_FAILURE;
    }

    float color_saturation = strtof(argv[2], NULL);

    if (color_saturation < 0 || color_saturation > 100)
    {
        return EXIT_FAILURE;
    }

    float color_value = strtof(argv[3], NULL);

    if (color_value < 0 || color_value > 100)
    {
        return EXIT_FAILURE;
    }

    int32_t color_opacity = 255;

    if (argc == 5)
    {
        color_opacity = strtol(argv[4], NULL, 10);
    }

    if (color_opacity < 0 || color_opacity > 255)
    {
        return EXIT_FAILURE;
    }

    color_saturation /= 100.0;
    color_value /= 100.0;

    float color_c = color_value * color_saturation;
    float color_m = color_value - color_c;

    float color_mod = fmod(color_hue / 60.0, 2.0);
    float color_abs = fabs(color_mod - 1);

    float color_x = color_c * (1 - color_abs);
    float rgb[3];

    if (color_hue < 60)
    {
        rgb[0] = color_c;
        rgb[1] = color_x;
        rgb[2] = 0;
    }
    else if (color_hue < 120)
    {
        rgb[0] = color_x;
        rgb[1] = color_c;
        rgb[2] = 0;
    }
    else if (color_hue < 180)
    {
        rgb[0] = 0;
        rgb[1] = color_c;
        rgb[2] = color_x;
    }
    else if (color_hue < 240)
    {
        rgb[0] = 0;
        rgb[1] = color_x;
        rgb[2] = color_c;
    }
    else if (color_hue < 300)
    {
        rgb[0] = color_x;
        rgb[1] = 0;
        rgb[2] = color_c;
    }
    else if (color_hue < 360)
    {
        rgb[0] = color_c;
        rgb[1] = 0;
        rgb[2] = color_x;
    }

    rgb[0] = (rgb[0] + color_m) * 255;
    rgb[1] = (rgb[1] + color_m) * 255;
    rgb[2] = (rgb[2] + color_m) * 255;

    if (argc == 5)
    {
        printf("%02x%02x%02x%02x\n",
                (int32_t) rgb[0],
                (int32_t) rgb[1],
                (int32_t) rgb[2],
                color_opacity);
    }
    else
    {
        printf("%02x%02x%02x\n",
                (int32_t) rgb[0],
                (int32_t) rgb[1],
                (int32_t) rgb[2]);
    }
}
