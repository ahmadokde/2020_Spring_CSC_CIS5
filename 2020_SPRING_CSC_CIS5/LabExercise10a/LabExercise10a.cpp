/*
 * Redaction is the removal of sensitive words in a document with 
 * unidentifiable markings that prevent the orignal word from being known.
 * This is a practice commonly used to render classfied documents as 
 * unclassfied ("clean" or "sanistized") documents.
 *
 */

/* 
 * File:   LabExercise10a.cpp
 * Author: Ahmad okde
 * Created on June 2, 2020
 */

/* Place Library References Here */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
 * Put function definitions below
 */

 /*
  * Function: openDataFile
  * Description: Open data file and return status
  * ('true' = file is open)
  */
bool openDataFile(ifstream& stream, string prompt) {
    string filename;
    cout << prompt;
    cin >> filename;
    stream.open(filename);
    return stream.is_open();
}

/* Function: readWordList
 * Descrition: Read list of words form file
 * Returns: actual number of dirty words, up to max size
 * Parameters:
 *   ifstream stream - open input file object
 *   int size - max size of wordist
 *   string wordList - list into which words will be stored
 */
int readWordList(ifstream& stream, int size, string wordList[]) {
    string word;
    for (int i = 0; i < size; i++) {
        getline(stream, word);
        if (stream.eof())
            // end of file, return count
            return i;
        wordList[i] = word;
    }
    return size;
}

/*Function to convert string to lower case*/
string toLowerCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
/*
 * Function: scrubIt
 * Description: given dirty word list and input string,
 *              replace the words n the dirty word list
 *              with asterisks
 * Parameters:
 *    string array of dirty words
 *    dirty word count
 *    string to scrub
 *    replacement string
 */
void scrubIt(string dirtyWordList[], int size, string& line, string replacement) {

    /// Add code here to redact sesitive text using dirty word list
    for (int i = 0; i < size; i++)
    {
        //find index of dirtyWordList word
        size_t found = toLowerCase(line).find(toLowerCase(dirtyWordList[i]));
        if (found != string::npos)
        {
            //replace 
            line.replace(found, dirtyWordList[i].length(), replacement);
        }
    }
}


/*
 * Main Program
 * Description: <describe what main program does>
 */
int main() {

    const string REPLACEMENT_TEXT = "[redacted]";

    /**********************************************************************************************
     *
     * Read dirty word list
     *
     */
    const int MAXSIZE = 100;
    string dirtyWords[MAXSIZE];

    // declare input stream
    ifstream textInput;

    // Open input file
    while (!openDataFile(textInput, "What is the name of the textfile containing the sensitive word list? "))
        cout << "File failed to open." << endl;

    // Acknowledgd file is open
    cout << "Sensitive word file is open.\n";

    int dirtyWordListSize = readWordList(textInput, MAXSIZE, dirtyWords);

    textInput.close();

    // Display dirty words 
    cout << "These are the " << dirtyWordListSize << " words or phrases to be scrubbed:\n" << endl;
    for (int i = 0; i < dirtyWordListSize; i++) {
        cout << dirtyWords[i] << endl;
    }
    cout << endl;


    /**********************************************************************************************
     *
     * Open sensitive text file
     *
     */
     // Open input file
    while (!openDataFile(textInput, "What is the name of the textfile you wish to sanitize? "))
        cout << "File failed to open." << endl;

    // Acknowledg file is open
    cout << "Text file is open.\n";


    /**********************************************************************************************
     *
     * Process sensitive text
     *
     */
    string inputLine;

    // Read initial line from input file
    getline(textInput, inputLine);

    while (!textInput.eof()) {

        // Scrub input line using dirty word list
        scrubIt(dirtyWords, dirtyWordListSize, inputLine, REPLACEMENT_TEXT);

        // output scrubbed inputLine
        cout << inputLine << endl;

        // read next line from input file
        getline(textInput, inputLine);
    }

    textInput.close();

    return 0;

}