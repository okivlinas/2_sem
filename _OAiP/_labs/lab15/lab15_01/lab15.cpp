#include <iostream>
#include <string>

#define TABLE_SIZE 100

struct Entry {
    int phoneNumber;
    std::string owner;
};

struct HashTable {
    Entry* table[TABLE_SIZE];
};

unsigned int hashFunction(int key) {
    unsigned int hashValue = key % TABLE_SIZE;
    return hashValue;
}

void initializeHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable->table[i] = nullptr;
    }
}

void displayHashTable(const HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hashTable->table[i] != nullptr) {
            std::cout << "Key: " << hashTable->table[i]->phoneNumber << ", Value: " << hashTable->table[i]->owner << std::endl;
        }
    }
    std::cout << std::endl;
}

void insertEntry(HashTable* hashTable, int phoneNumber, const std::string& owner) {
    unsigned int hashValue = hashFunction(phoneNumber);

    while (hashTable->table[hashValue] != nullptr) {
        hashValue = (hashValue + 1) % TABLE_SIZE;
    }

    Entry* newEntry = new Entry;
    newEntry->phoneNumber = phoneNumber;
    newEntry->owner = owner;
    hashTable->table[hashValue] = newEntry;
}

void deleteEntry(HashTable* hashTable, int phoneNumber) {
    unsigned int hashValue = hashFunction(phoneNumber);

    while (hashTable->table[hashValue] != nullptr) {
        if (hashTable->table[hashValue]->phoneNumber == phoneNumber) {
            delete hashTable->table[hashValue];
            hashTable->table[hashValue] = nullptr;
            std::cout << "Entry deleted." << std::endl;
            return;
        }
        hashValue = (hashValue + 1) % TABLE_SIZE;
    }

    std::cout << "Entry not found." << std::endl;
}

void searchEntry(const HashTable* hashTable, int phoneNumber) {
    unsigned int hashValue = hashFunction(phoneNumber);

    while (hashTable->table[hashValue] != nullptr) {
        if (hashTable->table[hashValue]->phoneNumber == phoneNumber) {
            std::cout << "Key: " << hashTable->table[hashValue]->phoneNumber << ", Value: " << hashTable->table[hashValue]->owner << std::endl;
            return;
        }
        hashValue = (hashValue + 1) % TABLE_SIZE;
    }

    std::cout << "Entry not found." << std::endl;
}

int main() {
    HashTable hashTable;
    initializeHashTable(&hashTable);

    int choice;
    int phoneNumber;
    std::string owner;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert an entry" << std::endl;
        std::cout << "2. Delete an entry" << std::endl;
        std::cout << "3. Search for an entry" << std::endl;
        std::cout << "4. Display the hash table" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            if (phoneNumber > 32767) {
                std::cout << "Invalid phone number. Please enter again." << std::endl;
                continue;
            }
            std::cout << "Enter owner: ";
            std::cin.ignore(); // Ignore the newline character
            std::getline(std::cin, owner);
            insertEntry(&hashTable, phoneNumber, owner);
            break;
        case 2:
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            deleteEntry(&hashTable, phoneNumber);
            break;
        case 3:
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            searchEntry(&hashTable, phoneNumber);
            break;
        case 4:
            displayHashTable(&hashTable);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice. Please enter again." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
