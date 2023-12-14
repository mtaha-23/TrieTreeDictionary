#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include<regex>
using namespace std;
//function to color text on console
void redColor();
void greenColor();
void whiteColor();
void grayColor();
struct Node
{
public:

    Node* alphabets[26]; //each node having 26 further nodes
    bool isEndOfWord; //a flag for isEndOfWord of the string on particular node
    string meaning;
    Node();
};
class Dictionary
{
public:
    Dictionary();
    //main menu
    void mainMenu();

private:
    Node* root; //root of our node class

    //lower case the string 
    void lowerCaseString(string& str);

    //return true if it is non Alpha  
    bool isNonAlpha(const string str);

    //load data from file into Tree
    void loadDictionary();  

    //delete word from tree and file
    bool deleteWord(string word);
    //finds the line number of word to delete and delete's it from file using deleteLineFromFile() function
    void deleteWordFromFile(string word);
    //delete line from file by creating a new file and copying the data
    void deleteLineFromFile(const string& filePath, int deleteLineNo);
    
    //inserts word in Tree and returns true
    bool insertWordInTree(string word, string meaning);
    //inserts word in File
    void insertWordInFile(string word, string meaning);
    
    //search the Node of word where EndOfWord is true
    Node* searchNode(string word);
    //searches for Word and return's it's meaning if found 
    string searchMeaning(string word);
    //searches for word and print it's meaning
    void searchWordAndPrintMeaning(string word);

    //updates meaning of the word, if word is not present than it asks to add it
    void updateMeaning(string word, string newMeaning); 

    //prints 10 suggested words with same prefix
    void suggestWord(string prefix);
    //find the suggested word and prints it    
    void suggestWord(Node* curr, string prefix, int& count); 
};