                            Type Catsing in c++
-) what is type casting:
    converting an expression of a given type into anther type is knwon as type-casting;
-)implicit conversion:
    do not require any operator. they are automatically performed when a value is coped to a compatible type;
    Example int (a -> short b = a); float (a -> int b = a)
-} explicit conversion:
    1-) functional and c-like casting:
    examples:
        short k = 1;
        int l;
        l = (int) k; c-like cast notation
        l = (k); functional notation
    2-) static_cast
        it is a compile time cast and same as implicit conversions unlike c-style it control conversion between pointers.
        conversions between pointers to related classes. from a base class to its derived. and it's the other way around.
        performs no run-time checks.
        use static_cast<>() insted of c-style cats,it's more clear and readable and usualy safe.
            Examples:
                float f = 5.5;   ->  int i = static_cast<int>(f);
                Animal* ptr1 = new Cat()   ->  Cat *ptr = static_cast<Cat*>(ptr1);
    -) static_pointer_cast shared_ptr
        Example
            shared_ptr<Animal> ptr = make_shared<Cat>();
            shared_ptr<Cat> ptr_cat = static_pointer_cast<Cat>(ptr);
    3-) dynamic_cast
        its run-time cast it useful especially when combined with polymorphic classes.
        when a class is polymorphic, dynamic_cast perfprms a special checkimg during runtime to ensure that the expression yields a valid complete object of the requested class: if it's valid, returns a pointer; otherwise its returns null.
        less perfomance than static_cast