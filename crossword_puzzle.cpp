//
//  crossword_puzzle.cpp
//
//  Created by omlenka on 21/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define CROSSWORD_ROW_MAX 10
#define CROSSWORD_COL_MAX 10

void printCrossword(vector<string> &crossword)
{
    for(int i = 0;i<CROSSWORD_ROW_MAX;i++)
    {
        for(int j = 0;j<CROSSWORD_COL_MAX;j++)
        {
            cout << crossword[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeHorizontal(vector<string> &crossword, int row, int col, string word)
{
    if(word.length() == 0)
        return false;
    bool res = false;
    string crossword_row = crossword[row];
    
    int index = 0;
    int j = col;
    
    while(index < word.length())
    {
        
        if(j < CROSSWORD_COL_MAX && crossword_row[j] != '+')
        {
            if(crossword_row[j] == word[index])
                index++;
            else if(crossword_row[j] == '-')
                crossword_row[j] = word[index++];
            else
                break;
            j++;
        }
        else
            break;
    }
    
    if(index == word.length())
    {
        if(j < CROSSWORD_COL_MAX && crossword[row][j] == '-')
            return false;
        
        res = true;
        crossword[row] = crossword_row;
    }
    return res;
}

bool placeVertical(vector<string> &crossword, int row, int col, string word)
{
    if(word.length() == 0)
        return false;
    
    bool res = false;
    string crossword_col;
    crossword_col.resize(CROSSWORD_ROW_MAX);
    int idx = 0;
    for(int i= 0;i<CROSSWORD_ROW_MAX;i++)
    {
        crossword_col[idx++] = crossword[i][col];
    }
    
    int index = 0;
    int i = row;
    
    while(index < word.length())
    {
        
        if(i < CROSSWORD_ROW_MAX && crossword_col[i] != '+')
        {
            if(crossword_col[i] == word[index])
                index++;
            else if(crossword_col[i] == '-')
                crossword_col[i] = word[index++];
            else
                break;
            i++;
        }
        else
            break;
    }
    
    if(index == word.length())
    {
        if(i < CROSSWORD_ROW_MAX && crossword[i][col] == '-')
            return false;
        
        res = true;
        idx = 0;
        for(int i= 0;i<CROSSWORD_ROW_MAX;i++)
        {
            crossword[i][col] = crossword_col[idx++];
        }
    }
    return res;
}

void removeFromList(vector<string> &word_list, string word)
{
    vector<string>::iterator itr = word_list.begin();
    while(itr != word_list.end())
    {
        if(*itr == word)
        {
            word_list.erase(itr );
            break;
        }
        itr++;
    }
}

bool crosswordPuzzle_util(vector<string> &crossword, int row, int col, vector<string> &word_list )
{
    if(row > CROSSWORD_ROW_MAX || col > CROSSWORD_COL_MAX)
        return false;
    
    if(word_list.empty())
        return true;
    
    for(int i = 0;i<CROSSWORD_ROW_MAX;i++)
    {
        for(int j = 0;j<CROSSWORD_COL_MAX;j++)
        {
            if(crossword[i][j] != '+')
            {
                for(string word : word_list)
                {
                    //Place Horizontal
                    string crossword_row = crossword[i];
                    bool hor = false;
//                    printCrossword(crossword);
                    hor = placeHorizontal(crossword, i, j, word);
                    if(hor)
                    {
//                        printCrossword(crossword);
                        removeFromList(word_list, word);
                        if(crosswordPuzzle_util(crossword, row, col, word_list) && word_list.empty())
                            return true;
                        
                        crossword[i] = crossword_row;
                        word_list.push_back(word);
                    }

                    //Place Vertical
                    string crossword_col;
                    crossword_col.resize(CROSSWORD_COL_MAX);
                    int idx = 0;
                    for(int i= 0;i<CROSSWORD_ROW_MAX;i++)
                    {
                        crossword_col[idx] = crossword[i][j];
                        idx++;
                    }
                    bool ver = placeVertical(crossword, i, j, word);
                    if(ver)
                    {
//                        printCrossword(crossword);
                        removeFromList(word_list, word);
                        
                        if(crosswordPuzzle_util(crossword, row, col, word_list) && word_list.empty())
                            return true;
                        
                        word_list.push_back(word);
                        
                        idx = 0;
                        for(int i= 0;i<CROSSWORD_ROW_MAX;i++)
                        {
                            crossword[i][j] = crossword_col[idx++];
                        }
                    }
                }
            }
        }
    }
    
    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words)
{
    vector<string> word_list;
    char *token = strtok(&words[0], ";");

    while(token != NULL)
    {
        word_list.push_back(token);
        token = strtok(NULL, ";");
    }

    crosswordPuzzle_util(crossword, 0, 0, word_list);
    return crossword;
}

int main()
{
    vector<string> crossword(10);
    
    for(int i = 0;i<10;i++)
        cin >> crossword[i];
    
    string words;
    cin >> words;
    
    vector<string> result = crosswordPuzzle(crossword, words);
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        
        if (i != result.size() - 1)
            cout << "\n";
    }
    
    return 0;
}
