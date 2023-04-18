#include <iostream>
#include <chrono>
#include <thread>

std::string getOsName() {
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}

int main() {
    const char *clear_cmd{"clear"};
    if ("Windows 32-bit" == getOsName() || "Windows 64-bit" == getOsName())
        clear_cmd = "cls";
    system(clear_cmd);
    std::cout << "Assurez vous de mettre le terminal en fullscreen! [ENTREE] pour continuer...";
    std::cin.get();
    system(clear_cmd);

    size_t millis{100};
    size_t max_spaces{10};
    std::string base_str{};

    while (true) {
        std::cout << "Combiens de milliseconds (recommendation=100): ";
        if (std::cin >> millis) {
            std::cout << std::endl;
            break;
        } else {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "no." << std::endl;
        }

    }
    system(clear_cmd);
    while (true) {
        std::cout << "Combiens d'espaces max (recommendation=20): ";
        if (std::cin >> max_spaces) {
            std::cout << std::endl;
            break;
        } else {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "no." << std::endl;
        }
    }

    while (true) {
        system(clear_cmd);
        std::cout << "Entrez votre nom en MAJ separe d'un espace: ";
        if (std::cin >> base_str) {
            std::cout << std::endl;
            break;
        } else {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "no." << std::endl;
        }
    }


    system(clear_cmd);
    while (true) {
        for (size_t i{0}; i < max_spaces; i++) {
            std::string show_str{};
            for (char ii: base_str) {
                show_str += ii + std::string(i, ' ');
            }
            std::cout << "\t" << show_str << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds((int) millis / 2));
        }
        for (size_t i{max_spaces}; i > 0; i--) {
            std::string show_str{};
            for (char ii: base_str) {
                show_str += ii + std::string(i, ' ');
            }
            std::cout << "\t" << show_str << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds((int) millis / 2));
        }
    }


}
