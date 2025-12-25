#include <bitset>
#include <codecvt>
#include <cstdint>
#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include <vector>
#include "thirdparty_UTF8-CPP/utf8.h"
#include "thirdparty_UTF8-CPP/utf8/checked.h"

using namespace std;

void prefaceText() {
    cout << "=============================================\n";
    cout << "        Text Encoding Conversion Tool\n";
    cout << "=============================================\n\n";

    cout << "The program has started successfully.\n";
    cout << "You will now go through a few simple menus\n";
    cout << "to choose your language, encoding standard,\n";
    cout << "Unicode format, and the type of output you want.\n\n";

    cout << "Please follow the instructions and select the\n";
    cout << "appropriate options by entering the number\n";
    cout << "shown in the menu.\n\n";

    cout << "Let's begin!\n\n";
}

int languageChoice() {
    int choice = 0;

    cout << "Select Language:\n";
    cout << "1. English\n";
    cout << "2. Persian\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Invalid choice. Select again.\n";
        return languageChoice();
    }

    return choice;
}

int standardChoice(int language) {
    int choice = 0;

    switch (language) {
        case 1:
            cout << "\nSelect Standard:\n";
            cout << "1. ASCII\n";
            cout << "2. Extended ASCII\n";
            cout << "3. Unicode\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice < 1 || choice > 3) {
                cout << "Invalid choice. Select again.\n";
                return standardChoice(language);
            }
            break;

        case 2:
            cout << "\nSelect Standard:\n";
            cout << "1. Unicode\n";
            cout << "Enter choice: ";
            cin >> choice;

            // Check if the input is valid
            if (choice != 1) {
                cout << "Invalid choice. Select again.\n";
                return standardChoice(language);
            }
            break;
    }

    return choice;
}

int utfEncoding(int *opts) {
    int choice = 0;

    if ((opts[0] == 1 && opts[1] == 3) || (opts[0] == 2 && opts[1] == 1)) {
        cout << "\nSelect Unicode UTF encoding:\n";
        cout << "1. UTF-8\n";
        cout << "2. UTF-16\n";
        cout << "3. UTF-32\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Select again.\n";
            return utfEncoding(opts);
        }

        return choice;
    }

    return 0;
}

int outputFormatChoice() {
    int choice = 0;

    cout << "\nSelect output format:\n";
    cout << "1. Decimal\n"; // Decimal output
    cout << "2. Binary\n"; // Binary output
    cout << "3. Hexadecimal\n"; // Hex output
    cout << "Enter choice: ";
    cin >> choice;

    // Validate user input
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Select again.\n";
        return outputFormatChoice(); // Repeat until valid
    }

    return choice;
}

int selectOption() {
    int choice = 0;

    cout << "\nSelect Option:\n";
    cout << "1. Convert custom text to binary\n";
    cout << "2. Show all characters and codes of the selected language\n";
    cout << "3. Show a predefined sample text and its binary codes\n";
    cout << "Enter choice: ";
    cin >> choice;

    // Validate the option
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Select again.\n";
        return selectOption();
    }

    return choice;
}

void printUserChoice(int *opts) {
    cout << "\nYou have selected:\n";
    cout << "\tLanguage:\t";
    if (opts[0] == 1) {
        cout << "English" << "\n";
    } else {
        cout << "Persian" << "\n";
    }

    cout << "\tStandard:\t";
    if (opts[0] == 1) {
        switch (opts[1]) {
            case 1:
                cout << "ASCII" << "\n";
                break;

            case 2:
                cout << "Extended ASCII" << "\n";
                break;

            case 3:
                cout << "Unicode" << "\n";
                break;
        }
    } else {
        cout << "Unicode" << "\n";

        cout << "\tEncoding:\t";
        if (opts[2] == 1) {
            cout << "UTF-8" << "\n";
        } else if (opts[2] == 2) {
            cout << "UTF-16" << "\n";
        } else if (opts[2] == 3) {
            cout << "UTF-32" << "\n";
        }
    }

    cout << "\tOutput Format:\t";
    if (opts[3] == 1) {
        cout << "Decimal" << "\n";
    } else if (opts[3] == 2) {
        cout << "Binary" << "\n";
    } else if (opts[3] == 3) {
        cout << "Hexadecimal" << "\n";
    }

    cout << "\tOption:\t";
    if (opts[4] == 1) {
        cout << "Custom text" << "\n";
    } else if (opts[4] == 2) {
        cout << "All characters" << "\n";
    } else if (opts[4] == 3) {
        cout << "Sample text" << "\n";
    }
}

