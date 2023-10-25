#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct WordNode_struct {
    char* myWord;
    struct WordNode_struct* next;
} WordNode;

typedef struct LadderNode_struct {
    WordNode* topWord;
    struct LadderNode_struct* next;
} LadderNode;

int countWordsOfLength(char* filename, int wordSize) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    int count = 0;
    char line[100];
    while (fgets(line, 100, file)) {
        strtok(line, "\n"); // removes newline character
        if (strlen(line) == wordSize) {
            count++;
        }
    }
    fclose(file);

    return count;
}

bool buildWordArray(char* filename, char** words, int numWords, int wordSize) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    int count = 0;
    char line[100];
    while (fgets(line, 100, file)) {
        strtok(line, "\n"); // removes newline character
        if (strlen(line) == wordSize) {
            line[wordSize] = '\0'; // adds null character to end
            strcpy(words[count], line);
            count++;
        }
    }
    fclose(file);

    if (count != numWords) {
        return false;
    }
    return true;
}

int findWord(char** words, char* aWord, int loInd, int hiInd) {
    while (loInd <= hiInd) {
        int mid = (loInd + hiInd) / 2;
        
        // aWord found at mid
        if (strcmp(aWord, words[mid]) == 0) {
            return mid;
        }

        if (strcmp(aWord, words[mid]) > 0) {
            loInd = mid+1; // ignore left half
        }
        else {
            hiInd = mid-1; // ignore right half
        }
    }
    return -1; // not found
}

void freeWords(char** words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
}

void insertWordAtFront(WordNode** ladder, char* newWord) {
    //---------------------------------------------------------
    // TODO - write insertWordAtFront()
    //          allocate space for a new [WordNode], set its
    //          [myWord] subitem using <newWord> and insert
    //          it to the front of <ladder>, which is a
    //          pointer-passed-by-pointer as the head node of
    //          ladder changes inside this function;
    //          <newWord> is a pointer to a C-string from the
    //          full word array, already heap-allocated
    //---------------------------------------------------------
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    strcpy(newNode->myWord, newWord);
    newNode->next = (*ladder);
}

