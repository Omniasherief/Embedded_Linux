# concept of PLT (Procedure Linkage Table) and GOT (Global Offset Table) in dynamic linking

## First call
**1. Function Call:**

* The `printf` function is called in the `main` function.

**2. PLT Section:**

* The call to `printf` is redirected to the `printf@plt` entry in the PLT.

**3. Jump to GOT:**

* The `printf@plt` entry contains a jump instruction that initially points to a resolver function.
* This jump instruction is executed, and the control flow is transferred to the resolver function.

**4. Resolver Function:**

* The resolver function checks if the GOT entry for `printf` is filled.
* If not, the resolver function loads the shared library containing `printf` and updates the GOT entry with the correct address.

**5. Return to Main:**

* The resolver function returns to the PLT, and the control flow is transferred back to the `main` function.

**6. Subsequent Calls:**

* Subsequent calls to `printf` will directly jump to the correct address in the GOT, avoiding the need for further resolution.



## Second call

* **Second call:** The `printf` function is called for the second time.
* **PLT jump:** The call is redirected to the `printf@plt` entry in the PLT.
* **GOT update:** The GOT entry for `printf` has already been filled with the correct address during the first call.
* **Direct call:** The PLT stub directly jumps to the address in the GOT, avoiding the need for further resolution.
* **Disassembled code:** The disassembled code shows the instructions executed for the second call to `printf`, including the direct jump to the GOT entry.

**Comparison to First Call:**

* **First call:** The PLT stub jumps to the resolver function, which loads the shared library and updates the GOT entry.
* **Second call:** The PLT stub directly jumps to the GOT entry, avoiding the resolver function and improving performance.


