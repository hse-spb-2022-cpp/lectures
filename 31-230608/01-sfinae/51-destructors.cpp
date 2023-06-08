// Destructors cannot be SFINAEd out. C++20: concepts to the rescue!
// Having a destructor makes the difference between TriviallyDestructible types and others.

~Foo() noexcept(?????) {  // No SFINAE even within noexcept: https://stackoverflow.com/a/33667546/767632
}