int getLadderHeight(WordNode* ladder) {
    //---------------------------------------------------------
    // TODO - write getLadderHeight()
    //          find & return number of words in <ladder> list
    //---------------------------------------------------------
    int count = 0;
    WordNode* curr = ladder;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

WordNode* copyLadder(WordNode* ladder) {
    //---------------------------------------------------------
    // TODO - write copyLadder()
    //          make a complete copy of <ladder> and return it;
    //          the copy ladder must have new space allocated
    //          for each [WordNode] in <ladder>, BUT the
    //          C-string pointers to elements of the full word
    //          array can be reused; i.e. the actual words do
    //          NOT need another allocation here
    //---------------------------------------------------------
    return NULL; //modify this
}

void freeLadder(WordNode* ladder) {
    //---------------------------------------------------------
    // TODO - write freeLadder()
    //          free up all heap-allocated space for <ladder>;
    //          this does NOT include the actual words,
    //          instead just free up the space that was
    //          allocated for each [WordNode]
    //---------------------------------------------------------
    WordNode* curr = ladder;
    while (curr) {
        WordNode* temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void insertLadderAtBack(LadderNode** list, WordNode* newLadder) {
    //---------------------------------------------------------
    // TODO - write insertLadderAtBack()
    //          allocate space for a new [LadderNode], set its
    //          [topWord] subitem using <newLadder>; then, find
    //          the back of <list> and append the newly created
    //          [LadderNode] to the back; Note that <list> is a
    //          pointer-passed-by-pointer, since this function
    //          must handle the edge case where <list> is empty
    //          and the new [LadderNode] becomes the head node
    //---------------------------------------------------------
}

WordNode* popLadderFromFront(LadderNode** list) {
    //---------------------------------------------------------
    // TODO - write popLadderFromFront()
    //          pop the first Ladder from the front of the list
    //          by returning the pointer to the head node
    //          of <list> AND updating the head node of <list>
    //          to the next [LadderNode]; Note that <list> is a
    //          pointer-passed-by-pointer, since this function
    //          updates the head node to be one down the list;
    //          the [LadderNode] popped off the front must have
    //          its memory freed in this function, since it
    //          will go out of scope, but the ladder itself,
    //          i.e. the head [WordNode], should NOT be freed.
    //---------------------------------------------------------
    return NULL; //modify this
}

void freeLadderList(LadderNode* myList) {
    //---------------------------------------------------------
    // TODO - write freeLadderList()
    //          free up all heap-allocated space for <myList>;
    //          for each ladder in <myList>:
    //           - free the space allocated for each [WordNode]
    //                  in the ladder using freeLadder()
    //           - then, free the space allocated for the
    //                  [LadderNode] itself
    //---------------------------------------------------------
}

WordNode* findShortestWordLadder(   char** words,
                                    bool* usedWord,
                                    int numWords,
                                    int wordSize,
                                    char* startWord,
                                    char* finalWord ) {
    //---------------------------------------------------------
    // TODO - write findShortestWordLadder()
    //          run algorithm to find the shortest word ladder
    //          from <startWord> to <finalWord> in the <words>
    //          word array, where each word is <wordSize> long
    //          and there are <numWords> total words;
    //          <usedWord> also has size <numWords>, such that
    //          usedWord[i] is only true if words[i] has
    //          previously be entered into a ladder, and should
    //          therefore not be added to any other ladders;
    //          the algorithm creates partial word ladders,
    //          which are [WordNode] linked lists, and stores
    //          them in a [LadderNode] linked list.
    //              return a pointer to the shortest ladder;
    //              return NULL if no ladder is possible;
    //                  before return, free all heap-allocated
    //                  memory that is created here that is not
    //                  the returned ladder
    //---------------------------------------------------------


    return NULL;
}

// interactive user-input to set a word;
//  ensures sure the word is in the dictionary word array
void setWord(char** words, int numWords, int wordSize, char* aWord) {
    bool valid = false;
    printf("  Enter a %d-letter word: ", wordSize);
    int count = 0;
    while (!valid) {
        scanf("%s",aWord);
        count++;
        valid = (strlen(aWord) == wordSize);
        if (valid) {
            int wordInd = findWord(words, aWord, 0, numWords-1);
            if (wordInd < 0) {
                valid = false;
                printf("    Entered word %s is not in the dictionary.\n",aWord);
                printf("  Enter a %d-letter word: ", wordSize);
            }
        } else {
            printf("    Entered word %s is not a valid %d-letter word.\n",aWord,wordSize);
            printf("  Enter a %d-letter word: ", wordSize);
        }
        if (!valid && count >= 5) { //too many tries, picking random word
            printf("\n");
            printf("  Picking a random word for you...\n");
            strcpy(aWord,words[rand()%numWords]);
            printf("  Your word is: %s\n",aWord);
            valid = true;
        }
    }
}

// helpful debugging function to print a single Ladder
void printLadder(WordNode* ladder) {
    WordNode* currNode = ladder;
    while (currNode != NULL) {
        printf("\t\t\t%s\n",currNode->myWord);
        currNode = currNode->next;
    }
}

// helpful debugging function to print the entire list of Ladders
void printList(LadderNode* list) {
    printf("\n");
    printf("Printing the full list of ladders:\n");
    LadderNode* currList = list;
    while (currList != NULL) {
        printf("  Printing a ladder:\n");
        printLadder(currList->topWord);
        currList = currList->next;
    }
    printf("\n");
}


//-----------------------------------------------------
// The primary application is fully provided in main();
//  no changes should be made to main()
//-----------------------------------------------------
int main() {
    srand((int)time(0));

    printf("\nWelcome to the CS 211 Word Ladder Generator!\n\n");

    // set word length using interactive user-input
    int wordSize;
    printf("Enter the word size for the ladder: ");
    scanf("%d",&wordSize);
    printf("\n");

    printf("This program will make the shortest possible\n");
    printf("word ladder between two %d-letter words.\n\n",wordSize);

    // interactive user-input sets the dictionary file;
    //  check that file exists; if not, user enters another file
    //  if file exists, count #words of desired length [wordSize]
    char dict[100];
    printf("Enter filename for dictionary: ");
    scanf("%s", dict);
    printf("\n");
    int numWords = countWordsOfLength(dict,wordSize);
    while (numWords < 0) {
        printf("  Dictionary %s not found...\n",dict);
        printf("Enter filename for dictionary: ");
        scanf("%s", dict);
        printf("\n");
        numWords = countWordsOfLength(dict,wordSize);
    }

    // allocate heap memory for the word array; only words with desired length
    char** words = (char**)malloc(numWords*sizeof(char*));
    for (int i = 0; i < numWords; ++i) {
        words[i] = (char*)malloc((wordSize+1)*sizeof(char));
    }

    // end program if file does not have at least two words of desired length
    if (numWords < 2) {
        printf("  Dictionary %s contains insufficient %d-letter words...\n",dict,wordSize);
        printf("Terminating program...\n");
        return -1;
    }

    // [usedWord] bool array has same size as word array [words];
    //  all elements initialized to [false];
    //  later, usedWord[i] will be set to [true] whenever
    //      words[i] is added to ANY partial word ladder;
    //      before adding words[i] to another word ladder,
    //      check for previous usage with usedWord[i]
    bool* usedWord = (bool*)malloc(numWords*sizeof(bool));
    for (int i = 0; i < numWords; ++i) {
        usedWord[i] = false;
    }

    // build word array (only words with desired length) from dictionary file
    printf("Building array of %d-letter words... ", wordSize);
    bool status = buildWordArray(dict,words,numWords,wordSize);
    if (!status) {
        printf("  ERROR in building word array.\n");
        printf("  File not found or incorrect number of %d-letter words.\n",wordSize);
        printf("Terminating program...\n");
        return -1;
    }
    printf("Done!\n");

    // set the two ends of the word ladder using interactive user-input
    //  make sure start and final words are in the word array,
    //  have the correct length (implicit by checking word array), AND
    //  that the two words are not the same
    char startWord[30];
    char finalWord[30];
    printf("Setting the start %d-letter word... \n", wordSize);
    setWord(words, numWords, wordSize, startWord);
    printf("\n");
    printf("Setting the final %d-letter word... \n", wordSize);
    setWord(words, numWords, wordSize, finalWord);
    while (strcmp(finalWord,startWord) == 0) {
        printf("  The final word cannot be the same as the start word (%s).\n",startWord);
        printf("Setting the final %d-letter word... \n", wordSize);
        setWord(words, numWords, wordSize, finalWord);
    }
    printf("\n");

    // run the algorithm to find the shortest word ladder
    WordNode* myLadder = findShortestWordLadder(words, usedWord, numWords, wordSize, startWord, finalWord);

    // display word ladder and its height if one was found
    if (myLadder == NULL) {
        printf("There is no possible word ladder from %s to %s\n",startWord,finalWord);
    } else {
        printf("Shortest Word Ladder found!\n");
        printLadder(myLadder);
    }
    printf("Word Ladder height = %d\n",getLadderHeight(myLadder));

    // free the heap-allocated memory for the shortest ladder
    freeLadder(myLadder);
    // free the heap-allocated memory for the words array
    freeWords(words,numWords);
    free(usedWord);

    return 0;
}
