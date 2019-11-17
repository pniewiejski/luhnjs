## Running tests
1. Make sure that in `lib` directory the `googletest` is present. 
**It should be downloaded as git submodule.**
2. Run the following commands:
```
$ cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
$ make all
``` 
This should create `build/bin` with executable `luhncpp_test`. 
3. Execute `luhncpp_test` it to run unit tests.

## Code style
Code formatting using `clang-format`: 
```
clang-format *.cpp -i
```
`clang-format` config was generated using: 
```
clang-format -style=google -dump-config > .clang-format
```