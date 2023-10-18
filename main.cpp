#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

class MyBigInteger {
private:
    std::vector<uint32_t> digits;

public:
    MyBigInteger() {
        digits.push_back(0);
    }

    MyBigInteger(const std::string& hexString) {
        this->setHex(hexString);
    }

    std::vector<uint32_t> getDigits() {
        return digits;
    }

    void setDigits(std::vector<uint32_t> digits) {
        this->digits = digits;
    }

    std::string getHex() const {
        std::string hexString;
        for (int i = digits.size() - 1; i >= 0; i--) {
           uint32_t digit = digits[i];
           if (digit >= 10 && digit <= 15) {
               hexString.push_back(char(digit + 87));
           }
           else if (digit >= 0 && digit < 10) {
               hexString.append(std::to_string(digit));
           }

        }
        return hexString;
    }

    void setHex(const std::string& hexString) {
        digits.clear();

        int len = hexString.size();

        int digit = 0;

        for (int i = len - 1; i >= 0; i--) {
            if (hexString[i] >= '0' && hexString[i] <= '9') {
                digit = int(hexString[i]) - 48;
            }
            else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
                digit = int(hexString[i]) - 55;
            }
            else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
                digit = int(hexString[i]) - 87;
            }
            digits.push_back(digit);
        }
    }
};

int main() {
    std::string hexValue = "51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4";

    MyBigInteger a;
    a.setHex(hexValue);
    std::cout << a.getHex() << std::endl;



    return 0;
}