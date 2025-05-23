# Polymorphism, Abstract Classes, and Interfaces
## 1. Subtype Polymorphism

Subtype polymorphism is a mechanism in OOP where a reference variable of a supertype (e.g., a parent class or interface) can refer to an object of any of its subtypes (e.g., child classes or implementing classes). This allows code to work with objects at a general level while invoking specific behavior defined in the subtype, typically through method overriding or implementation.

How It Works:
![poly](https://media.discordapp.net/attachments/1102948634493984769/1363202050825126039/Polymorphism_Abstract_Classes_and_Interfaces_-_visual_selection.png?ex=6831ff57&is=6830add7&hm=06f597feff7fccba24306f3033f7ed5e34372378ad265b5bdaaf69fd8cf69f29&=&format=webp&quality=lossless&width=1416&height=912)

* A supertype defines a contract (methods, properties, etc.).
* Subtypes inherit or implement this contract, potentially overriding methods to provide specific behavior.
* At runtime, the actual type of the object determines which method is called (dynamic dispatch).

#### Key Characteristics:

* Enables flexibility and extensibility in code.
* Relies on inheritance (for classes) or implementation (for interfaces).
* Often achieved through method overriding (redefining a method in a subclass) or method implementation (defining an interface’s method in a class).

## 2. Abstract Classes

An abstract class is a class that cannot be instantiated directly and is meant to serve as a blueprint for other classes. It may contain both concrete methods (with implementations) and abstract methods (without implementations, declared with the abstract keyword). Subclasses must extend the abstract class and provide implementations for its abstract methods.

![poly](https://media.discordapp.net/attachments/1102948634493984769/1363202050275545230/Polymorphism_Abstract_Classes_and_Interfaces_-_visual_selection_1.png?ex=6831ff57&is=6830add7&hm=7ae4be18c75ed636c829c68d4f782438a16ecfe866126f4f5e15b46d56cefba4&=&format=webp&quality=lossless&width=1704&height=794)

How It Works:
* It has at least a pure virtual function.
* Can include:
  * Abstract methods: Declared without a body; subclasses must implement them.
  * Concrete methods: Fully implemented methods that subclasses inherit.
  * Fields, constructors, etc.: Like regular classes.
* Subclasses that don’t implement all abstract methods must also be declared abstract.

#### Key Characteristics:

* Provides partial implementation, unlike interfaces.
* Supports single inheritance (a class can extend only one abstract class).
* Useful for sharing code among closely related classes.

## 3. Interfaces
An interface in C++ is typically an abstract base class where:

* All member functions are pure virtual (declared with = 0), meaning they have no implementation and must be overridden by derived classes.
* The class has no data members (or minimal state), focusing purely on behavior.
* The class cannot be instantiated directly due to its abstract nature.
This mimics the role of interfaces in other languages: defining a contract that derived classes must implement, enabling polymorphism and loose coupling.

![poly](https://media.discordapp.net/attachments/1102948634493984769/1363207322108956763/Polymorphism_Abstract_Classes_and_Interfaces_-_visual_selection_3.png?ex=68320440&is=6830b2c0&hm=e6738c694332f6b3a9318fe07cae44025c9c1bb5abfbc4edd3d46a045f88e2d6&=&format=webp&quality=lossless&width=1632&height=1164)

#### How to Implement an Interface in C++
To create an interface:

1. Define a class with pure virtual functions (e.g., virtual void function() = 0;).
2. Optionally, make the destructor virtual (or pure virtual) to ensure proper cleanup in polymorphic hierarchies.
3. Avoid data members to keep the interface stateless, focusing on behavior.
4. Derived classes inherit from the interface and provide implementations for all pure virtual functions.

#### Why We Need Interfaces in C++

1. Define Contracts: Specify methods that derived classes must implement, ensuring consistent behavior (e.g., virtual void fly() const = 0;).
2. Enable Polymorphism: Allow code to work with base class pointers/references, invoking derived class behavior (e.g., Flyable* flyer = new Duck(); flyer->fly();).
3. Support Loose Coupling: Decouple code from specific implementations, making systems modular and extensible (e.g., plugin systems).
4. Facilitate Multiple Inheritance: Allow classes to implement multiple interfaces safely (e.g., class Duck : public Flyable, public Swimmable).
5. Enforce Design Patterns: Support patterns like Strategy or Factory by defining abstract behaviors.
