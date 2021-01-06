#ifndef WET2_HASH_TABLE_H
#define WET2_HASH_TABLE_H

#include <cassert>
#include "List_Map.h"

const int inititial_hash_table_array_size = 4;
const double maximal_load_factor = 1;
const double minimal_load_factor = 0.25;

template <class T> //value type
class Hash_Table
{
private:
    int array_size;
    int num_of_elements;
    List_Map<int, T>* hash_table_array;

public:
    Hash_Table();
    ~Hash_Table();
    void insert(const int key);
    void erase(const int key);
    T& operator[] (const int key); //access only
    bool contains(const int key);
    int size() const;

private:
    inline int hash(const int key) const;
    void resize(const int new_array_size); //and rehash
};

//***************************************functions implementation**************************************

template <class T>
Hash_Table<T>::Hash_Table() : array_size(inititial_hash_table_array_size), num_of_elements(0), hash_table_array(new List_Map<int, T>[array_size])
{ 
}

template <class T>
Hash_Table<T>::~Hash_Table()
{
    delete[] hash_table_array;
}

template <class T>
void Hash_Table<T>::insert(const int key)
{
    hash_table_array[hash(key)].insert(key);
    num_of_elements++;

    //handle enlargement
    double curr_load_factor = ((double)num_of_elements) / array_size;
    if(curr_load_factor >  maximal_load_factor)
    {
        this->resize(2 * array_size);
    }
}

template <class T>
void Hash_Table<T>::erase(const int key)
{
    hash_table_array[hash(key)].erase(key);
    num_of_elements--;
    //handle reduction
    double curr_load_factor = ((double)num_of_elements) / array_size;
    if(curr_load_factor <  minimal_load_factor)
    {
        this->resize(array_size / 2);
    }
}

template <class T>
T& Hash_Table<T>::operator[] (const int key)
{
    return hash_table_array[hash(key)][key];
}

template <class T>
bool Hash_Table<T>::contains(const int key)
{
    return hash_table_array[hash(key)].contains(key);
}

template <class T>
int Hash_Table<T>::size() const
{
    return num_of_elements;
}


//***********************************************private methods*********************************

template <class T>
int Hash_Table<T>::hash(const int key) const
{ 
    int index =  key % array_size;

    assert(index >= 0 && index < array_size);

    return index;
}

template <class T>
void Hash_Table<T>::resize(const int new_array_size)
{
    List_Map<int, T>* new_hash_table_array =  new List_Map<int, T>[new_array_size];

    int old_array_size = array_size;
    array_size = new_array_size;

    for(int i = 0; i < old_array_size; i++)
    {
        List_Map<int, T> curr_list = hash_table_array[i];
        for(typename List_Map<int, T>::iterator it = curr_list.begin(); it != curr_list.end(); ++it)
        {
            new_hash_table_array[hash(it->key)].insert(it->key, it->value);
        }
    }
    
    delete[] hash_table_array;
    hash_table_array = new_hash_table_array;
}

#endif //WET2_HASH_TABLE_H