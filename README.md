# Robospark-2021-FT-Hash-Map

## Hashing

> Hashing is the process of converting a given key into another smaller value for O(1) retrieval time.

- This is done by taking the help of some function or algorithm which is called as hash function to map data to some encrypted or simplified representative value which is termed as “hash code” or “hash”. This hash is then used as an index to narrow down search criteria to get data quickly.
- Hashing can be considered as a significant improvement over DAT to reduce the space complexity.

## Hash Table

> A hash table is an array that stores pointers to data mapping to a given hashed key.

- Hash table uses hash function to compute index of array where a record will be inserted or searched. Basically, there are 2 main components of hash table: Hash function and array.
- A value in hash table is null if no existing key has hash value equal to the index for the entry.
- The average time complexity needed to search for a record in hash table is O(1) under reasonable assumptions.
- The maximum size of the array is according to the amount of data expected to be hashed.

## Hash Functions

> A hash function is a function or algorithm that is used to generate the encrypted or shortened value to any given key. The resultant of hash function is termed as a hash value or simply hash.

## Collisions

> The phenomenon where two keys generate same hash value from a given hash function is called as a collision. A good hash function should ensure that the collisions are minimum.

## Linear probing

> Linear probing is a scheme in computer programming for resolving collisions in hash tables, data structures for maintaining a collection of key–value pairs and looking up the value associated with a given key.
>
> > >

- Calculate the hash key. key = data % size;

- If hashTable[key] is empty, store the value directly. hashTable[key] = data.

- If the hash index already has some value, check for next index.

- key = (key+1) % size;

- If the next index is available hashTable[key], store the value. Otherwise try for next index.

- Do the above process till we find the space.
  > > >
