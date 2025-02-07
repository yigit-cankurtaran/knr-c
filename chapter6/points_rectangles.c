#include <stdio.h>

#define XMAX 500
#define YMAX 500
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
}; // we will use this one a lot

struct rect { // rectangles in 2d spaces are fully defined if we know any 2 opposite corners
    struct point pt1; // pt1 should generally be smaller than pt2 to symbolize the left
    // if it's not we can "canonicalize" it to make it fit our format
    struct point pt2;
}; // structs also need ; after them

// i can now use this to initialize any structure dynamically
struct point makepoint(int x, int y) { // function that returns a struct point
    struct point temp; // we initialize a struct point named temp

    temp.x = x; // the x of temp is what we pass into it
    temp.y = y; // the y of temp is what we pass into it
    return temp; // we return this struct point
}

struct rect canonrect(struct rect r) {
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    // we want pt1 to be on the left and bottom point of a rectangle
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    // we want pt2 to be on the right and top point of a rectangle
    // by knowing 2 opposite points we can know how to show this rectangle
    return temp;

}

void print_point(struct point p) {
    printf("point; (%d, %d)\n", p.x, p.y);
}

struct point addpoint(struct point p1, struct point p2) {
    // both arguments and the return are structures
    p1.x += p2.x;
    p1.y += p2.y; // adding both their points
    // if we don't want to do the arithmetic on p1 itself we can just use a temp var
    return p1;
}

int ptinrect(struct point p, struct rect r){
    // function to see if a point is in a rectangle

    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
    // if the x of the point is bigger or equal than the left side of the x of the rect
    // or smaller than the right side of its x it's in the x
    // run the same check for the y side
    // if it returns a 1 and 1 (both are in the values) it returns a 1 and 0 otherwise
}

int main(void) {
    struct rect screen;
    struct point middle;
    struct point origin, *pp; // pointer to a struct
    // pp points to a structure, *pp is the structure
    // (*pp).x and (*pp).y are the members

    origin.x = 0;
    origin.y = 0;

    pp = &origin; // pp is the address of origin
    // printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
    printf("origin is (%d, %d)\n", pp->x, pp->y); // this is special notation for this

    screen.pt1 = origin;
    screen.pt2 = makepoint(XMAX, YMAX);
    screen = canonrect(screen);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                       (screen.pt1.y + screen.pt2.y) / 2);

    print_point(middle); // prints (250, 250)
}
