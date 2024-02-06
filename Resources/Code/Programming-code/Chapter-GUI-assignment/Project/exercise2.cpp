#include <iostream>
#include <sstream>
#include "Graph.h"         // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"
#include "FL/Fl_File_Chooser.H"

using namespace Graph_lib;
using namespace std;


struct Carousel_window: Graph_lib::Window {
    public:
        // Constructor
        Carousel_window(Point xy, int w, int h, const string& title);
    private:
        // Widgets
        Button open_image_button;
        Button next_image_button;
        Button previous_image_button;
        Image* current_img;
        vector<string> image_paths;
        int current_img_idx;

        void open_image_button_pressed();
        void next_image_button_pressed();
        void previous_image_button_pressed();

        // callback functions:
        static void cb_open(Address, Address);
        static void cb_next(Address, Address);
        static void cb_previous(Address, Address);
};

Carousel_window::Carousel_window(Point xy, int w, int h, const string& title)
    :Window(xy, w, h, title),
    open_image_button(Point(20, 20), 90, 40, "Open Image", cb_open),
    next_image_button(Point(x_max()/2, y_max() - 125), 90, 40, "Next Image", cb_next),
    previous_image_button(Point(x_max()/2 - 120, y_max() - 125), 110, 40, "Previous Image", cb_previous)
{
    current_img_idx = 0;
    current_img = new Image(Point(0, 0), "");
    attach(open_image_button);
    attach(next_image_button);
    attach(previous_image_button);
}

void Carousel_window::open_image_button_pressed()
{
    Fl_File_Chooser chooser(".", "*.jpg, *.jpeg", Fl_File_Chooser::MULTI, "Open Image");
    chooser.show();

    // Block until user picks something.
    // (The other way to do this is to use a callback())
    while(chooser.shown())
        { Fl::wait(); }

    // User hit cancel?
    if ( chooser.value() == NULL )
        { fprintf(stderr, "(User hit 'Cancel')\n"); return; }

    // Print what the user picked
    fprintf(stderr, "--------------------\n");
    fprintf(stderr, "DIRECTORY: '%s'\n", chooser.directory());
    fprintf(stderr, "    VALUE: '%s'\n", chooser.value());
    fprintf(stderr, "    COUNT: %d files selected\n", chooser.count());

    detach(*current_img);
    string path = chooser.value();
    image_paths.push_back(path);
    current_img_idx = image_paths.size()-1;
    current_img = new Image(Point(x_max()/2 - 150, y_max()/2 - 100), path);
    // img.set_mask(Point(40,40),200,150);       // display center part of image
    // img.move(100, 100);
    attach(*current_img);
    redraw();

    // Multiple files? Show all of them
    if ( chooser.count() > 1 ) {
        for ( int t = 2; t <= chooser.count(); t++ ) {
            std::string path = chooser.value(t);
            image_paths.push_back(path);
            fprintf(stderr, " VALUE[%d]: '%s'\n", t, chooser.value(t));
        }
    }
}

void Carousel_window::next_image_button_pressed()
{
    if (image_paths.empty() || current_img_idx >= image_paths.size()-1) return;

    detach(*current_img);
    current_img = new Image(Point(x_max()/2 - 150, y_max()/2 - 100), image_paths[++current_img_idx]);
    attach(*current_img);
    redraw();
}

void Carousel_window::previous_image_button_pressed()
{
    if (image_paths.empty() || current_img_idx == 0) return;

    detach(*current_img);
    current_img = new Image(Point(x_max()/2 - 150, y_max()/2 - 100), image_paths[--current_img_idx]);
    attach(*current_img);
    redraw();
}

//----------------------- Callbacks -------------------------------
void Carousel_window::cb_next(Address, Address pw) 
{
    reference_to<Carousel_window>(pw).next_image_button_pressed();
}

void Carousel_window::cb_open(Address, Address pw)
{
    reference_to<Carousel_window>(pw).open_image_button_pressed();
}

void Carousel_window::cb_previous(Address, Address pw)
{
    reference_to<Carousel_window>(pw).previous_image_button_pressed();
}
//------------------------------------------------------------------

int main()
try {
    Carousel_window win(Point(300, 100),800,600,"Carousel");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}