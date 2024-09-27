#include <lognest/lognest.h>
#include <stdio.h>

int main(void) {

    printf("Hello, World!\n");

    Log log_example = {
        .identifier = "[log_example]",
        .filename = "latest.log",
    };

    Log another = {.identifier = "another_channel", .filename = "not_latest.txt"};

    log_trace(&log_example, "normal log with arguments at the end %d", 1);
    log_warn(&log_example, "Warning with %d on the middle", 32);
    log_error(&log_example, "Error with no extra arguments");
    log_debug(&log_example, "debug example with x = %f", 3.14f);

    return 0;
}
