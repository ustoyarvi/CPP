#include <iostream>
#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 42;
    original.name = "School";

    uintptr_t raw = Serializer::serialize(&original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &original << std::endl;
    std::cout << "Restored pointer: " << restored << std::endl;

    std::cout << "Original data: [" << original.id << ", " << original.name << "]" << std::endl;
    std::cout << "Restored data: [" << restored->id << ", " << restored->name << "]" << std::endl;

    return 0;
}
