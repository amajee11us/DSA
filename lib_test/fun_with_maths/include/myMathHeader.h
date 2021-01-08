#include <iostream>
#include <math.h>
#include <string>

namespace myName{
    class Mathlib{
        public:
            int do_sum(int a, int b);

            int do_subtract(int a, int b);

            int do_multiply(int a, int b);

            int do_divide(int a, int b);

            int power(int input, int p);

            int get_input();

    };
}