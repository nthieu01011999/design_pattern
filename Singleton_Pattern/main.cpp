#include <iostream>
#include <string>

// Preferences class
class Preferences {
private:
    // Private static variable to hold the single instance of the class
    static Preferences* uniqueInstance;

    // Private constructor to prevent instantiation from outside the class
    Preferences() {
        // Initialize default settings
        playingSurfaceColor = "Green";
        cardBackDesign = "Classic";
    }

    // Private copy constructor and assignment operator to prevent copying
    Preferences(const Preferences&) = delete;
    Preferences& operator=(const Preferences&) = delete;

    // Member variables to store user preferences
    std::string playingSurfaceColor;
    std::string cardBackDesign;

public:
    // Public static method to provide global access to the single instance
    static Preferences* getInstance() {
        if (uniqueInstance == nullptr) {
            uniqueInstance = new Preferences();
        }
        return uniqueInstance;
    }

    // Method to set the playing surface color
    void setPlayingSurfaceColor(const std::string& color) {
        playingSurfaceColor = color;
    }

    // Method to get the playing surface color
    std::string getPlayingSurfaceColor() const {
        return playingSurfaceColor;
    }

    // Method to set the card back design
    void setCardBackDesign(const std::string& design) {
        cardBackDesign = design;
    }

    // Method to get the card back design
    std::string getCardBackDesign() const {
        return cardBackDesign;
    }
};

// Initialize the static member variable
Preferences* Preferences::uniqueInstance = nullptr;

int main() {
    // Access the single instance of Preferences and set some values
    Preferences* prefs = Preferences::getInstance();
    prefs->setPlayingSurfaceColor("Blue");
    prefs->setCardBackDesign("Modern");

    // Access the single instance of Preferences again and get the values
    Preferences* prefs2 = Preferences::getInstance();
    std::cout << "Playing Surface Color: " << prefs2->getPlayingSurfaceColor() << std::endl;
    std::cout << "Card Back Design: " << prefs2->getCardBackDesign() << std::endl;

    return 0;
}
