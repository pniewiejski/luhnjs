# luhnjs - C++ project

## Running unit tests

Unit tests for this project are managed by the
[googletest](https://github.com/google/googletest/blob/master/LICENSE) 
library which distributed under the BSD 3-Clause licence.

1. Make sure that in the `lib/` directory the `googletest` dependency is
   present. **It should be downloaded as git submodule.** If you've already
   cloned this repo simply run:

```
$ git submodule update --init --recursive
```

Alternatively, you can download all submodules during clone:

```
$ git clone --recursive git://github.com/pniewiejski/luhnjs.git
```

2. Run the following commands:

```
$ cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
$ make all
```

This should create `build/bin` with executable `luhncpp_test`.

3. Execute `luhncpp_test` to run unit tests.

```
$ cd bin
$ ./luhncpp_test
```

### Code style

Code formatting was done using `clang-format`. I've created a simple bash script
(`format-code.sh`) that runs the `clang-format` command. `clang-format` config
was generated using:

```
$ clang-format -style=google -dump-config > .clang-format
```
