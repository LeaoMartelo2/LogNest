#include "lognest.hpp"
#include <chrono>
#include <ctime>
#include <fstream>
#include <string>

LogNest::LogNest(std::string filename, std::string identifier) {
    set_log_file(filename);
    set_log_level_identifier(identifier);
}

LogNest::~LogNest() {
}

void LogNest::set_log_file(std::string filename) {

    log_file = filename;
}

void LogNest::set_log_level_identifier(std::string new_name) {
    log_identifier = new_name;
}

std::string LogNest::get_log_level_string(LogNest::LogType level) {

    switch (level) {
    case LogNest::LogType::LOG:
        return "[LOG]  :";
        break;

    case LogNest::LogType::WARN:
        return "[WARN] :";
        break;

    case LogNest::LogType::ERROR:
        return "[ERROR]:";
        break;
    case LogNest::LogType::DEBUG:
        return "[DEBUG]:";
        break;

    default:
        return "[UNREACHABLE]";
    }
}

void LogNest::print_to_file(std::string log_line) {

    /*std::cout << "print_to_file called\n";*/

    auto now = std::chrono::system_clock::now();

    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm *local_time = std::localtime(&now_c);

    int day = local_time->tm_mday;
    int month = local_time->tm_mon + 1;
    int year = local_time->tm_year + 1900;
    int hour = local_time->tm_hour;
    int minute = local_time->tm_min;
    int second = local_time->tm_sec;

    std::fstream file(log_file, std::ios::app);

    if (!file.is_open()) {
        file.open(log_file, std::ios::out);
    }

    file << '[' << year << '/' << month << '/' << day << ']'
         << '[' << hour << ':' << minute << ':' << second << ']'
         << log_line << '\n';

    file.close();
}
