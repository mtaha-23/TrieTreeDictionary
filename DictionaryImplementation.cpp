#include"DictionaryHeader.h"

///---------------------------------TEXT Color Functions---------------------------------
void redColor()
{
    printf("\033[1;31m");
}

void greenColor()
{
    printf("\033[1;32m");
}

void whiteColor()
{
    printf("\033[0m");
}

void grayColor()
{
    printf("\033[1;30m");
}

///---------------------------Node and Dictionary Default Constructor---------------------------

Node::Node() : isEndOfWord(false), meaning ("")
{
    for (int i = 0; i < 26; i++)
        alphabets[i] = nullptr;
}

Dictionary::Dictionary()
{
    root = new Node;
    loadDictionary();
}

///--------------------------------------------------------------------------------------

//main menu
void Dictionary::mainMenu()
{
    string word, meaning;

    string input;
    int choice;
    do
    {
        cout << "1) ADD WORD\n";
        cout << "2) SEARCH WORD\n";
        cout << "3) DELETE WORD\n";
        cout << "4) UPDATE WORD\n";
        cout << "5) WORD SUGGESTION\n";
        cout << "6) EXIT\n\n";

        grayColor();
       
        cout << "Select: ";
        bool again = true;
        while (again)
        {
            try
            {
                cin >> input;

                if (input.length() > 1)
                    throw string("Enter 1 char: ");

                if (!((input == "1") || (input == "2") || (input == "3") || (input == "4") || (input == "5") || (input == "6")))
                    throw string("Enter between 1-6: ");

                again = false;
            }
            catch (string error)
            {
                cin.clear();
                cin.ignore();
                redColor();
                cout << error;
                grayColor();
            }
        }
        choice = stoi(input);
        whiteColor();
        switch (choice)
        {
            //ADD WORD
        case 1:
        {
            cout << "Insert Word: ";
            bool again = true;
            while (again)
            {
                try
                {
                    cin >> word;

                    if (isNonAlpha(word))
                        throw string("Enter alpha Word: ");

                    again = false;
                }
                catch (string error)
                {
                    cin.clear();
                    cin.ignore();
                    redColor();
                    cout << error;
                    whiteColor();
                    
                }
            }

            cin.clear();
            cin.ignore();
            cout << "Insert Meaning: ";
            getline(cin, meaning);
           
            //it return true when word is inserted in dictionary
            if (insertWordInTree(word, meaning))
            {
                greenColor();
                cout << word << " Inserted\n";

            }
            else //it return false when word is already present in dictionary
            {
                redColor();
                cout << word << " not Inserted as New Word\n";
            }
            whiteColor();

            break;
        }

            //SEARCH WORD
        case 2:
            cout << "Search Word: ";
            again = true;
            while (again)
            {
                try
                {
                    cin >> word;

                    if (isNonAlpha(word))
                        throw string("Enter alpha Word: ");

                    again = false;
                }
                catch (string error)
                {
                    cin.clear();
                    cin.ignore();
                    redColor();
                    cout << error;
                    whiteColor();
                }
            }
            searchWordAndPrintMeaning(word);

            break;

            //DELETE WORD
        case 3:
            cout << "Delete Word: ";
            again = true;
            while (again)
            {
                try
                {
                    cin >> word;

                    if (isNonAlpha(word))
                        throw string("Enter alpha Word: ");

                    again = false;
                }
                catch (string error)
                {
                    cin.clear();
                    cin.ignore();
                    redColor();
                    cout << error;
                    whiteColor();
                }
            }

            if (deleteWord(word))
            {
                greenColor();
                cout << "Word " << word << " Deleted!\n";
            }
            else
            {
                redColor();
                cout << "Word " << word << " Not Found!\n";
            }
            whiteColor();

            break;

            //UPDATE WORD
        case 4:

            cout << "Enter Word: ";
            again = true;
            while (again)
            {
                try
                {
                    cin >> word;

                    if (isNonAlpha(word))
                        throw string("Enter alpha Word: ");

                    again = false;
                }
                catch (string error)
                {
                    cin.clear();
                    cin.ignore();
                    redColor();
                    cout << error;
                    whiteColor();
                }
            }
            cout << "Enter Updated Meaning: ";
            cin.clear();
            cin.ignore();
            getline(cin, meaning);
            updateMeaning(word, meaning);

            break;

            //WORD SUGGESTION
        case 5:
        {
            string prefix;
            cout << "Word Prefix: ";
            char ch;
            while (1)
            {
                if (_kbhit())
                {

                    //stores the pressed key in ch
                    ch = _getch();

                    cout << "\n";

                    //append the character to the prefix
                    prefix += ch;

                    //terminates the loop when escape is pressed
                    if (int(ch) == 27)
                        break;

                    //if backspace is pressed it removes last char from string
                    if (int(ch) == 8)
                        prefix = prefix.substr(0, prefix.length() - 2);
                    
                    ////if any other char is pressed except alphabets or backspace than it is removed from prefix, if esc is pressed it will break before coming to this line
                    if (!((int(ch) >= 65 && int(ch) <= 90) || (int(ch) >= 97 && int(ch) <= 122)) && !((int(ch) == 8)))
                        prefix = prefix.substr(0, prefix.length() - 1);

                    system("cls");
                    suggestWord(prefix);

                    cout << "\nESC to EXIT - Word Prefix: " << prefix;

                }
            }
        }
        break;
        
            //EXIT
        case 6:
            return;
        }
        cout << endl;
        
        //if word suggestion was opened before than no need to pause
        if (choice != 5)
            system("pause");
        
        system("cls");

    } while (choice != 6);
}

