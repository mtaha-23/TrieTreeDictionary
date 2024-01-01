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

# Screenshots
#### - Adding a New Word<br>
![Screenshot 2024-01-01 142702](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/fdc92503-6b61-46b1-a3c5-aba8ba74f362)

#### - Searching Word <br>
![Screenshot 2024-01-01 142710](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/281ace0c-286a-4383-9707-9bf19e5f12ec)

#### - Searching a word that don't exist <br>

![Screenshot 2024-01-01 142716](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/239e58f6-8955-4beb-bdab-086c62fe656c)

#### - Updating Meaning of Word <br>
![Screenshot 2024-01-01 142724](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/64a09a3d-1bf2-4f3c-afd1-efe4595c8d47)

#### - Searching Word to see new Meaning<br>
![Screenshot 2024-01-01 142728](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/4c3b8313-a4c9-45c0-a155-d764fd6b8ba4)

#### - Deleting Word <br>
![Screenshot 2024-01-01 142746](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/426339da-d127-47e4-9175-814eae67b69a)

#### - Searching Word after it is deleted<br>
![Screenshot 2024-01-01 142753](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/29e60191-264e-41b6-b1a8-4aec65a5f0dd)

#### - Seeing word suggestion from a prefix<br>
![Screenshot 2024-01-01 142800](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/8b292d98-4762-49e4-af67-84a883187dd1)

#### - Seeing word suggestion from a prefix<br>
![Screenshot 2024-01-01 142804](https://github.com/mtaha-23/TruthTableGenerator/assets/132524394/262f5e5d-9f5c-4fe4-92bd-98a49442e963)
