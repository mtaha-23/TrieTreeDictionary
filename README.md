# TrieTreeDictionary

This is a GitHub repository for a dictionary implementation that uses a trie data structure. A trie is a tree-like structure that stores words and their meanings in a compact and efficient way. With this, you can:

- Add a new word and its meaning to the dictionary
- Search for the meaning of an existing word in the dictionary
- Delete a word and its meaning from the dictionary
- Update the meaning of a word in the dictionary
- Get suggestions for words that start with a given prefix

# Functions

**`void ___Color()`**
```c
printf("\033[1;31m"); //redColor
printf("\033[1;32m"); //greenColor
printf("\033[0m"); //whiteColor
printf("\033[1;30m"); //grayColor
```
These color functions can be used in C and C++. [You can further see more about ANSI Colors.](https://github.com/Guleri24/ANSI-color-code-in-c-programming/blob/master/main.c)

**`Node();`**<br>
Default constructor of Node class. It initializes _`bool isEndOfWord`_ as false, _`string meaning`_ as empty
and _`Node* alphabets[26]`_ as nullptr.  

**`Dictionary();`**<br>
Default constructor of Dictionary. It loads the Dictionary Data from Dictionary file to Tree. In the Dictionary File the _`meaning is on the left`_ and _`word is on the right`_.  

**`void mainMenu();`**<br>
This Function is the mainMenu. This is used to access dictionary action. It takes input from the user on 
which operation to perform and performs the action. 

**`void lowerCaseString(string& str);`**<br>
This Function is used to convert the string in lower case as the word APPLE and apple are same in 
dictionary.

**`bool isNonAlpha(const string str);`**<br>
This Function is returns true if the string contain’s non alphabet character. 

**`bool deleteWord(string word);`**<br>
This function is used to delete the Word from the File. If the Word is found it calls the _`void
deleteWordFromFile(string word)`_ function and deletes the word and return true else it will return 
false.

**`void deleteWordFromFile(string word);`**<br>
This functions find the word in file and count the line no on which the word is present than it calls the 
_`void deleteLineFromFile(const string& filePath, int deleteLineNo)`_ function and send the file 
name and the line number to delete. 

**`void deleteLineFromFile(const string& filePath, int deleteLineNo);`**<br>
This function takes the file name and line no to delete than it creates new file and copies all the data 
from the original file to new file except the line no which contains the word that has to be deleted than 
it rename the new file and deletes the old file.

**`bool insertWordInTree(string word, string meaning);`**<br>
This functions insert a new word in Tree in the tree and then calls the _`void insertWordInFile(string
word, string meaning)`_ function to insert that word in file and return true. But if the word it already 
present in Tree than it asks to update it’s meaning, if Yes than _`void updateMeaning(string word, 
string newMeaning)`_ function is called to update meaning.

**`void insertWordInFile(string word, string meaning);`**<br>
The function inserts the word and meaning in file. In the Dictionary File the _`meaning is on the left`_ and _`word is on the right`_.

**`Node* searchNode(string word);`**<br>
This function returns the Node pointer to the node where the given word is ending. Then it is used in 
deleting Word, suggesting Word and Updating Word Functions.

**`string searchMeaning(string word);`**<br>
This function searches for the word and if the word is found then it returnsits meaning or else it returns 
empty string.

**`void searchWordAndPrintMeaning(string word);`**<br>
This function calls the _`string searchMeaning(string word)`_ function and prints the word with its
meaning. 

**`void updateMeaning(string word, string newMeaning);`**<br>
This function searches word with the help of _`Node* searchNode(string word)`_ function, if the word is found it 
deletes the old Word from file using _`bool deleteWord(string word)`_ function, than updates the 
meaning of the word and inserts the word in Tree and File using _`void insertWordInFile(string word, 
string meaning)`_ function.

**`void suggestWord(string prefix);`**<br>
This Function find the Node of prefix where endOfWord is true and passes it to _`void suggestWord(Node* curr, string prefix, int& count)`_ function to print 10 word suggestions.

**`void suggestWord(Node* curr, string prefix, int& count);`**<br>
This function recursively prints 10 words and their meaning with the prefix word passed as parameter.
