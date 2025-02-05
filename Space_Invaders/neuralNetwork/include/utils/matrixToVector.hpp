#ifndef _MATRIXTOVECTOR_HPP_
#define _MATRIXTOVECTOR_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

namespace utils {
    class MatrixToVector {
        public:
            MatrixToVector(Matrix *a);
            std::vector<double> execute();
        
        private:
            Matrix *a;
    };
}

#endif