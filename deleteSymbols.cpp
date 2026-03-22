#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Дана строка. Удалить слова со M по N

string deleteWords(string text, int m, int n)
{
    if (m > n || m <= 0 || n <= 0)
    {
        throw invalid_argument("Вы ввели неправильные индексы начального и конечного слов");
    }
    if (text.empty())
    {
        throw invalid_argument("Вы ввели пустую строку");
    }

    int wordsCount = 0;
    bool flag = false;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            if (!flag)
            {
                wordsCount++;
                flag = true;
            }
        }
        else
        {
            flag = false;
        }
    }

    if (m > wordsCount || n > wordsCount)
    {
        throw out_of_range("Вы ввели такие индексы слов, что они выходят за пределы строки");
    }

    int wordIndex = 1;
    string currentWord;
    string result;

    for (int i = 0; i <= text.length(); i++)
    {
        if (i < text.length() && text[i] != ' ')
        {
            currentWord += text[i];
        }
        else
        {
            if (!currentWord.empty())
            {
                if (wordIndex < m || wordIndex > n)
                {
                    if (!result.empty())
                    {
                        result += ' ';
                    }
                    result += currentWord;
                }
                wordIndex++;
                currentWord.clear();
            }
        }
    }
    return result;
}

int main()
{
    string sentence;
    int startWord, endWord;

    getline(cin, sentence);
    cin >> startWord >> endWord;

    try
    {
        cout << deleteWords(sentence, startWord, endWord);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}