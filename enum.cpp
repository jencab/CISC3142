#include <iostream>
using namespace std; 

//enum-key  attr(optional)  name (optional)  base(optional)  { enum-list(optional) }
/*  key: enum / enum class / enum struct
        enum is UNSCOPED   enumclass/struct is SCOPED
        class&struct are equivalent
    base: fixed underlying type of the enum
    list: identifer; or identifier = value;
*/

// 1st enum == 0 if uninitialized 
// following uninitialized enum == prevEnumValue + 1

/* unscoped ennumerations
    allow for conversions from int to long
    if type not specified default is int
    casting needed for int & float conversion
*/
    enum Foo {
        a,      // 0
        b,      // 1
        c=10,
        d,      // 11
        e=1,
        f,      // 2
        g = f + c,       // 12
        jj = sizeof(b)   // 4 b/c int == 4 bytes
    };  int n = b; // n == 1

/* scoped enumerations
    cannot convert to integral type (int/long)
    static_cast to get num value of enum
    using list initialization enum can convert to int w/rules
*/
    enum class altitude: char {     // type is char
        //may be altitude::high or altitude::low
        high = 'h',
        low = 'l', 
    };

    enum class Color {      // type not specified
        red,        // 0
        green = 20, 
        blue,        // 21
        orange = sizeof(red)    // 1 bc char==1
    }; Color r = Color::blue;   // r = 21;
    int main() {
        // int n = r; // error: no implicit conversion from scoped enum to int
        int n = static_cast <int> (r);    //OK, n = 21; 
    };
/* using-enum
    adds members of the enumration to the scope
    enum members must have unique names
*/
    enum class fruit {orange, apple};
    enum class hues { red, orange};
    struct S {
        //using enum fruit;  // OK: introduces orange & apple in S
    }; 
/*  void f(){
        S s;
        s.orange;  -- OK: names fruit::orange
        S::orange; -- OK: names fruit::orange
    } 
    void f(){
        using enum fruit;       -- OK
        using enum color;       -- error orange conflicts
    }
*/
