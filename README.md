# LogNest

## A "Header file only" library for logging to files made in C, with focus on simplicity

![image](images/example2.png)

## Installing:

```
wget https://raw.githubusercontent.com/LeaoMartelo2/LogNest/main/lognest.h
```
<sub>just copy this if you are lazy</sub>

## Usage:

- Download `lognest.h` and add it to your project.
- Any specific log level can be disabled with:

```c
#define LOGNEST_DISABLE_TRACE
#define LOGNEST_DISABLE_WARN
#define LOGNEST_DISABLE_ERROR
#define LOGNEST_DISABLE_DEBUG
```

- Optionally change where the log file is sent to  (default: "latest.log") with:

```c 
#define LOGNEST_FILE "path/to/log/filename.log"
```

- Optionally disable the log's timestamp with:

```c 
#define LOGNEST_DISABLE_TIMESTAMP
```

(All configuration defines must come before the implementation define)

- For the library to serve as implementation, add: `#define LOGNEST_IMPLEMENTATION` before the `#include`.
- This also means you should only define the implementation in one file. Just including it serves as a header.

![image](images/usage2.png)

## Updates:


### LogNest 2.1 (August 1st, 2025)

- Renamed some internal functions to avoid name hogging.
- Added the ability to disable the `Timestamp` on logging.

use: 
```c 
#define LOGNEST_DISABLE_TIMESTAMP
```

before defining the implementation.


- Fixed some UX around changing the file being logged to.

you can now do:

```c 
#define LOGNEST_FILE "path/to/log/filename.log"
```
before defining the implementation




### LogNest 2.0 (May 7th, 2025)

- Improved compiler compatibility by removing some parts of the code that i didn't knew were GNU extensions.


- Added new Macros for disabling a log level entirely

you can now disable any log level with:

```c
#define LOGNEST_DISABLE_TRACE
#define LOGNEST_DISABLE_WARN
#define LOGNEST_DISABLE_ERROR
#define LOGNEST_DISABLE_DEBUG
```

That has to be defined before the implementation define, that is already before the #include

- Added a new macro that returns a c literal of the current LogNest version


