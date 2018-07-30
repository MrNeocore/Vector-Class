# Vector class C++
Implementation of common vector operations in C++

## Context :
- Original developement date : 01/2018
- Haven't done much C++ in recent months
- Developped as part of a Computer Games Programming coursework at HWU.
  - Very limited value as part of the coursework : 1 points out of 20.

## Features 
- Use of templating and pointers 
- Support for vector / vector and vector / scalar operations
- Cross and dot product

## Self analysis as of 30/07/2018 :
 - Some objects could be passed as const.
 - Missing C++11 move operator.
 - Missing 7D cross product
 - No comments
 - Ok error handling
 
## Overall : 
- Stability    : OK
- Readability  : OK but no comments
- Code quality : MOK, see above.
- Performance  : OK, obviously slower than std::vector implementation. 
  - Could use OpenMP or AVX instructions for parallel computation.
