#include "lognest.hpp"
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
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

    auto now = std::chrono::system_clock::now();

    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm *local_time = std::localtime(&now_c);

    /*padding boilerplate
     * basically makes so numbers <10 start with a 0
     * such as:
     * 5 -> 05
     * 11 -> 11 (unchanged)*/

    std::ostringstream day;
    day << std::setw(2) << std::setfill('0') << local_time->tm_mday;
    std::string padded_day = day.str();

    std::ostringstream month;
    month << std::setw(2) << std::setfill('0') << local_time->tm_mon + 1;
    std::string padded_month = month.str();

    int year = local_time->tm_year + 1900;

    std::ostringstream hour;
    hour << std::setw(2) << std::setfill('0') << local_time->tm_hour;
    std::string padded_hour = hour.str();

    std::ostringstream minute;
    minute << std::setw(2) << std::setfill('0') << local_time->tm_min;
    std::string padded_minute = minute.str();

    std::ostringstream second;
    second << std::setw(2) << std::setfill('0') << local_time->tm_sec;
    std::string padded_second = second.str();

    std::fstream file(log_file, std::ios::app);

    if (!file.is_open()) {
        file.open(log_file, std::ios::out);
    }

    file << '[' << year << '/' << padded_month << '/' << padded_day << ']'
         << '[' << padded_hour << ':' << padded_minute << ':' << padded_second << ']'
         << log_line << '\n';

    file.close();
}
