# Simple Header file only library in C to easily make log files 

![image](images/example2.png)

## Installing:

```
wget https://raw.githubusercontent.com/LeaoMartelo2/LogNest/main/lognest.h
```

- Just grab the `lognest.h` file and add it to your project.
- You need to remember that only including the file serves as forward declaring/API.
- For the library to serve as implementation, add: `#define LOGNEST_IMPLEMENTATION` before the `#include`.
- This also means you should only define the implementation in one file.
- Remember to also `#define LOGNEST_FILE "your/file/path/here.log"` before including it.

## Usage:

![image](images/usage2.png)

- Is as simple as that.

