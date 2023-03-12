import factory from "./wasm_api.mjs";

factory().then((instance) => {
  arrayOperationsOnC([3, 2, 5]);

  function arrayOperationsOnC(n) {
    const BYTES_PER_INT = 4;

    const arraySize = n.length;
    const arrayPointer = instance._malloc(arraySize * BYTES_PER_INT);
    instance.HEAP32.set(new Int32Array(n), arrayPointer / BYTES_PER_INT);
    const cFunc = instance.cwrap("arraySorter", null, ["number", "number"]);
    const byteAddres = arrayPointer / BYTES_PER_INT;
    // const t1 = performance.now();
    cFunc(arrayPointer, arraySize);
    const res = Array.from(
      instance.HEAP32.subarray(byteAddres, byteAddres + arraySize)
    );
    console.log(res);

    instance._free(arrayPointer);
    // const t2 = performance.now();
    // return t2 - t1;
  }
});
