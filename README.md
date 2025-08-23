# LogNest

## A Simple yet customizable header only library for logging in C.

![image](images/example2.png)
<sub>Image depicting the dafault configuration result</sub>

## Installing:

```
wget https://raw.githubusercontent.com/LeaoMartelo2/LogNest/main/lognest.h
```
<sub>just copy this if you are lazy</sub>

## Usage:

(Please refer to the examples if needed)

- Download `lognest.h` and add it to your project.
- `#define` the settings for your program ONLY in one file.
- Add `#define LOGNEST_IMPLEMENTATION` before including it ONLY in one file (the same you configured on).
- `#include` lognest.h normally and in any other file you need.

## Configuration:

- Disable any specific log level with:

```c
#define LOGNEST_DISABLE_<TRACE/WARN/ERROR/DEBUG>
```
<sub> Pairs great with -DLOGNEST_DISABLE<LEVEL> on compile flags </sub>

- Change any log level identifier prefix with :
```c 
#define LOGNEST_<TRACE/WARN/ERROR/DEBUG>_PREFIX "<custom prefix>"
```
<sub> The separators (`[]`) around the type must also be included here. </sub>

- Optionally change where the log file path with:

```c 
#define LOGNEST_FILE "path/to/log/filename.log"
```

<sub> Defaults to `latest.log` </sub>

- Optionally disable the log's time or date of message with:

```c 
#define LOGNEST_DISABLE_TIMESTAMP
/* or */
#define LOGNEST_DISABLE_DATESTAMP
```

- Optionally allow crashing on error with:
```c
#define LOGNEST_ALLOW_CRASH
```

- Some other misc configurations can be changed with:
```c 
#define LOGNEST_ABORT()
/* uses stdlib's abort() for crashing */
#define LOGNEST_API
/* added before every function definition, use it to add stuff like `static inline` on single file projects */
```

![image](images/usage2.png)

## Latest update changes:


### LogNest 2.1.6

- Fix issue with `LOGNEST_API` macro causing some issues with its defult behaviour, now its up to the user to enable it.
- Add macro to replace force exiting / crashing on error function with your own.