//lower case the string 
void Dictionary::lowerCaseString(string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        str[i] = tolower(str[i]);
    }
}

//return true if it is non Alpha  
bool Dictionary::isNonAlpha(const string str)
{
    return regex_match(str, regex("^[a-z A-Z]+$")) ? false : true;
}

//load data from file to Tree
void Dictionary::loadDictionary()
{
    fstream readFromFile;
    readFromFile.open("Dictionary.txt");
    if (readFromFile.is_open())
    {
        string word, meaning;

        while (!readFromFile.eof())
        {
            //read from file
            readFromFile >> meaning >> word;

            //insert in Tree
            Node* curr = root;

            for (int i = 0; i < word.length(); i++) //loop on each character in string
            {
                int index = word[i] - 'a';

                if (curr->alphabets[index] == nullptr) //check for chlid
                    curr->alphabets[index] = new Node; //if not than create a new one

                curr = curr->alphabets[index];
            }
            curr->isEndOfWord = true;

            curr->meaning = meaning;
        }

        greenColor();
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING";
        redColor();
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        system("cls");
        greenColor();
        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tDICTIONARY LOADED!\n";
        Sleep(1500);
        system("cls");
        whiteColor();

    }
    else
    {
        redColor();
        cout << "Can't Load Dictionary!\n";
        whiteColor();
    }

    readFromFile.close();
}

///-----------------------------------Delete Functions-----------------------------------

//delete word from tree and file
bool Dictionary::deleteWord(string word)
{
    lowerCaseString(word);

    Node* curr = searchNode(word);

    if (curr != nullptr && curr->isEndOfWord)
    {
        curr->isEndOfWord = false;  // Mark isEndOfWord flag as false to delete the word
        curr->meaning = ""; //remove meaning of the deleted word;

        deleteWordFromFile(word);

        return true;
    }

    return false;
}

//finds the line number of word to delete and delete's it from file using deleteLineFromFile() function
void Dictionary::deleteWordFromFile(string word)
{
    int wordToDeleteLineNo = 0;

    fstream readingWord;
    readingWord.open("Dictionary.txt");

    if (readingWord.is_open())
    {
        string fileWord, fileMeaning;

        while (readingWord >> fileMeaning >> fileWord)
        {
            //counting on which line the word is that is to be deleted
            ++wordToDeleteLineNo;

            if (word == fileWord)
                //if the word is found that is to be deleted than close the file now we have the line number to delete
                readingWord.close();
        }
    }
    else
    {
        redColor();
        cout << "Can't Open Dictionary for Deletion\n";
        whiteColor();
    }

    readingWord.close();

    string file = "Dictionary.txt";

    //removing previous word and meaning by removing the line
    deleteLineFromFile(file, wordToDeleteLineNo);
}

//delete line from file by creating a new file and copying the data
void Dictionary::deleteLineFromFile(const string& filePath, int deleteLineNo)
{
    ifstream readFile(filePath);
    ofstream writeTempFile("temp.txt");
    string line;
    int currentLineNo = 0;

    while (getline(readFile, line))
    {
        ++currentLineNo;

        if (currentLineNo != deleteLineNo)
        {
            writeTempFile << line << endl;
        }
    }

    readFile.close();
    writeTempFile.close();

    //remove the original file
    if (remove(filePath.c_str()) != 0)
    {
        redColor();
        cout << "Error deleting the " << filePath << " file." << endl;
        perror("Error details");
        return;
    }

    //rename the temp file to the original file name
    if (rename("temp.txt", filePath.c_str()) != 0)
    {
        redColor();
        cerr << "Error renaming the " << filePath << " file." << endl;
        perror("Error details");
    }

    whiteColor();
}

///-----------------------------------Insert Functions-----------------------------------

