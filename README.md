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
- For the library to serve as implementation, add: `#define LOGNEST_IMPLEMENTATION` before the `#include`.
- This also means you should only define the implementation in one file. Just including it serves as a header.
- Optionally cuztomize the output path in `lognest.h`, by changing `#define LOGNEST_FILE "your/custom/path"`
- The path is relative to the executable

![image](images/usage2.png)
