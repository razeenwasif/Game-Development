#ifndef _MATRIXMULTIPLY_HPP_
#define _MATRIXMULTIPLY_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

namespace utils {
    class matrixMultiply {
        public:
            matrixMultiply(Matrix *a, Matrix *b);
            Matrix *execute();
        
        private:
            Matrix *a;
            Matrix *b;
            Matrix *c;
    };
}

#endif