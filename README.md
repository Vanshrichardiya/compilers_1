Name: Chardiya Vanshribahen Rajeshbhai
Roll Number: 23110074
Email: 23110074@iitgn.ac.in
Programming Language Used (Part 3): C

Compilation Instructions:
1. Open the terminal (Linux/WSL) and navigate to the directory containing tokenizer.c.
2. Compile the tokenizer using GCC:
   gcc tokenizer.c -o tokenizer
3. Run the tokenizer with the test files:
   ./tokenizer < public_test1.txt
   ./tokenizer < public_test2.txt
   ./tokenizer < public_test3.txt
4. To generate the output files:
   ./tokenizer < public_test1.txt > public_output1.txt
   ./tokenizer < public_test2.txt > public_output2.txt
   ./tokenizer < public_test3.txt > public_output3.txt

Known Issues/Limitations:
- Buffer Size: The tokenizer uses a fixed buffer of 256 characters. Tokens exceeding this length will be truncated to prevent buffer overflow.
- Number Support: As per the assignment specifications, only integers are supported. Floating-point numbers (e.g., 3.14) are not handled as a single token.
- Line Endings: The code explicitly handles both Linux (\n) and Windows (\r\n) line endings to ensure correct processing across different environments.
- No Library Functions: All string processing is implemented manually without <string.h> functions.
