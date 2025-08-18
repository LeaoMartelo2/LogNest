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
- Any specific log level can be disabled with:

```c
#define LOGNEST_DISABLE_<TRACE/WARN/ERROR/DEBUG>
```

- Change the log type indicator prefix with:

```c 
#define LOGNEST_<TRACE/WARN/ERROR/DEBUG>_PREFIX "<custom prefix>"
```
- The separators (`[]`) around the type must also be included here.

- Optionally change where the log file is sent to  (default: "latest.log") with:

```c 
#define LOGNEST_FILE "path/to/log/filename.log"
```

- Optionally disable the log's time or date of the message with:

```c 
#define LOGNEST_DISABLE_TIMESTAMP
/* or */
#define LOGNEST_DISABLE_DATESTAMP
```

- Optionally allow crashing on error with:
```c
#define LOGNEST_ALLOW_CRASH
```

(All configuration defines must come before the implementation define)

- For the library to serve as implementation, add: `#define LOGNEST_IMPLEMENTATION` before finally `#include`-ing the file.
- Only add the `Implementation` define to a single file, adding the `.h` to multiple files is ok.

![image](images/usage2.png)

## Latest update changes:


### LogNest 2.1.5 

- Added `LOGNEST_API` macro (defaulted to `static inline`) to allow you to change how lognest functions are defined.

- Added macros do change the prefix of the log level identifier, add this before the implementation define:

```c 
#define LOGNEST_<TRACE/WARN/ERROR/DEBUG>_PREFIX "<custom prefix goes here>"
```

- Added split the macro to divide the timestamp do allow to individually disable the date-stamp with `#define LOGNEST_DISABLE_DATESTAMP`
- Renamed some internal macros with common names to avoid name hogging.
- Added a option to allow crashing on error:
```c
#define LOGNEST_ALLOW_CRASH
```
