#include<stdio.h> /* standard input output library, provides printf, scanf etc */
#include<stdlib.h>
#include<SDL3/SDL.h> /* graphical interface */

int main(void) { /* excplicitely shows no given args */

    /* window variables */
    const int width = 900;
    const int height = 600;
    const char *title = "Image Viewer";
    int flags = 0;

    /* this initialises SDL */
    SDL_Init(SDL_INIT_VIDEO);

    /* this creates a canvas */
    SDL_Window *pwindow =  SDL_CreateWindow(title, width, height, flags);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    /* this clears the background (makes it black) */
    SDL_FillSurfaceRect(psurface, NULL, SDL_MapRGB(SDL_GetPixelFormatDetails(psurface->format), NULL, 0, 0, 0));

    /* this sets the rgb values to be used in the pixel format */
    Uint8 r,g,b;
    r = 0xFF;
    b = g = 0x00;

    int x = 50;
    int y = 50;


    /* this sets the colour / pixel format to be used in the rect */
    Uint32 colour = SDL_MapRGB(SDL_GetPixelFormatDetails(psurface->format), NULL, r, g, b);

    /* creates a rect structure */
    SDL_Rect pixel = { .x=0, .y=0, .w=1, .h=1 };

    for (int x=0; x<width; x++) {
        for (int y=0; y<height; y++) {

            /* this updates the x and y values of the pixel rect */
            pixel.x = x;
            pixel.y = y;
            
            /* paints the rectangle onto the surface of the canvas*/
            SDL_FillSurfaceRect(psurface, &pixel, colour);
        }
    }

    SDL_UpdateWindowSurface(pwindow);

    /* this allows macOS to process the window state immediately */
    SDL_PumpEvents();

    /* keeps the window open for 3 seconds (3000ms)*/
    SDL_Delay(5000);

    /* cleans memory before exiting */
    SDL_DestroyWindow(pwindow);
    SDL_Quit();

    return 0;

}
