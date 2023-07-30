Group Project
C - Printf project
A function that produces output according to a format
Handle the following conversion specifiers:
d, i
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers
Handle the following custom conversion specifiers:
b: the unsigned int argument is converted to binary
Handle the following conversion specifiers:
u
o
x
X
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers
Use a local buffer of 1024 chars in order to call write as little as possible.
Handle the following custom conversion specifier:
S : prints the string.
Non-printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
