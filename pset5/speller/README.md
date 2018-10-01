# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is an artificial long word said to mean a lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

getrusage() returns resource usage measures for RUSAGE_SELF (which is the sum of resources used by all threads) , RUSAGE_CHILDREN (which is the sum of resources used by children, grandchildren and furthur removed descendants), or RUSAGE_THREAD (resources for calling the thread)

## Per that same man page, how many members are in a variable of type `struct rusage`?

14

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

By passing the two structures by reference, we save a lot of system resources which would have otherwise been used for making a copy of the two structs everytime it was passed by value.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The `for` loop (in line 71) iterates through each character in the text file until it reaches the EOF character. The loop uses conditional statements to accept only alphabetical characters and apostrophes while it rejects alphanumeric strings and alphabetical strings too long to be words.
If a proper word is found, a counter is incremented and the check() function is called to check the word's spelling. The amount of system resources being used while this is being done is noted and the total time taken is noted. If a misspelling is detected, another counter is incremented by 1.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc allows us to dynamically store each word whereas if we use fscanf it may be difficult to properly allocate the right memory for each word.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

When the variables are declared as constant, it means that the variables are not meant to be modified in any shape or form. Since we do not want to modify the word or the dictionary, we declared it as const.
