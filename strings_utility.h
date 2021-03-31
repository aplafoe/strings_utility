#ifndef STRINGS_UTILITY
#define STRINGS_UTILITY
#include <string>
#include <string_view>
#include <vector>
#include <string.h>
#include <algorithm>
namespace strings_utility {
    using size_t = unsigned int;
    template<typename chars>
    std::vector<std::pair<size_t, size_t>> get_idx_of_all_substrings(const std::basic_string<chars>& str,
        const std::basic_string<chars>& substr) {
        std::vector<std::pair<size_t, size_t>> idx_of_all_substr;
        idx_of_all_substr.reserve(str.size() * 2);
        size_t idx = str.find(substr.c_str(), 0U);
        if (idx == size_t(-1)) {
            idx_of_all_substr.reserve(0U);
            return idx_of_all_substr;
        }
        while (idx != size_t(-1)) {
            idx_of_all_substr.emplace_back(std::make_pair(idx, idx + (substr.size() - 1)));
            idx = str.find(substr.c_str(), idx + substr.size());
        }
        idx_of_all_substr.shrink_to_fit();
        return idx_of_all_substr;
    }
    template<typename chars>
    std::vector<std::pair<size_t, size_t>> get_idx_of_all_substrings(const std::basic_string_view<chars> str,
        const std::basic_string_view<chars>& substr) {
        std::vector<std::pair<size_t, size_t>> idx_of_all_substr;
        idx_of_all_substr.reserve(str.size() * 2);
        size_t idx = str.find(substr.data(), 0U);
        if (idx == size_t(-1)) {
            idx_of_all_substr.reserve(0U);
            return idx_of_all_substr;
        }
        while (idx != size_t(-1)) {
            idx_of_all_substr.emplace_back(std::make_pair(idx, idx + (substr.size() - 1)));
            idx = str.find(substr.data(), idx + substr.size());
        }
        idx_of_all_substr.shrink_to_fit();
        return idx_of_all_substr;
    }
    inline std::vector<std::pair<size_t, size_t>> get_idx_of_all_substrings(const std::string& str,
        const char* const substr) {
        std::vector<std::pair<size_t, size_t>> idx_of_all_substr;
        idx_of_all_substr.reserve(str.size() * 2);
        const size_t len = std::strlen(substr);
        size_t idx = str.find(substr);
        if (idx == size_t(-1)) {
            idx_of_all_substr.reserve(0U);
            return idx_of_all_substr;
        }
        while (idx != size_t(-1)) {
            idx_of_all_substr.emplace_back(std::make_pair(idx, idx + (len - 1)));
            idx = str.find(substr, idx + len);
        }
        idx_of_all_substr.shrink_to_fit();
        return idx_of_all_substr;
    }
    inline std::vector<std::pair<size_t, size_t>> get_idx_of_all_substrings(const std::string_view str,
        const char* const substr) {
        std::vector<std::pair<size_t, size_t>> idx_of_all_substr;
        idx_of_all_substr.reserve(str.size() * 2);
        const size_t len = std::strlen(substr);
        size_t idx = str.find(substr);
        if (idx == size_t(-1)) {
            idx_of_all_substr.reserve(0U);
            return idx_of_all_substr;
        }
        while (idx != size_t(-1)) {
            idx_of_all_substr.emplace_back(std::make_pair(idx, idx + (len - 1)));
            idx = str.find(substr, idx + len);
        }
        idx_of_all_substr.shrink_to_fit();
        return idx_of_all_substr;
    }
    template<typename chars>
    void to_upper(std::basic_string<chars>& str) {
        std::transform(str.begin(), str.end(), str.begin(), [](chars c) { return std::toupper(c); });
    }
    template<typename chars>
    void to_lower(std::basic_string<chars>& str) {
        std::transform(str.begin(), str.end(), str.begin(), [](chars c) {return std::tolower(c); });
    }
    template<typename chars, size_t size>
    void to_upper(chars(&arr)[size]) {
        std::transform(std::begin(arr), std::end(arr), std::begin(arr), [](chars c) {return std::toupper(c); });
    }
    template<typename chars, size_t size>
    void to_lower(chars(&arr)[size]) {
        std::transform(std::begin(arr), std::end(arr), std::begin(arr), [](chars c) {return std::tolower(c); });
    }
    template<typename chars>
    std::vector<std::basic_string<chars>> split(const std::basic_string<chars>& str, const chars del) {
        std::vector<std::basic_string<chars>> splitted;
        size_t word = 0;
        splitted.reserve(str.size() * 2);
        for (size_t index = 0; index < str.length(); ++index) {
            word = index;
            while (str[word] != del) {
                if (str[word] == '\0') {
                    splitted.emplace_back(str.substr(index, word - index));
                    return splitted;
                }
                ++word;
            }
            if (index != word) {
                splitted.emplace_back(str.substr(index, word - index));
            }
            index = word;
        }
        splitted.shrink_to_fit();
        return splitted;
    }
    template<typename chars>
    std::vector<std::basic_string_view<chars>> split(const std::basic_string_view<chars> str,
        const chars del) {
        std::vector<std::basic_string_view<chars>> splitted;
        size_t word = 0;
        splitted.reserve(str.size() * 2);
        for (size_t index = 0; index < str.length(); ++index) {
            word = index;
            while (str[word] != del) {
                if (str[word] == '\0') {
                    splitted.emplace_back(str.substr(index, word - index));
                    return splitted;
                }
                ++word;
            }
            if (index != word) {
                splitted.emplace_back(str.substr(index, word - index));
            }
            index = word;
        }
        splitted.shrink_to_fit();
        return splitted;
    }
    template<typename chars>
    void erase_of_all_substrings(std::basic_string<chars>& str, const std::basic_string<chars>& substr) {
        size_t idx = str.find(substr.c_str(), 0U);
        if (idx == size_t(-1)) {
            return;
        }
        while (idx != size_t(-1)) {
            str.erase(idx, substr.size());
            idx = str.find(substr.c_str());
        }
        return;
    }
    inline void erase_of_all_substrings(std::string& str, const char* const substr) {
        size_t idx = str.find(substr, 0U);
        const size_t len = std::strlen(substr);
        if (idx == size_t(-1)) {
            return;
        }
        while (idx != size_t(-1)) {
            str.erase(idx, len);
            idx = str.find(substr);
        }
        return;
    }
}
#endif //STRINGS_UTILITY
