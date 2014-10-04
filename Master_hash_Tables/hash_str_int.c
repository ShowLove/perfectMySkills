#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash_table
{
	// hash table -- an array of strings
	char **table;

	// number of time each key was put
	int *numTable;
	
	// number of elements currently in the table
	int size;
	
	// current length of array
	int capacity;
	
} hash_table;


// create and initialize a new hash table of the specified size
hash_table *create_table(int size)
{
	int i;
	
	//Create Table for strings
	hash_table *h = malloc(sizeof(hash_table));	
	h->table = malloc(sizeof(char *) * size);
	for (i = 0; i < size; i++)
		h->table[i] = NULL;

	//Create Table for ints
	h->numTable = malloc(sizeof(int) * size);
	
	h->capacity = size;
	h->size     = 0;
	
	return h;
}

// hash function that uses Horner's Rule to compute:
// (int)str[0] * 37^(k-1) + (int)str[1] * 37^(k-2) + ... + (int)str[k-1] * 37^0,
// where k = strlen(str)
int hash(char *key, int table_size)
{
	int i, hval = 0, len = strlen(key);
	
	for (i = 0; i < len; i++)
		hval = (hval * 37 + key[i]) % table_size;
	
	// For example: "cat"
	//    hval = 'c' * 37^2 + 'a' * 37 + 't'

	return hval;
}

// quadratic probing
int quadratic_get_pos(hash_table *h, char *key)
{
	int i = 1, index, hval = hash(key, h->capacity);

	index = hval;
	
	while (h->table[index] != NULL)
	{
		// assume keys in the hash table are unique, so it's okay to return this
		// position if get_pos() is called by the hash_put() function
		if (strcmp(h->table[index], key) == 0)
			return index;
		
		printf(" *%s* collides with *%s*\n", key, h->table[index]);
		
		index = (hval + i * i);
		if (index < 0)
			index = index * -1;
		index = index % h->capacity;
		i++;
	}

	return index;
}

// get index of element to be inserted / retrieved using the appropriate probing
// algorithm
int get_pos(hash_table *h, char *key)
{
	return quadratic_get_pos(h, key);
}



void print_table(hash_table *h)
{
	int i;
	
	for (i = 0; i < h->capacity; i++)
	{
		printf("%02d: %s ", i, (h->table[i] == NULL) ? "(null)" : h->table[i]);
		printf(": num(%d)\n", (h->table[i] == NULL) ? 0 : h->numTable[i] );
	}
	/*
	01: hello
	02: world
	...
	10: strings
	11: no
	12: longer
	13: line
	14: up
	 */
	printf("%c", '\n');
}

// determines whether an integer is prime
int is_prime(int n)
{
	int i;
	
	for (i = 3; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	
	return 1;
}

// a function to find the next prime number, beginning at n
int next_prime(int n)
{
	if (n % 2 == 0)
		n++;
	
	while (!is_prime(n))
		n += 2;
	
	return n;
}

// dynamically expand hash table
void expand_table(hash_table *h)
{
	int i, index, new_size;
	
	new_size = next_prime(h->capacity * 2 + 1);

	// create new, expanded hash table
	hash_table *new_table = create_table(new_size);
	
	printf("Hash table before expansion to size %d:\n", new_size);
	print_table(h);
	
	// rehash elements from the old table into the new table
	for (i = 0; i < h->capacity; i++)
	{
		if (h->table[i] != NULL)
		{
			index = get_pos(new_table, h->table[i]);
			new_table->table[index] = h->table[i];
			new_table->numTable[index] = h->numTable[i];
		
			new_table->size++;
		}
	}
	
	free(h->table);
	
	h->table    = new_table->table;
	h->numTable = new_table->numTable;
	h->size     = new_table->size;
	h->capacity = new_table->capacity;
	
	free(new_table);
	
	printf("Hash table after expansion:\n");
	print_table(h);
}

// insert key into hash table
void hash_put(hash_table *h, char *key, int value)
{
	int index = get_pos(h, key);
	
	// disallow insertion of duplicates into the hash table
	if (h->table[index] != NULL)
	{
		h->numTable[index] = value;
		return;
	}
		
	
	// create space for the new string
	h->table[index] = malloc(sizeof(char) * (strlen(key) + 1));
	//Keep track of how many times we have tried to insert the key
	h->numTable[index] = value;
	
	// copy string into hash table
	strcpy(h->table[index], key);
	
	// record keeping :)
	h->size++;
	
	// expand the table if it's over half full
	if (h->size > h->capacity / 2)
		expand_table(h);
}

// returns pointer to key if it is in the hash table, NULL otherwise
int hash_get(hash_table *h, char *key)
{
	if( h->table[get_pos(h, key)] == NULL )
		return -1;		//This tells us we have not initiated this key 
									//make certain to return something that won't be used as a value

	return h->numTable[get_pos(h, key)];
}

int main(void)
{
	char *temp;
	
	hash_table *h = create_table(11);
	
	hash_put(h, "Design", 1);
	hash_put(h, "and", 2);
	hash_put(h, "Analysis", 3);
	hash_put(h, "of", 4);
	hash_put(h, "Algorithms", 5);
	hash_put(h, "Data", 6);
	hash_put(h, "Data", 7);
	hash_put(h, "Structures", 8);
	
	printf("Hash table at end of main():\n");
	print_table(h);
	
	printf("\"Data\": %s\n", hash_get(h, "Data") == -1 ? "NO" : "YES");
	printf("\"data\": %s\n", hash_get(h, "data") == -1 ? "NO" : "YES");
	printf("\"and\": %s\n", hash_get(h, "and") == -1 ? "NO" : "YES");

	printf("\n use hash_get(Data)=(%d)\n", hash_get(h,"Data"));
	
	return 0;
}
