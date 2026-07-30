#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <string_view>
#include <vector>
#include <random>

namespace Bisto {

    class Color {
    public:
        //  (Foreground)
        static inline const std::string RESET   = "\033[0m";
        static inline const std::string BLACK   = "\033[30m";
        static inline const std::string RED     = "\033[31m";
        static inline const std::string GREEN   = "\033[32m";
        static inline const std::string YELLOW  = "\033[33m";
        static inline const std::string BLUE    = "\033[34m";
        static inline const std::string MAGENTA = "\033[35m";
        static inline const std::string CYAN    = "\033[36m";
        static inline const std::string WHITE   = "\033[37m";

        // (Bold/Bright)
        static inline const std::string BOLD_RED     = "\033[1;31m";
        static inline const std::string BOLD_GREEN   = "\033[1;32m";
        static inline const std::string BOLD_YELLOW  = "\033[1;33m";
        static inline const std::string BOLD_BLUE    = "\033[1;34m";

        // Background
        static inline const std::string BG_RED      = "\033[41m";
        static inline const std::string BG_GREEN    = "\033[42m";
        static inline const std::string BG_YELLOW   = "\033[43m";
        static inline const std::string BG_BLUE     = "\033[44m";
    };

    class Input {
    public:
        int getInt(const std::string& prompt);
        double getDouble(const std::string& prompt);
        std::string getstring(const std::string& prompt);
        float getfloat(const std::string& prompt);
    };

    class strings {
    public:
        std::string getstring(const std::string& prompt);
        std::string Lower(std::string str);
        std::string Upper(std::string str);
        std::string trim(std::string str);

        bool startsWith(std::string_view text, std::string_view target);
        bool endsWith(std::string_view text, std::string_view target);

        std::vector<std::string> split(std::string_view text, char delimiter);
        std::string replace(std::string text, std::string_view oldWord, std::string_view newWord);
        bool contains(std::string_view text, std::string_view target);
    };

    class randoms {
    private:
        std::mt19937& getRNG();
    public:
        int randomInt(int min, int max);
        double randomDouble(double min, double max);
        bool randomBool();
        char randomChar();
        std::string randomString(int length);
    };

    class logger {
    public:
        bool isNumber(std::string_view text);
        bool isStrongPassword(std::string_view password);
        void menushow(std::string prompt, const std::vector<std::string>& Show);
    };

    class vectors {};

    void Hashing(std::string hash);

}