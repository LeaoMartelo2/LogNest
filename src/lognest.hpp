#ifndef LOGNEST_HPP
#define LOGNEST_HPP

#include <fmt/core.h>

#define LN_LOG LogNest::LogType::LOG
#define LN_ERROR LogNest::LogType::ERROR
#define LN_WARN LogNest::LogType::WARN
#define LN_DEBUG LogNest::LogType::DEBUG

class LogNest {

    public:
        LogNest(std::string filename, std::string identifier);
        ~LogNest();

    public:
        enum class LogType { LOG,
                             ERROR,
                             WARN,
                             DEBUG
        };

        template <typename... Args>
        void log(LogType level, const std::string &format_string, Args &&...args) {

            std::string formated_message = log_identifier;
            formated_message += get_log_level_string(level);
            formated_message += fmt::format(format_string, std::forward<Args>(args)...);
            print_to_file(formated_message);
        }

        void set_log_file(std::string filename);

        void set_log_level_identifier(std::string new_name);

    private:
        void print_to_file(std::string log_line);

        std::string get_log_level_string(LogType level);

        std::string log_identifier = "Default";
        std::string log_file = "latest.log";
};

#endif // !LOGNEST_HPP
