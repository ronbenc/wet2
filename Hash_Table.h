#ifndef WET2_HASH_TABLE_H
#define WET2_HASH_TABLE_H

#include <cassert>
#include "List_Map.h"

template <class T>
class Hash_Table
{
private:
    const int inititial_array_size = 4;
    const double maximal_load_factor = 1;
    int array_size;
    int num_of_elements;
    List_Map<int, T>* hash_table_array;

    int hash(const int key);

public:
    
    Hash_Table();
    Hash_Table(const Hash_Table& to_copy);
    ~Hash_Table();

    void insert(const int key, const T& value = T());
    //access only
    T& operator[] (const int key);
};

//***************************************functions implementation**************************************

template <class T>
int Hash_Table<T>::hash(const int key)
{ 
    int index =  key % array_size;

    assert(index >= 0 && index < array_size);

    return index;
}


template <class T>
Hash_Table<T>::Hash_Table() : array_size(inititial_array_size), num_of_elements(0), hash_table_array(new List_Map<int, T>[array_size])
{ 
}

template <class T>
Hash_Table<T>::Hash_Table(const Hash_Table& to_copy) : array_size(to_copy.array_size), num_of_elements(to_copy.num_of_elements), hash_table_array(new List_Map<int, T>[array_size])
{
    for(int i = 0; i < array_size; ++i)
    {
        hash_table_array[i](to_copy.hash_table_array[i]); 
    }
}

template <class T>
Hash_Table<T>::~Hash_Table()
{
    delete[] hash_table_array;
}

template <class T>
void Hash_Table<T>::insert(const int key, const T& value)
{
    hash_table_array[hash(key)].insert(key, value);
    num_of_elements++;

    //handle resizing...
}

template <class T>
T& Hash_Table<T>::operator[] (const int key)
{
    return  hash_table_array[hash(key)][key];
}

#endif //WET2_HASH_TABLE_H