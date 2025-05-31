# C++ Casts

### What is Casting?

In C++, casting is the process of converting a variable from one type to another. For example, you might want to convert an int to a double or a base class pointer to a derived class pointer. C++ provides several casting operators to do this safely and explicitly. The three we'll cover here are static_cast, reinterpret_cast, and dynamic_cast.

## static_cast

What it does: static_cast is the go-to cast for safe and predictable type conversions. It’s used when you know the conversion is valid at compile time, like converting between related types (e.g., int to double, or a base class pointer to a derived class pointer when you're sure of the object’s type).

Key features:
* Safe for basic type conversions (e.g., int to float).
* Used for upcasting (derived to base) or downcasting (base to derived) when the type is certain.
* Checked at compile time, so it’s fast and efficient.

![cast](https://cdn.discordapp.com/attachments/1102948634493984769/1375543225607258122/-_visual_selection.png?ex=683211f5&is=6830c075&hm=ceb55374df2dab776137775309f46b396e9b3ed876720499b6b176a8a5733bdb&)

Example:
``` c++
int main() {
    // Converting int to double
    int num = 42;
    double decimal = static_cast<double>(num); // Converts 42 to 42.0
    std::cout << "Int to double: " << decimal << std::endl;

    // Upcasting: Derived to Base
    class Base {};
    class Derived : public Base {};
    Derived d;
    Base* basePtr = static_cast<Base*>(&d); // Safe, Derived is a Base
}
```
When to use: Use static_cast for safe, well-defined conversions where you’re confident about the types involved.

## reinterpret_cast

What it does: reinterpret_cast is the most powerful and dangerous cast. It lets you treat one type as another, even if they’re unrelated, by reinterpreting the underlying bits of the data. Think of it as telling the compiler, “Pretend this data is a different type.”

Key features:
* Used for low-level, risky conversions, like turning a pointer of one type into another.
* No type safety checks—use with caution!
* Common in systems programming or when working with raw memory.

![cast](https://cdn.discordapp.com/attachments/1102948634493984769/1375544126463938690/-_visual_selection_1.png?ex=683212cc&is=6830c14c&hm=42e207596ba31d4d8ebc8d8e3c79a5dc3c6d8b9e4d13155afc1831817bd9a75b&)

Example:
``` c++
int main() {
    int num = 65; // ASCII value for 'A'
    char* charPtr = reinterpret_cast<char*>(&num);
    std::cout << "Int as char: " << *charPtr << std::endl; // Prints 'A' on some systems

    // Warning: This is platform-dependent and can be dangerous!
}
```
When to use: Use reinterpret_cast only when you need to work with raw memory or interface with low-level code, and you’re absolutely sure what you’re doing.

## dynamic_cast

What it does: dynamic_cast is used for safe downcasting in polymorphic class hierarchies (classes with virtual functions). It checks at runtime whether a base class pointer or reference actually points to a derived class object. If the cast is invalid, it returns nullptr (for pointers) or throws an exception (for references).

Key features:
* Requires a polymorphic type (at least one virtual function in the class).
* Performs runtime type identification (RTTI) to ensure safety.
* Useful when you’re unsure of the exact type of an object.

![cast](https://cdn.discordapp.com/attachments/1102948634493984769/1375545183629738054/-_visual_selection_2.png?ex=683213c8&is=6830c248&hm=8f872d06c8a98971c4aa26ab803d66c34b7d43e4861bccf0f6c5146d4e0cb029&)

Example:
``` c++
#include <iostream>
class Base {
public:
    virtual void speak() { std::cout << "I am Base!" << std::endl; }
};
class Derived : public Base {
public:
    void speak() { std::cout << "I am Derived!" << std::endl; }
};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    
    if (derivedPtr) {
        derivedPtr->speak(); // Prints "I am Derived!"
    } else {
        std::cout << "Cast failed!" << std::endl;
    }
    delete basePtr;
}
```
When to use: Use dynamic_cast when working with polymorphic classes and you need to safely downcast a base class pointer or reference to a derived class.
