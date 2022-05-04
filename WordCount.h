// WordCount.h

#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class WordCount {
public:
  // Default Constructor
  WordCount();

  // Return total number of word occurrences (for all words) in the
  // hash table.
  int getTotalWords() const;

  // Return total number of unique words that exist in the hash table.
  // Note that multiple occurrences of a word is considered one unique
  // word.
  int getNumUniqueWords() const;

  // Return the number of occurences for a specific word.
  // You may not assume the parameter is a valid word and must
  // strip / convert to lower case before looking in the hash table.
  // If the word does not exist in the table, return 0
  int getWordCount(const std::string & word) const;

  // Update the hash table by incrementing the number of occurences for
  // the word. You MAY NOT assume the parameter word is a valid word.
  // Words must be hashed and stored containing all lower case
  // characters.
  // * If the word is not in the table, then add it with the number
  //   of occurences equal to 1.
  // * If the word was added, this method updates the number of occurences
  //   of the word in the hash table, and returns the current number of
  //   occurences of the word after it was added.
  int incrWordCount(const std::string & word);

  // Update the hash table by decrementing the number of occurences for
  // the word. You MAY NOT assume the parameter word is a valid word.
  // The word must be converted to a valid word containing all
  // lower case characters to be searched through the hash table.
  // * If an entry for the word exists and the number of occurences is > 1,
  //   then the number of occurences for this word entry is updated and this
  //   method returns the updated number of occurences.
  // * If the number of occurences for the word is 1, then the key / value
  //   pair entry in the hash table is removed from the vector and 0 is
  //   returned.
  // * If the word does not exist, then this method returns -1.
  int decrWordCount(const std::string & word);

  // Useful as a helper method in your code.
  // Returns true if c is a valid word character defined as either
  // a lower-case or upper-case alpha char.
  static bool isWordChar(char c);

  // Words cannot contain any digits, or special characters EXCEPT for
  // hyphens (-) and apostrophes (') that occur in the middle of a
  // valid word (the first and last characters of a word must be an alpha
  // character). All upper case characters in the word should be convertd
  // to lower case.
  //
  // For example, "can't" and "good-hearted" are considered valid words.
  // "12mOnkEYs-$" will be converted to "monkeys".
  // "Pa55ive" will be stripped "paive".
  static std::string makeValidWord(const std::string & word);

private:
  // capacity for the hash table array
  const static size_t CAPACITY = 100;

  // hash table array of vectors. Each index in the array will contain
  // a vector. Each element in the vector contains a <string, int>
  // pair where the string value represents a unique word and the int
  // value represents the number of occurences for that word.
  //
  // In effect, this representation is used for implementing chained
  // hashing where we use vectors for chaining.
  std::vector<std::pair<std::string, int>> table[CAPACITY];

  // Hash function that will return an index for the hash table.
  size_t hash(const std::string & word) const;
};


#endif // WORDCOUNT_H
