#include <iostream>
#include <string>
using namespace std;
class StringProcessor {
private:
    string* strPtr;
public:
    StringProcessor(const std::string& str) {
        strPtr = new std::string(str);
    }
    ~StringProcessor() {
        delete strPtr;
    }
    int countWords() {
        int count = 0;
        bool inWord = false;
        for (char c : *strPtr) {
            if ((c == ' ' || c == '\n') && inWord) {
                count++;
                inWord = false; 
            }
            else if (c != ' ' && c != '\n' && !inWord) {
                inWord = true;
            }
        }
        if (inWord) {
            count++;
        }

        return count;
    }
};

int main() {
    StringProcessor processor("Hello, this is  sentence.");
    cout << "Total words:"<<processor.countWords()<<endl;
    return 0;
}
