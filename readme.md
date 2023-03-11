# WASM0

## Overview and goal

This is just a trial to see if we can call a C function from JavaScript of a browser. It seems we can. May aim is to check whether this can be used to make executions faster on browser using WebAssembly (WASM for short).

As we all know C is fast. So let's say I'm sorting an array of integers in JavaScript in browser. If I create a C function for sorting and use it, can it execute faster?

## Instructions

- Followed instructions at [MDN](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm) and https://emscripten.org/docs/getting_started/downloads.html Basically I used emscripten to generate WASM code from C code and then open it in the browser. You need a [basic HTTP server](https://github.com/ritwickdey/vscode-live-server-plus-plus). Opening raw HTML in browser won't work.

- To conveniently access emsdk tools from the command line run `source ./emsdk_env.sh` from terminal and use the same terminal window to compile C code. This way C header files will be available

- To not duplicate file names, I created another `shell-minimal2.html` file different from [MDN documentation](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm#calling_a_custom_function_defined_in_c).

- To compile WebAssembly `emcc -o hello3.html hello3.c --shell-file html_template/shell_minimal2.html -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']"`

- To complie WebAssembly `emcc -o hello5.html fib2.c --shell-file html_template/shell_minimal2.html -sEXPORTED_FUNCTIONS=_fib -sEXPORTED_RUNTIME_METHODS=cwrap`

- It seems with some optimization flags during compilation C can execute faster than JS `emcc -o hello5.html fib2.c --shell-file html_template/shell_minimal2.html -sEXPORTED_FUNCTIONS=_fib -sEXPORTED_RUNTIME_METHODS=cwrap -O2`

- To call `Module._malloc` from JS `_malloc` should be exported inside flag `sEXPORTED_FUNCTIONS` like `emcc -o hello6.html fib3.c --shell-file html_template/simple_compare.html -sEXPORTED_FUNCTIONS=_fib,_malloc -sEXPORTED_RUNTIME_METHODS=cwrap -O2`

- To call `Module._malloc` and `Module._free` from JS `_malloc` and `_free` should be exported inside flag `sEXPORTED_FUNCTIONS` like `emcc -o hello7.html arraySorter.c --shell-file html_template/simple_compare_array.html -sEXPORTED_FUNCTIONS=_arraySorter,_malloc,_free -sEXPORTED_RUNTIME_METHODS=cwrap -O2`
