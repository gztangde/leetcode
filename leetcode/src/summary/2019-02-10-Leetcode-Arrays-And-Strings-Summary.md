Any array questions and string questions are often **Interchangeable**. That is, a question that using an arrsy may be asked instead as a string questions.

# Hash Table

A data structure that maps keys to values for highly efficient lookup. Think about how to implementing a hash table. We can use an array of linked lists and a hash code function. To insert a key (Which might be a string or essentially any other data type) and value. We do the following

1. Firstly, compute the key's hash code, which will usually be a int or long. (Note that two different keys could have the **same hash code** as there may be an infinite number of keys and a finite number of ints.)
2. Then, map the hash code to an index in the array. This could be done with something like hash(key) % array_lenght. Two different hash codes could, of course, map to the same index.
3. At the index, there is a linked list of keys and values. Store the key and value in this index. We mush use a linked list because of collisions: you could have two different keys with the smae hash code. or two different hash codes that map to the same index.

