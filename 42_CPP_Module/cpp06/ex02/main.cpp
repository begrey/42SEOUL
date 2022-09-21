#include "Cast.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base *b1 = generate();
    Base *b2 = generate();

    identify(b1);
    identify(*b2);
}