#define LOGNEST_DISABLE_DEBUG
#define LOGNEST_WARN_PREFIX "[warning]"
#define LOGNEST_DISABLE_DATESTAMP
#define LOGNEST_FILE "example.log"
#define LOGNEST_IMPLEMENTATION
#include "../lognest.h"

int main(void) {

    lognest_trace("This is a trace message. Sample value: %d", 100);

    lognest_warn("This is a warn. %s", "Be careful!");

    lognest_error("This is an error message: %s", "Something went wrong!");

    lognest_debug("This message wont show up!");

    lognest_trace("This is a message without extra args!");

    return 0;
}