string getText(int *opts) {
    string targetText = "";

    if (opts[4] == 1) {
        cout << "Enter your desired text: " << "\n";
        cin.ignore();
        getline(cin, targetText);
    } else if (opts[4] == 2) {
        if (opts[0] == 1) {
            targetText = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            targetText += "abcdefghijklmnopqrstuvwxyz";

        } else if (opts[0] == 2) {
            targetText = "آابپتثجچحخدذرزژسشصضطظعغفقکگلمنوهی";
        }
    } else if (opts[4] == 3) {
        if (opts[0] == 1) {
            targetText = "Hello World!";
        } else if (opts[0] == 2) {
            targetText = "سلام دنیا!";
        }
    }

    return targetText;
}

string convertDecimal(int number, int format) {
    switch (format) {
        case 2: {
            // Convert to binary
            bitset<32> binary(number);
            return binary.to_string();
        }

        case 16: {
            // Convert to hexadecimal
            stringstream ss;
            ss << hex << uppercase << number;
            return ss.str();
        }

        default:
            return "Invalid format";
    }
}

std::vector<unsigned char> codepoint_to_utf8(uint32_t cp) {
    std::vector<unsigned char> bytes;

    if (cp <= 0x7F) {
        bytes.push_back(static_cast<unsigned char>(cp));
    }
    else if (cp <= 0x7FF) {
        bytes.push_back(static_cast<unsigned char>(0xC0 | ((cp >> 6) & 0x1F)));
        bytes.push_back(static_cast<unsigned char>(0x80 | (cp & 0x3F)));
    }
    else if (cp <= 0xFFFF) {
        bytes.push_back(static_cast<unsigned char>(0xE0 | ((cp >> 12) & 0x0F)));
        bytes.push_back(static_cast<unsigned char>(0x80 | ((cp >> 6) & 0x3F)));
        bytes.push_back(static_cast<unsigned char>(0x80 | (cp & 0x3F)));
    }
    else if (cp <= 0x10FFFF) {
        bytes.push_back(static_cast<unsigned char>(0xF0 | ((cp >> 18) & 0x07)));
        bytes.push_back(static_cast<unsigned char>(0x80 | ((cp >> 12) & 0x3F)));
        bytes.push_back(static_cast<unsigned char>(0x80 | ((cp >> 6) & 0x3F)));
        bytes.push_back(static_cast<unsigned char>(0x80 | (cp & 0x3F)));
    }
    else {
        // کدپوینت نامعتبر
        throw std::runtime_error("Invalid Unicode codepoint");
    }

    return bytes;
}

std::vector<uint16_t> codepoint_to_utf16(uint32_t cp) {
    std::vector<uint16_t> utf16;

    if (cp <= 0xFFFF) {
        if (cp >= 0xD800 && cp <= 0xDFFF) {
            throw std::runtime_error("Invalid codepoint: surrogate area");
        }
        utf16.push_back(static_cast<uint16_t>(cp));
    } else if (cp <= 0x10FFFF) {
        cp -= 0x10000;
        uint16_t high = 0xD800 + ((cp >> 10) & 0x3FF);
        uint16_t low  = 0xDC00 + (cp & 0x3FF);
        utf16.push_back(high);
        utf16.push_back(low);
    } else {
        throw std::runtime_error("Invalid Unicode codepoint");
    }

    return utf16;
}

std::vector<uint32_t> codepoint_to_utf32(uint32_t cp) {
    if (cp > 0x10FFFF)
        throw std::runtime_error("Invalid Unicode codepoint");
    return {cp};
}

