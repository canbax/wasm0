# WASM0

## Overview and goal

This is just a trial to see if we can call a C function from JavaScript of a browser. It seems we can. May aim is to check whether this can be used to make executions faster on browser using WebAssembly (WASM for short).

As we all know C is fast. So let's say I'm sorting an array of integers in JavaScript in browser. If I create a C function for sorting and use it, can it execute faster?

## Introduction slides
https://docs.google.com/presentation/u/1/d/19jMpR6ZOJ7TQfjJdOHFjeeeZKxQzyGhN9YFLuEfP8KI/

## Instructions

- Followed instructions at [MDN](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm) and https://emscripten.org/docs/getting_started/downloads.html Basically I used emscripten to generate WASM code from C code and then open it in the browser. You need a [basic HTTP server](https://github.com/ritwickdey/vscode-live-server-plus-plus). Opening raw HTML in browser won't work.

- To conveniently access emsdk tools from the command line run `source ./emsdk_env.sh` from terminal and use the same terminal window to compile C code. This way C header files will be available

- Compile WebAssembly that prints 'hello world' to the developer console `emcc hello.c -o hello.html`

- Compile WebAssembly and use an HTML template `emcc -o hello2.html hello2.c -O3 --shell-file html_template/shell_minimal.html`

- Compile WebAssembly call a C function `emcc -o hello3.html hello3.c --shell-file html_template/shell_minimal2.html -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']"`

- Compile WebAssembly without optiimizations, call a very badly implemented fibonacci function in both C and JS `emcc -o hello4.html fib.c --shell-file html_template/simple_compare.html -sEXPORTED_FUNCTIONS=_fib -sEXPORTED_RUNTIME_METHODS=cwrap` => JS executes faster.

- Compile WebAssembly with O2 optiimizations, call a very badly implemented fibonacci function in both C and JS `emcc -o hello5.html fib.c --shell-file html_template/simple_compare.html -sEXPORTED_FUNCTIONS=_fib -sEXPORTED_RUNTIME_METHODS=cwrap -O2`=> C executes faster!

- Compile WebAssembly with O3 optiimizations, call a very badly implemented fibonacci function in both C and JS `emcc -o hello6.html fib.c --shell-file html_template/simple_compare.html -sEXPORTED_FUNCTIONS=_fib -sEXPORTED_RUNTIME_METHODS=cwrap -O3` => C executes faster!

- To call `Module._malloc` and `Module._free` from JS `_malloc` and `_free` should be exported inside flag `sEXPORTED_FUNCTIONS` like `emcc -o findIndex.html findIndex.c --shell-file html_template/simple_compare_findIndex.html -sEXPORTED_FUNCTIONS=_findIndex,_malloc,_free -sEXPORTED_RUNTIME_METHODS=cwrap -O2` => JS executes faster.

- To call `Module._malloc` and `Module._free` from JS `_malloc` and `_free` should be exported inside flag `sEXPORTED_FUNCTIONS` like `emcc -o mathMax.html mathMax.c --shell-file html_template/simple_compare_math_max.html -sEXPORTED_FUNCTIONS=_mathMax,_malloc,_free -sEXPORTED_RUNTIME_METHODS=cwrap -O2` => JS executes faster.

- To call `Module._malloc` and `Module._free` from JS `_malloc` and `_free` should be exported inside flag `sEXPORTED_FUNCTIONS` like `emcc -o qsort.html arraySorter.c --shell-file html_template/simple_compare_array.html -sEXPORTED_FUNCTIONS=_arraySorter,_malloc,_free -sEXPORTED_RUNTIME_METHODS=cwrap -O2` => JS executes faster.

- To call `Module._malloc` and `Module._free` from JS `_malloc` and `_free` should be exported inside flag `sEXPORTED_FUNCTIONS` like `emcc -o faster_sorter.html arraySorter2.c --shell-file html_template/simple_compare_array_sort.html -sEXPORTED_FUNCTIONS=_arraySorter,_malloc,_free -sEXPORTED_RUNTIME_METHODS=cwrap -O2` => C executes faster!

- To export as an npm module, `emcc arraySorter2.c -o wasm_api.js -sMODULARIZE -sEXPORTED_FUNCTIONS=_arraySorter,_malloc,_free -sEXPORTED_RUNTIME_METHODS=cwrap -O2`
