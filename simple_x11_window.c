// Author: William Selby
// open a simple x11 window

#include <X11/Xlib.h>
#include <stdio.h>

int main()
{
    // Open a connection to the X server
    Display *display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        printf("Cannot open display\n");
        return -1;
    }

    // Get the default root window
    Window root = DefaultRootWindow(display);

    // Create a window
    int width = 300;
    int height = 300;
    Window window = XCreateSimpleWindow(display, root, 0, 0, width, height, 0, BlackPixel(display, 0), WhitePixel(display, 0));

    // Set window name
    XStoreName(display, window, "My Window");

    // Select which events we want to handle
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Map the window to the screen
    XMapWindow(display, window);

    // Event loop
    while (1)
    {
        // Get next event
        XEvent event;
        XNextEvent(display, &event);

        // Handle Expose event
        if (event.type == Expose)
        {
            printf("Window Exposed\n");
        }

        // Handle KeyPress event
        if (event.type == KeyPress)
        {
            printf("Key pressed\n");
            break;
        }
    }

    // Close connection to X server
    XCloseDisplay(display);

    return 0;
}
