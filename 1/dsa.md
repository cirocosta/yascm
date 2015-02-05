# Semantic Analysis

checks for semantic consistency, mainly performing type checking and providing coercions (some type conversions), saving some informaton on the symbol table.

# Intermediate code generation

Produces resonably low-level code, easy to generate and further translating it into the target machine.

# Symbol-Table

DataStructure with each variable name and fields for the attributes of it. These attributes may, then, provide information about the storage allocated for a name, as well as the type, its scope and also procedure names, if it was passed by reference or value, etc..

# Programming languages

They can be classified by:

-	generation
	-	first gen: machine languages
	- second gen: assembly languages
	- third gen: higher-level (Lisp, Fortran,C ...)
	- fourth gen: languages for specific applicaiton (SQL, Postscript ...)
	- fifth gen: log and constraint-based (Prolog)
- paradigm
	-	imperative: specifies *how* a computation is to be done
	- declarative: specifies *What* computation to be done
- Von Neumann Languages: languages which are based on his computer architecture
- object-oriented: supports OOP
- scripting - interpreted and uses high-level operatores for gluing computations
