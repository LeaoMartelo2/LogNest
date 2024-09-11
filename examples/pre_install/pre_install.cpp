#include "../../src/lognest.hpp"
#include <iostream>
int main() {

    std::cout << "Hello, world\n";

    auto LogExample = std::make_shared<LogNest>("latest.log", "[LogExample]");

    LogExample->log(LN_LOG, "Regular log {}", 1);
    LogExample->log(LN_WARN, "Warn {} Log {}", 2, 3);
    LogExample->log(LN_ERROR, "{} Error log", 4);
    LogExample->log(LN_DEBUG, "Debug log");

    return 0;
}
