#include <SDL2/sdl.h>
#include <stdio.h>
#include <assert.h>
#define NUM_RECT 30
#define INDEX_ARRAY(ARR, X, Y, RECT) ARR[(X) + (RECT * (Y))]

int rect_map[NUM_RECT * NUM_RECT] =  {\
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,
    0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
    0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};


void print_rect(const int *rect_map) {
    for (int i = 0; i < NUM_RECT; i++) {
        for (int j = 0; j < NUM_RECT; j++) {
            printf("%d ", INDEX_ARRAY(rect_map, j, i, NUM_RECT));
        }
        printf("\n");
    }
    printf("\n");
}


int get_neighbours_count(const int *rect_map, int x, int y) {
    //(x-1,y-1) (x,y-1) (x+1,y-1)
    //(x-1,  y) (x,  y) (x+1,  y) 
    //(x-1,y+1) (x,y+1) (x+1,y+1)
    int ncount = 0;
    if (x > 0 && y > 0) {
        ncount += INDEX_ARRAY(rect_map, x-1, y-1, NUM_RECT);
    }
    if (y > 0) {
        ncount += INDEX_ARRAY(rect_map, x, y-1, NUM_RECT);
    }
    if (x < (NUM_RECT - 1) && y > 0) {
        ncount += INDEX_ARRAY(rect_map, x+1, y-1, NUM_RECT);
    }
    if (x > 0) {
        ncount += INDEX_ARRAY(rect_map, x-1, y, NUM_RECT);
    }
    if (x < (NUM_RECT - 1)) {
        ncount += INDEX_ARRAY(rect_map, x+1, y, NUM_RECT);
    }
    if (x > 0 && y < (NUM_RECT - 1)) {
        ncount += INDEX_ARRAY(rect_map, x-1, y+1, NUM_RECT);
    }
    if (y < NUM_RECT - 1) {
        ncount += INDEX_ARRAY(rect_map, x, y+1, NUM_RECT);
    }
    if (x < (NUM_RECT - 1) && y < (NUM_RECT - 1)) {
        ncount += INDEX_ARRAY(rect_map, x+1, y+1, NUM_RECT);
    }
    return ncount;
}

void update_map(int *rect_map) {
    int new_rect[NUM_RECT * NUM_RECT];
    for (int i = 0; i < NUM_RECT * NUM_RECT; i++) {
        new_rect[i] = 0;
    }
    for (int i = 0; i < NUM_RECT; i++) {
        for (int j = 0; j < NUM_RECT; j++) {
            int n = get_neighbours_count(rect_map, j, i);
            if (INDEX_ARRAY(rect_map, j, i, NUM_RECT) == 1 && ((n == 2) || (n == 3))) {
                INDEX_ARRAY(new_rect, j, i, NUM_RECT) = 1;
            } 
            if (INDEX_ARRAY(rect_map, j, i, NUM_RECT) == 0 && n == 3) {
                INDEX_ARRAY(new_rect, j, i, NUM_RECT) = 1;
            }
        }
    }
    for (int i = 0; i < NUM_RECT * NUM_RECT; i++) {
        rect_map[i] = new_rect[i];
    }
}

void show_rect(SDL_Renderer *renderer, int width, int height, const int *rect_map) {
    int padding = 5;
    // width = (total space) - (space between rect) - (space on left and right border) / (num of rect)
    int rect_width = (width - ((NUM_RECT + 1) * padding))/NUM_RECT;
    int rect_height = (height - ((NUM_RECT + 1) * padding))/NUM_RECT;
    for (int i = 0, y = 0; (i < NUM_RECT); y+=rect_height, i++) {
        y += padding;
        for (int j = 0, x = 0; (j < NUM_RECT); x+=rect_width, j++) {
            x += padding;
            SDL_Rect rect = {
                .x = x,
                .y = y,
                .w = rect_width,
                .h = rect_height,
            };
            if (INDEX_ARRAY(rect_map, j, i, NUM_RECT) == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // dead
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // alive
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}


int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int width = 605;
    int height = 605;

    SDL_Rect bg_rect = {
        .x = -1,
        .y = -1,
        .w = width,
        .h = height,
    };

    float fps = 5;
    float ms_per_frame = (1/(float)fps) * 1000.0f; 
    int generation = 0;
    int last_timer = 0;
    SDL_Event event;
    int quit = 0;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Init");
    } else {
        window = SDL_CreateWindow( "Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
        if (window == NULL) {
            printf("SDL_CreateWindow");
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // set background color
            SDL_RenderFillRect(renderer, &bg_rect);
            while (!quit) {
                while(SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = 1;
                    }
                    if (event.type == SDL_KEYDOWN) {
                        if (event.key.keysym.scancode== SDL_SCANCODE_ESCAPE) {
                            quit = 1;
                        }
                        if (event.key.keysym.scancode== SDL_SCANCODE_W) {
                            fps = (fps < 60) ? fps + 0.5 : fps;
                            ms_per_frame = (float)(1/fps) * 1000.0f; 
                        }
                        if (event.key.keysym.scancode== SDL_SCANCODE_S) {
                            fps = (fps > 2) ? fps - 0.5 : fps;
                            ms_per_frame = (float)(1/fps) * 1000.0f; 
                        }
                        assert(fps > 0);
                        assert(fps < 60);
                    }
                }
                show_rect(renderer, width, height, rect_map);
                printf("Generation: %d\n", generation++);
                SDL_RenderPresent(renderer);
                if (last_timer > 0) {
                    int current_timer = SDL_GetTicks();
                    int ms_elapsed = current_timer - last_timer;
                    int delay = (int)ms_per_frame - ms_elapsed;
                    if (delay > 0) {
                        SDL_Delay(delay);
                    }
                    update_map(rect_map);
                }
                last_timer = SDL_GetTicks();
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
