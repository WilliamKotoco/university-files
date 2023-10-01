#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100;

/// \brief bucket is a record that contains a particular set of 
/// keys and information associated with the keys. 
///
/// They are stored in a file.
struct bucket{
int depth;   ///< number of bits used in common by the keys in this bucket
struct directory *dir;    ///< directory that contains the bucket
int bucketAddr; ///< adress in file
};


/// creates a bucket.
struct bucket *create_bucket(struct directory *directory);

/// remove @key from the bucket
///
int remove_key(struct bucket *bucket, char *key);

/// Split and redistributes the keys.
///
/// The split is necessary when adding a new key causes
/// bucket overflow, being necessary to increase the directory's depth
///
struct bucket *split();

/// calculates the range of the new splited bucket
int new_range(int &new_start, int &new_end);


/// try to combine the bucket which his buddy.
int try_combine(struct bucket *bucket);

/// Finds a "buddy" bucket.
///
/// As extensible hashing is a dynamic system, it's abble 
/// to shrink files as we grow them. In the extensible hashing
/// model we combine buddy buckets to shrink
///
/// Buddy buckets is buckets that shares a portion of an address, in other words, 
/// are descented of the same node in a trie.
///
int find_buddy();



/// combine the currenty buddy with its buddy index.
int combine(struct bucket *curr_bucket, struct bucket *buddy, int buddy_index);