//inserts word in Tree and returns true
bool Dictionary::insertWordInTree(string word, string meaning)
{
    lowerCaseString(word);
    lowerCaseString(meaning);

    Node* curr = root;

    for (int i = 0; i < word.length(); i++) //loop on each character in string
    {
        int index = word[i] - 'a';

        if (curr->alphabets[index] == nullptr) //check for chlid
            curr->alphabets[index] = new Node; //if not than create a new one

        curr = curr->alphabets[index];
    }

    //if word is already present
    if (curr->isEndOfWord == true)
    {
        grayColor();
        cout << "Word Already Present in Dictionary\n";
        whiteColor();

        if (curr->meaning == meaning)
            return false; // if word with same meaning is present than return
        else
        {   //if meaning is different
            int choice;
            string input;
            cout << "Update Meaning?\nNo(0)\nYes(1)\n";
            bool again = true;
            while (again)
            {
                try
                {
                    cin >> input;

                    if (input.length() > 1)
                        throw string("Enter 1 char: ");

                    if (!((input == "1") || (input == "0")))
                        throw string("Enter 1 or 0: ");

                    again = false;
                }
                catch (string error)
                {
                    cin.clear();
                    cin.ignore();
                    redColor();
                    cout << error;
                    whiteColor();
                }
            }
            choice = stoi(input);


            if (choice == 1)
                updateMeaning(word, meaning);

            //as word was already present so it return false because the word was not inserted, even if the meaning was updated
            return false;
        }
    }
    //if word is not already present
    else
    {
        curr->isEndOfWord = true;
        curr->meaning = meaning;
        insertWordInFile(word, meaning);
        return true;
    }

}

//inserts word in File
void Dictionary::insertWordInFile(string word, string meaning)
{
    ofstream writeInFile;
    writeInFile.open("Dictionary.txt", ios::app);

    if (writeInFile.is_open())
        writeInFile << meaning << " " << word << endl;
    else
    {
        redColor();
        cout << "Can't Insert in Dictionary!\n";
        whiteColor();
    }

    writeInFile.close();
}

///-----------------------------------Search Functions-----------------------------------

//search the Node of word where EndOfWord is true
Node* Dictionary::searchNode(string word)
{
    Node* curr = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';

        if (!curr)
            return nullptr;

        //if character exist
        curr = curr->alphabets[index]; //search for next character

    }
    return curr;
}

//searches for Word and return's it's meaning if found 
string Dictionary::searchMeaning(string word)
{
    Node* curr = root;

    for (int i = 0; i < word.size(); i++) //loop each char in string
    {
        int index = word[i] - 'a';

        //if curr don't exist than return empty string
        if (!curr)
            return "";

        //if character exist
        curr = curr->alphabets[index]; //search for next character

    }
    //if the word is ending than return it's meaning
    if (curr && curr->isEndOfWord)
        return curr->meaning;
    else
        return "";
}

//searches for word and print it's meaning
void Dictionary::searchWordAndPrintMeaning(string word)
{
    lowerCaseString(word);

    string meaning = searchMeaning(word);

    //if meaning exists than prints it
    if (meaning != "")
    {
        cout << "\n----------------------\n";
        
        whiteColor();
        cout << word;
        cout << " : ";
        
        grayColor();
        cout << meaning;
        
        whiteColor();
        cout << "\n----------------------\n";
    }
    else
    {
        redColor();
        cout << "Word not Found\n";
    }
   
    whiteColor();

}

///-----------------------------------Update Function-----------------------------------

//updates meaning of the word, if word is not present than it asks to add it
void Dictionary::updateMeaning(string word, string newMeaning)
{
    lowerCaseString(word);
    lowerCaseString(newMeaning);

    Node* curr = searchNode(word);

    //if curr exist than update meaning
    if (curr && curr->isEndOfWord)
    {
        deleteWord(word);
        curr->meaning = newMeaning;
        insertWordInTree(word, newMeaning);

        greenColor();
        cout << word << "'s meaning updated!\n";
        whiteColor();

    }
    //if word is not found than asks to add it as new word
    else
    {
        int option;

        redColor();
        cout << word << " not Found!\n";
        whiteColor();

        cout << "Insert as new Word? No(0) Yes (1)\n";
        string input;
        bool again = true;
        while (again)
        {
            try
            {
                cin >> input;

                if (input.length() > 1)
                    throw string("Enter 1 char: ");

                if (!((input == "1") || (input == "0")))
                    throw string("Enter 1 or 0: ");

                again = false;
            }
            catch (string error)
            {
                cin.clear();
                cin.ignore();
                redColor();
                cout << error;
                whiteColor();
            }
        }
        option = stoi(input);

        if (option == 1)
            if (insertWordInTree(word, newMeaning))
            {
                greenColor();
                cout << word << " Inserted\n";
                whiteColor();
            }
        
    }
}

///---------------------------------Suggest Word Function---------------------------------
//prints 10 suggested words with same prefix
void Dictionary::suggestWord(string prefix)
{
    lowerCaseString(prefix);

    int count = 10;
    Node* curr = searchNode(prefix);

    suggestWord(curr, prefix, count);
}

//find the suggested word and prints it    
void Dictionary::suggestWord(Node* curr, string prefix, int& count)
{
    if (!curr)
    {
        redColor();
        cout << "No Suggestion";
        whiteColor();
        return;
    }

    //returns if count is 0
    if (count == 0)
        return;
    
    //if end of word is found print prefix and meaning
    if (curr->isEndOfWord)
    {
        cout << left << setw(15) << prefix << ": ";
       
        grayColor();
        cout << setw(10) << curr->meaning << endl;
        whiteColor();

        count--;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (curr->alphabets[i] != nullptr)
        {
            char ch = 'a' + i;
            suggestWord(curr->alphabets[i], prefix + ch, count);
        }
    }
}