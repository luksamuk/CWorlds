CWorlds v0.1
=======================

THIS PROJECT IS DEPRECATED
------------
This is a deprecation notice. I've moved on a long time ago from this; also, I went ahead and remove my pretensious statement that this would be a C++ port of Sonic Worlds, because it never was.

Anyway, this is open so that people may take a look at what I did here.


Dependancies
------------
- SDL2
- SDL2_image

Compiling
---------
On the root folder, make two folders: one called bin, and other
called obj.

<code>$ mkdir bin obj</code>

Then, go to the src folder and run make.

<pre><code>$ cd src
$ make
</code></pre>

You need to have GCC 4.7 or up installed, along with the above dependancies.
If you're running Ubuntu 13.10 "Saucy Salamander" or Ubuntu 14.04 "Trusty Tahr",
all you need to do is install these packages:

<code>$ sudo apt-get install build-essential git libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev</code>

Then execute the steps above.

For building on Windows, you might want to use an IDE such as Code::Blocks, with MinGW compiler, and the SDL2 and SDL2_image libraries, which can be found on these links:
- https://libsdl.org/
- https://www.libsdl.org/projects/SDL_image/

We'll be using the versions 2.0.X for everything.

There's also an optional Code::Blocks project for Linux, if you're not much into using the terminal.

Stay sharp for updates on this README, as new libraries could be added.


License
-------
This project is now distributed under the MIT license.
