#include "bisto.h"

namespace Bisto {

    // ================= Input Class =================
    int Input::getInt(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;

            if (std::cin.good()) {
                return value;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "خطأ — أدخل رقم صحيح.\n";
        }
    }

    double Input::getDouble(const std::string& prompt) {
        double value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.good()) return value;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "خطأ — أدخل رقم.\n";
        }
    }

    std::string Input::getstring(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            if (std::cin.peek() == '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::getline(std::cin, input);
            
            bool isEmptyOrWhitespace = std::all_of(input.begin(), input.end(), [](unsigned char c) {
                return std::isspace(c);
            });

            if (!isEmptyOrWhitespace) {
                return input; 
            }
        }
    }

    float Input::getfloat(const std::string& prompt) {
        float value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            std::cout << "إدخال خاطئ! يرجى إدخال رقم صحيح.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }



    // ================= strings Class =================
    std::string strings::getstring(const std::string& prompt) {
        Input in;
        return in.getstring(prompt);
    }

    std::string strings::Lower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        return str;
    }

    std::string strings::Upper(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::toupper(c);
        });
        return str;
    }

    std::string strings::trim(std::string str) {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));

        str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), str.end());

        return str;
    } 

    bool strings::startsWith(std::string_view text, std::string_view target) {
        if (target.empty()) return true;
        if (text.size() < target.size()) return false;
        return text.compare(0, target.size(), target) == 0;
    }

    bool strings::endsWith(std::string_view text, std::string_view target) {
        if (target.empty()) return true;
        if (text.size() < target.size()) return false;
        return text.compare(text.size() - target.size(), target.size(), target) == 0;
    }

    std::vector<std::string> strings::split(std::string_view text, char delimiter) {
        std::vector<std::string> result;
        size_t start = 0;
        size_t end = text.find(delimiter);

        while (end != std::string_view::npos) {
            result.emplace_back(text.substr(start, end - start));
            start = end + 1;
            end = text.find(delimiter, start);
        }
        result.emplace_back(text.substr(start));

        return result;
    }

    std::string strings::replace(std::string text, std::string_view oldWord, std::string_view newWord) {
        if (oldWord.empty()) return text;

        size_t pos = 0;
        while ((pos = text.find(oldWord, pos)) != std::string::npos) {
            text.replace(pos, oldWord.length(), newWord);
            pos += newWord.length(); 
        }
        return text;
    }

    bool strings::contains(std::string_view text, std::string_view target) {
        return text.find(target) != std::string_view::npos;
    }


    
    // ================= randoms Class =================
    std::mt19937& randoms::getRNG() {
        thread_local std::mt19937 rng{std::random_device{}()};
        return rng;
    }

    int randoms::randomInt(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(getRNG());
    }

    double randoms::randomDouble(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(getRNG());
    }

    bool randoms::randomBool() {
        std::bernoulli_distribution dist(0.5);
        return dist(getRNG());
    }

    char randoms::randomChar() {
        const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        int index = randomInt(0, static_cast<int>(chars.size()) - 1);
        return chars[index];
    }

    std::string randoms::randomString(int length) {
        if (length <= 0) return "";
        
        const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*().[]<>{}~`¿¡";
        std::string result;
        result.reserve(length);

        for (int i = 0; i < length; ++i) {
            result += chars[randomInt(0, static_cast<int>(chars.size()) - 1)];
        }
        return result;
    }
    bool logger::isNumber(std::string_view text){
        if (text.empty()) return false;
        for (char c : text) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                return false;
            }
        }
        return true;
    }


    bool logger::isStrongPassword(std::string_view password) {
        if (password.length() < 8) return false;

        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSpecial = false;

        for (char c : password) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                hasUpper = true;
            } else if (std::islower(static_cast<unsigned char>(c))) {
                hasLower = true;
            } else if (std::isdigit(static_cast<unsigned char>(c))) {
                hasDigit = true;
            } else if (std::ispunct(static_cast<unsigned char>(c))) {
                hasSpecial = true;
            }
        }

        return hasUpper && hasLower && hasDigit && hasSpecial;
    }

    void logger::menushow(std::string prompt, const std::vector<std::string>& Show) {
        std::cout << prompt << "\n";
        int nums = 1;
        for (const auto& it : Show) {
            std::cout << nums << "-" << it << "\n";
            nums++;
        }
        std::cout << "0-exit\n";
    }

    // Global Function Implementation
    void Hashing(std::string hash) {
        // Implement hashing logic here
    }

} // namespace Bisto