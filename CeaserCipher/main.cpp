#include <iostream>
#include <string>

const std::string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string userMessage;
std::string userEncryptedMessage;
std::string userDecryptedMessage;
int shift;

void createMessage() {

    std::cout << "Type message:\n";
    std::cin >> userMessage;
    std::cout << userMessage <<"\n";

}

void encryptMessage() {
    std::cout << "Type shift:\n";
    std::cin >> shift;
    userEncryptedMessage = userMessage;

    for (char& c : userEncryptedMessage) {
            if (std::isalpha(c)) {

                bool isUpper = std::isupper(c);

                char upperC = std::toupper(c);

                size_t position = Alphabet.find(upperC);

                position = (position + shift) % Alphabet.length();

                c = isUpper ? Alphabet[position] : std::tolower(Alphabet[position]);
            }
        }
    std::cout << "Encrypted message: " << userEncryptedMessage << "\n";
}



void decryptMessage() {
    if (userEncryptedMessage.empty()) {
        std::cout << "Create and Encrypt message\n";
    } else {
        userDecryptedMessage = userEncryptedMessage;
        for (char& c : userDecryptedMessage) {
            if (std::isalpha(c)) {
                bool isUpper = std::isupper(c);
                char upperC = std::toupper(c);
                size_t position = Alphabet.find(upperC);
                
                // Adjusting the shift direction for decryption
                position = (position - shift + Alphabet.length()) % Alphabet.length();
                
                c = isUpper ? Alphabet[position] : std::tolower(Alphabet[position]);
            }
        }
        std::cout << "Decrypted message: " << userDecryptedMessage << "\n";
    }
}


void bruteforceEncryptedMessage() {
    
    for (int i = 0; i < Alphabet.length(); i++){
            std::string bfUserEncryptedMessage = userEncryptedMessage;
            
            for (char& c : bfUserEncryptedMessage) {
                if (std::isalpha(c)) {

                    bool isUpper = std::isupper(c);

                    char upperC = std::toupper(c);

                    size_t position = Alphabet.find(upperC);

                    position = (position - i + Alphabet.length()) % Alphabet.length();
                    
                    c = isUpper ? Alphabet[position] : std::tolower(Alphabet[position]);

                }
            }
            std::cout << i + 1 << ". " << bfUserEncryptedMessage << "\n";
        }    
}

int main() {

    std::cout << "Ceaser Cipher\n";

    bool exitMenu = false;
    while (!exitMenu) {
        std::cout << "Menu:\n";
        std::cout << "1. Create message\n";
        std::cout << "2. Encrypt message\n";
        std::cout << "3. Decrypt message\n";
        std::cout << "4. Bruteforce encrypted message\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                createMessage();
                break;
            case 2:
                encryptMessage();
                break;
            case 3:
                decryptMessage();
                break;
            case 4:
                bruteforceEncryptedMessage();
            case 5:
                exitMenu = true;
                break;
        }
    }

    return 0;
}