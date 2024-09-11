#include <iostream>
#include <lognest/lognest.hpp>

int main() {

    auto log_example = std::make_shared<LogNest>("latest.log", "[log_example]");

    std::cout << "Hello, world\n";

    log_example->log(LN_LOG, "Normal Log with 1 argument: {}", "hello");
    log_example->log(LN_WARN, "Warn log with no arguments");
    log_example->log(LN_ERROR, "{} The arguments can, be anywhere on the message {}", "HELLO", "WORLD");
    log_example->log(LN_DEBUG, "With almost any type! int: {} float: {}, char: {}, std::string: {}", 1, 5.4f, 'h', "HELLO");

    return 0;
}
