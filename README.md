# README.md

## exception.h
**Example**:
```c++
try {
    printf("Before\n");
    throw(FileNotFoundException);
    printf("After\n");
}catch(NullPointerException) {
    printf("NullPointerException\n");
}catch(IOException) {
    printf("IOException\n");
}else{
    printf("Else\n");
}
```
**Output**:
``` 
Before
IOException
```
**Explanation**: 
The code inside the `catch` block runs if `((y % x) == 0)` is true, `y` is the thrown exception and `x` is the parameter that is passed to the catch (`catch(x)`).
The code inside runs if the exception passed is divisible by the exception thrown. This is why the code at the top works, because `FileNotFoundException` is an `IOException`
```c
#define IOException 2           
#define FileNotFoundException 4
```
To create a custom exception pick an unused prime number and create a macro for it
```c
#define FooException 7
```
To create subexceptions for it, create a macro that has the square the value of the parent exception
```c
#define BarException 49     // 7*7
```
An exception can have multiple parents, because a number can be divisible by multiple numbers
```c
#define FooException 7
#define BarException 9
#define FooBarException 63 // (7*9) 
        // if this is thrown both FooException and BarException will catch it
```
**Note:** *catch blocks are checked from top to bottom

**Note:** *This library has the GPL 3.0 license*