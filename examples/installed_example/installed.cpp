#include <iostream>
#include <lognest/lognest.hpp>

int main() {

    auto log_example = std::make_shared<LogNest>("latest.log", "[log_example]");

    std::cout << "Hello, world\n";

    log_example->log(LN_LOG, "Normal Log with 1 argument: {}", "hello");
    log_example->log(LN_WARN, "Warn log with no arguments");
    log_example->log(LN_ERROR, "Error log with 2 arguments {}, {}", "hello", "world");
    log_example->log(LN_DEBUG, "Debug log with int arguments {}", 123);

    return 0;
}
