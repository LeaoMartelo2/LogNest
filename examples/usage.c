#define LOGNEST_IMPLEMENTATION
#define LOGNEST_FILE "latest.log"
#include "../lognest.h"

int main(void) {

    lognest_trace("This is a trace message. Sample value: %d", 100);

    lognest_warn("This is a warn. %s", "Be careful!");

    lognest_error("This is an error message: %s", "Something went wrong!");

    lognest_debug("This is a debug message: %f", 3.14);

    return 0;
}
