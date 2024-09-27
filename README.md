# Simple single header C library to easily make log files 

![image](images/example.png)

## Installing:

Installing is as easy as:

    git clone https://github.com/LeaoMartelo2/lognest

    cd lognest/src

    make && sudo make install

<small>(this is a single header and translation unit header, you can add it dirrectly to your project, if you know what you are doing)</small>

# Usage:
- The main header should be included: 
`#include <lognest/lognest.h>`

- To begin using the library, you'll need to create a logging channel, you can have multiple of them, and they can be printed to the same file or not!.

![image](images/usage.png)
 
  - `.identifier` Defines what will be its identifier on the file.
  - `.filename` Defines the path and name of the file it will be logged to, different channels can go to the same file or not.

	
- Following the example given above, we can create a log using
`log_trace(&log_example, "Hello, World!");`

	- You can use the logging functions to write your info to the desired file.
	- (`log_trace()`, `log_warn()`, `log_error()` and `log_debug()`)
	- They all accept formmating arguments (`%d, %f, etc`) just like `printf()`

- Compile with `-lLogNest`