void unicodeConverter(int *opts, const string &text) {
    int lan = opts[0]; // 1 English, 2 Persian
    int std = opts[1]; // ASCII/Extended/Unicode
    int utf = opts[2];
    int fom = opts[3];
    int opt = opts[4];

    cout << "\n=== Character Codes ===\n";

    // ---------- English Mode (ASCII / Extended ASCII) ----------
    if (lan == 1 && std != 3) {
        for (int i = 0; i < text.size();) {
            unsigned char c = text[i];
            int code = (int) c;
            string output = to_string(code);

            if (fom == 2) {
                output = convertDecimal(code, 2);
            } else if (fom == 3) {
                output = convertDecimal(code, 16);
            }

            if (opt == 2) {
                cout << text[i] << "  ->  " << output << "\n";
            } else {
                cout << output << " ";
            }

            i++;
        }
    }

    // ---------- Unicode Mode (UTF-8 / UTF-16 / UTF-32) ----------
    else {
        auto it = text.begin();
        while (it != text.end()) {
            if (*it == ' ') {
                ++it;
                continue;
            }

            uint32_t cp = utf8::unchecked::next(it);
            std::string s;
            utf8::append(cp, std::back_inserter(s));

            if (opt == 2) {
                cout << s << "  ->  ";
            }

            if (utf == 1) {
                auto utf8_bytes = codepoint_to_utf8(cp);
                for (auto b : utf8_bytes) {
                    if (fom == 1) {
                        std::cout << std::dec << static_cast<int>(b) << ",";
                    } else if (fom == 2) {
                        std::cout << convertDecimal(static_cast<int>(b), 2) << ",";
                    }else if (fom == 3) {
                        std::cout << std::hex << std::uppercase << static_cast<int>(b) << ",";
                    }
                }
            }

            if (utf == 2) {
                auto utf16 = codepoint_to_utf16(cp);
                for (auto u : utf16) {
                    if (fom == 1) {
                        std::cout << std::dec << u << ",";
                    } else if (fom == 2) {
                        std::cout << convertDecimal(u, 2) << ",";
                    }else if (fom == 3) {
                        std::cout << std::hex << std::uppercase << u << ",";
                    }
                }
            }

            if (utf == 3) {
                auto utf32 = codepoint_to_utf32(cp);
                for (auto u : utf32) {
                    if (fom == 1) {
                        std::cout << std::dec << u << ",";
                    } else if (fom == 2) {
                        std::cout << convertDecimal(u, 2) << ",";
                    }else if (fom == 3) {
                        std::cout << std::hex << std::uppercase << u << ",";
                    }
                }
            }

            if (opt == 2) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
    }
}

int main() {
    // ===============================================================
    // Main Program Entry Point
    // This program allows the user to convert text characters into
    // different encoding formats (ASCII, Unicode, etc.) and display
    // them in various numeric formats (Decimal, Binary, Hexadecimal).
    // The user can select language, encoding, output format, and text.
    // ===============================================================

    // Display initial program introduction or instructions
    prefaceText();

    // Allocate an array to store user-selected options:
    // opts[0] = Language (1 = English, 2 = Persian)
    // opts[1] = Standard (English: ASCII/Extended ASCII/Unicode, Persian: Unicode)
    // opts[2] = UTF Encoding (1 = UTF-8, 2 = UTF-16, 3 = UTF-32)
    // opts[3] = Output Format (1 = Decimal, 2 = Binary, 3 = Hexadecimal)
    // opts[4] = Program Mode (1 = Custom Text, 2 = All Characters, 3 = Sample Text)
    int *opts = new int[5];

    // Variable to control program loop and menu navigation
    int reRun = 0;

    // String to hold the target text that will be converted
    string targetText;

    // Main program loop (continues until user chooses to exit)
    while (true) {
        switch (reRun) {

            // ========================================================
            // Full Reselect Mode
            // Runs when the user starts the program or chooses to
            // reselect all options. Handles initial setup and text selection.
            // ========================================================
            case 0:
            case 2:
                // Display restarting message if user chose to rerun and reselect
                if (reRun == 2)
                    cout << "\n\nRestarting...\n\n";

                // Prompt user for language selection
                opts[0] = languageChoice();

                // Prompt user for standard selection based on chosen language
                opts[1] = standardChoice(opts[0]);

                // Prompt user for UTF encoding type
                opts[2] = utfEncoding(opts);

                // Prompt user for output format (Decimal, Binary, Hex)
                opts[3] = outputFormatChoice();

                // Prompt user for program mode (text selection)
                opts[4] = selectOption();

                // Display the current user choices for confirmation
                printUserChoice(opts);

                // Retrieve or generate the target text based on options
                targetText = getText(opts);

                // Perform the conversion and display results according to options
                unicodeConverter(opts, targetText);

                // Prompt user for next action (same options, reselect, or exit)
                cout << "\n\n\n1) Run again with the same options."
                     << "\n2) Rerun and reselect."
                     << "\n3) Exit the program."
                     << "\nEnter choice: ";
                cin >> reRun;
                break;

            // ========================================================
            // Same Options Mode
            // Runs when the user wants to only change the text or list
            // while keeping other options (language, encoding, format) the same.
            // ========================================================
            case 1:
                // Only reselect the program mode (text selection)
                opts[4] = selectOption();

                // Display current options (mostly unchanged except for text)
                printUserChoice(opts);

                // Retrieve or generate the new target text based on selected mode
                targetText = getText(opts);

                // Perform the conversion and display results
                unicodeConverter(opts, targetText);

                // Prompt user for next action (same options, reselect, or exit)
                cout << "\n\n\n1) Run again with the same options."
                     << "\n2) Rerun and reselect."
                     << "\n3) Exit the program."
                     << "\nEnter choice: ";
                cin >> reRun;
                break;

            // ========================================================
            // Exit Case
            // Handles program termination, freeing memory, and cleanup
            // ========================================================
            case 3:
                cout << "\n\nExiting program...\n";

                // Free dynamically allocated memory for options array
                delete[] opts;

                // Exit the program successfully
                return 0;

            // ========================================================
            // Invalid Input Handling
            // Default case triggers when user enters an invalid option
            // ========================================================
            default:
                cout << "\nInvalid choice! Returning to menu...\n";

                // Reset loop to full reselect mode
                reRun = 0;
                break;
        }
    }
}
