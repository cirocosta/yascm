# 1. Exercises 

## 1.1 Difference between compiler and interpreter

A compiler is a program that reads a program in one language (source) and then translates it into an equivalent program in another (target) language. An interprether does not produces a target program as a translation, but directly executes operations specified in the source program on inputs supplied by the user (generates output).

In general the main difference between them is the produced code. The first generates machine specific, while the second one, is not tailored (in general) just for a target machine.

## 1.1.1 Virtual Machines

Virtual machines are hardware emulated in software, bridging the gap between compilation and interpretation. Tipically the virtual machine interprets an assembly-like program representation, which is created through a compilation process that does not target a specific machine. So, portability is its must (e.g, java).

### 1.1.2 JIT (just-in-time) Compilation (Dynamic Translation)

This is just compilation (to machine code) done during execution of a program (at run time), rather than prior to execution.

### 1.1.3 AOT (ahead-of-time) Compilation

The act of compiling a high-level programming language into a native (system-dependent) machine code.


## 1.2 Advantages of one over the other

The compiler may have a faster execution and also optimisation for the target hardware (pros). In the other hand, it requires a compiler and, by the way things gets done, it requires a slower way of deploying code. 

Interpreters usually run slower than compilers, have limited access to machine-specific optimizations. In the other hand it has a big con: portability

## 1.3 What advantages are there to a language-processing system in which the compiler produces assembly language rather than machine language

## 1.4 A compiler that translates a high-level language into another high-level language is called a source-to-source translator. What advantages are there to using C as a target language for a compiler?

## 1.5 Describe some of the tasks that an assembler needs to per­ form.
