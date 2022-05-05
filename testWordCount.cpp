#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

string makeValidWord(const std::string & word);

int main(){
    cout << "Testing WordCount..." << endl << endl;

    cout << "testing makeValidWord()" << endl;
    string validWord;

    validWord = makeValidWord("A");
    ASSERT_EQUALS("a", validWord);

    validWord = makeValidWord("computER-sCieNce");
    ASSERT_EQUALS("computer-science", validWord);

    validWord = makeValidWord("12mOnkEYs-$");
    ASSERT_EQUALS("monkeys", validWord);

    validWord = makeValidWord("12mOnkEYs-");
    ASSERT_EQUALS("monkeys", validWord);

    validWord = makeValidWord("Pa55ive");
    ASSERT_EQUALS("paive", validWord);

    validWord = makeValidWord("Pa55ive");
    ASSERT_EQUALS("paive", validWord);

    validWord = makeValidWord("Can'tGood-Hearted--");
    ASSERT_EQUALS("can'tgood-hearted", validWord);

    validWord = makeValidWord("ke-ke-ke-'");
    ASSERT_EQUALS("ke-ke-ke", validWord);

    validWord = makeValidWord("-");
    ASSERT_EQUALS("", validWord);

    validWord = makeValidWord("-nice-");
    ASSERT_EQUALS("nice", validWord);

    validWord = makeValidWord("'''''''NICE!!");
    ASSERT_EQUALS("nice", validWord);

    //EMPTY STRINGS MIGHT BE INVALID WORDS
    validWord = makeValidWord("--$$--");
    ASSERT_EQUALS("", validWord);

    cout << endl;

    WordCount w;
    WordCount w2;
    WordCount w3;
    WordCount w4;
    WordCount w5;

    //create an array/list of random strings (then add them to the wordcount object)
    vector<string> wordList = {"foo", "GOO", "CS", "cs", "lAb", "computER-sCieNce", "relatively-long-string-but-not-that-long", "computer-science", "CS", "ucsb", "North-Hall", "library", "compiler", "foO", "goO", "hash", "lIBRARY", "", "A",  "", "HaSh", "this-is-a-super-long-string-to-test-the-edge-case-of-a-string-that's-longer-than-the-max-capacity-defined-in-the-class-WordCount", "A", "a", "Another-Long-String-Except-The-First-Letter-Of-Each-Word-Is-Capitalized-Except-For-This-Word-Here-word", "Another-Long-String-Except-The-First-Letter-Of-Each-Word-Is-Capitalized-Except-For-This-Word-Here-word", "A", "a", "b", "a-bit-of-a-longer-word-but-not-that-long"};
    vector<string> wordList2 = {"sports", "mlb", "nfl", "nba", "nhl", "premier-league", "soccer", "BASKETBALL", "TeNnIs", "racket", "ball", "NBA", "GSW", "united-states", "los-angeles-lakers", "milwaukee", "SUNS", "memphis-grizzlies", "PLAYoffs", "offseason", "gsw", "bball", "a", "b", "c", "d", "e", "f", "g", "h", "b", "c"};
    vector<string> wordList3 = {"a", "b", "c"};
    vector<string> wordList4 = {"a", "b", "c", "a", "b", "c", "A", "B", "C"};

    //"foo", "GOO", "CS", "lAb", "computER-sCieNce", "relatively-long-string-but-not-that-long", "ucsb", "North-Hall", "library", "compiler", "hash", "lIBRARY", "", "A", "HaSh", "this-is-a-super-long-string-to-test-the-edge-case-of-a-string-that's-longer-than-the-max-capacity-defined-in-the-class-WordCount", "Another-Long-String-Except-The-First-Letter-Of-Each-Word-Is-Capitalized-Except-For-This-Word-Here-word", "b", "a-bit-of-a-longer-word-but-not-that-long"
    //"sports", "mlb", "nfl", "nba", "nhl", "premier-league", "soccer", "BASKETBALL", "TeNnIs", "racket", "ball", "GSW", "united-states", "los-angeles-lakers", "milwaukee", "SUNS", "memphis-grizzlies", "PLAYoffs", "offseason", "bball", "a", "b", "c", "d", "e", "f", "g", "h"
    //iterate thru the array/list of strings and then add them to the object - check the wordcount functions here

    //test incrWordCount()
    //cout << "testing incrWordCount()" << endl << endl;
    cout << "adding words to the WordCount objects..." << endl;
    
    string s;
    for (int i = 0; i < wordList.size(); i++){
        s = wordList.at(i);
        w.incrWordCount(s);
    }

    for (int i = 0; i < wordList2.size(); i++){
        s = wordList2.at(i);
        w2.incrWordCount(s);
    }

    for (int i = 0; i < wordList3.size(); i++){
        s = wordList3.at(i);
        w3.incrWordCount(s);
    }

    for (int i = 0; i < wordList4.size(); i++){
        s = wordList4.at(i);
        w4.incrWordCount(s);
    }
    w5.incrWordCount("--$$--");
    cout << endl;

    //test getTotalWords()
    cout << "testing getTotalWords()" << endl;
    int wordListSize;

    wordListSize = wordList.size();
    ASSERT_EQUALS(wordListSize, w.getTotalWords());

    wordListSize = wordList2.size();
    ASSERT_EQUALS(wordListSize, w2.getTotalWords());

    ASSERT_EQUALS(0, w5.getTotalWords());

    cout << endl;

    //test getNumUniqueWords()
    cout << "testing getNumUniqueWords()" << endl;
    ASSERT_EQUALS(17, w.getNumUniqueWords());
    ASSERT_EQUALS(28, w2.getNumUniqueWords());
    ASSERT_EQUALS(3, w3.getNumUniqueWords());
    ASSERT_EQUALS(3, w4.getNumUniqueWords());

    cout << endl;

    //test getWordCount()
    cout << "testing getWordCount()" << endl;
    ASSERT_EQUALS(2, w.getWordCount("foo"));
    ASSERT_EQUALS(5, w.getWordCount("a"));
    ASSERT_EQUALS(3, w.getWordCount("cs"));
    ASSERT_EQUALS(1, w.getWordCount("lab"));
    ASSERT_EQUALS(0, w.getWordCount("this-string-is-not-in-the-object"));
    ASSERT_EQUALS(2, w.getWordCount("computer-SCIENCE"));
    ASSERT_EQUALS(1, w.getWordCount("UCSB"));
    ASSERT_EQUALS(1, w.getWordCount("this-is-a-super-long-string-to-test-the-edge-case-of-a-string-that's-longer-than-the-max-capacity-defined-in-the-class-WordCount"));
    ASSERT_EQUALS(0, w.getWordCount("another-string-that's-not-in-the-object"));

    ASSERT_EQUALS(2, w2.getWordCount("nba"));
    ASSERT_EQUALS(2, w2.getWordCount("gsw"));
    ASSERT_EQUALS(1, w2.getWordCount("sports"));
    ASSERT_EQUALS(0, w2.getWordCount("houston-rockets"));
    ASSERT_EQUALS(0, w2.getWordCount(""));
    ASSERT_EQUALS(2, w2.getWordCount("b"));
    ASSERT_EQUALS(1, w2.getWordCount("bball"));
    ASSERT_EQUALS(1, w2.getWordCount("f"));
    ASSERT_EQUALS(1, w2.getWordCount("nfl"));

    cout << endl;

    //test decrWordCount()
    cout << "testing decrWordCount()" << endl;
    int wordCount = 0;

    wordCount = w.decrWordCount("foo");
    ASSERT_EQUALS(1, wordCount);

    wordCount = w.decrWordCount("a");
    ASSERT_EQUALS(4, wordCount);

    wordCount = w.decrWordCount("cs");
    ASSERT_EQUALS(2, wordCount);

    wordCount = w.decrWordCount("lab");
    ASSERT_EQUALS(0, wordCount);

    wordCount = w.decrWordCount("lab");
    ASSERT_EQUALS(-1, wordCount);

    wordCount = w.decrWordCount("this-string-is-not-in-the-object");
    ASSERT_EQUALS(-1, wordCount);

    wordCount = w.decrWordCount("computer-science");
    ASSERT_EQUALS(1, wordCount);

    wordCount = w.decrWordCount("ucsb");
    ASSERT_EQUALS(0, wordCount);

    wordCount = w.decrWordCount("this-is-a-super-long-string-to-test-the-edge-case-of-a-string-that's-longer-than-the-max-capacity-defined-in-the-class-WordCount");
    ASSERT_EQUALS(0, wordCount);
    
    wordCount = w.decrWordCount("another-string-that's-not-in-the-object");
    ASSERT_EQUALS(-1, wordCount);

    cout << endl;
    //remove some of these words (pick a few) - check the wordcount functions here (difference between this and previous function)


}
string makeValidWord(const std::string & word) {
	string validWord = "";
	char c;

    bool isAlpha = false;
	int validStartingIndex = 0;
	int validEndingIndex = 0;

	for (int i = 0; i < word.size(); i++){
		// if (word.at(i) != '\'' && word.at(i) != '-'){
		// 	validStartingIndex = i;
		// 	break;
		// }
		if (isalpha(word.at(i))){
            isAlpha = true;
			validStartingIndex = i;
			break;
		}
	}
    if (!isAlpha){
        return "";
    }
    
	for (int i = word.size() - 1; i >= 0; i--){
		// if (word.at(i) != '\'' && word.at(i) != '-'){
		// 	validEndingIndex = i;
		// 	break;
		// }
		if (isalpha(word.at(i))){
			validEndingIndex = i;
			break;
		}
	}
	for (int i = validStartingIndex; i < validEndingIndex + 1; i++){
		c = word.at(i);

		if (isalpha(c)){
			validWord+=(tolower(c));
		}
		else if (c == '\'' || c == '-'){
			validWord+=(c);
		}
	}

	return validWord;
}