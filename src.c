#include<stdio.h> /* standard input output library, provides printf, scanf etc */
#include<stdlib.h>
#include<SDL3/SDL.h> /* graphical interface */

int main(void) { /* excplicitely shows no given args */

    /* window variables */
    int width = 600;
    int height = 800;
    const char *title = "Image Viewer";
    int flags = 0;

    /* this initialises SDL */
    SDL_Init(SDL_INIT_VIDEO);

    /* creating widnow and renderer */
    SDL_Window *pwindow = NULL;
    SDL_Renderer *prenderer = NULL;

    SDL_CreateWindowAndRenderer(title, width, height, flags, &pwindow, &prenderer);

    /* sets the render colour (next drawing operations use this colour)  */
    /* renderer, then colour in RGB format, and then opacity (255)*/
    SDL_SetRenderDrawColor(prenderer, 0 ,0, 0, SDL_ALPHA_OPAQUE);

    /* paints the canvas black */
    SDL_RenderClear(prenderer);

    /* this presents the render onto the screen*/
    SDL_RenderPresent(prenderer);

    /* this allows macOS to process the window state immediately */
    SDL_PumpEvents();

    /* keeps the window open for 3 seconds (3000ms)*/
    SDL_Delay(1000);

    /* cleans memory before exiting */
    SDL_DestroyRenderer(prenderer);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();

    return 0;

}
