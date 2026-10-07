#pragma once

#include <fstream>

namespace ip {

    class Logger {

    public:
        Logger();
        ~Logger();

        void success(const std::string& command);
        void failure(const std::string& command);


    private:
        std::ofstream m_file;


    };
}

// namespace ip