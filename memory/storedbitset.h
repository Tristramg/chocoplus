#ifndef _SBIT
#define _SBIT

#include "environment.h"
#include "storedlong.h"
#include <vector>
#include <iostream>

class StoredBitSet : public StoredElement
{
private:
  const static int _ADDR_BITS_PER_WORD = 6;
  const static int _BITS_PER_WORD = 1 << _ADDR_BITS_PER_WORD;
  const static int _BIT_INDEX_MASK = _BITS_PER_WORD - 1;
  
  const static uint64_t _WORD_MASK = 0xffffffffffffffffLL;
  
  std::vector<StoredLong*> _words;
  size_t _size;
  
 
  
public:
  
  StoredBitSet(Environment*,size_t);
  ~StoredBitSet();
  
  
  void set(size_t);
  void set(size_t,size_t);
  
  void clear(size_t);
  void clear(size_t,size_t);
  
  void clear();
  
  bool get(size_t); 
  int next_set(size_t);
  int prev_set(size_t);
  int next_clear(size_t);
  int prev_clear(size_t);
  int cardinality();
  
  void print();
 
};



#endif