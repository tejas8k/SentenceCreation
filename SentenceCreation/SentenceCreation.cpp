#include <cassert>
#include <conio.h>

#include <iostream>

#include "DynamicArray.h"

char* readWords() {
	const int value = 20;

	char arr_letter[value];
	size_t wordLength = 0;
	while (wordLength <= value) {

		char _char;
		_char = std::getchar();
		if (_char != '\n' && _char != '\0') 
		{
			arr_letter[wordLength++] = _char;
		}
		else 
			break;
	}

	if (wordLength == 0) 
		return nullptr;

	wordLength++;
	char* _str = new char[wordLength];

	int index = 0;
	while (index < wordLength)
	{		
		_str[index] = arr_letter[index];
		index++;
	}

	//Last input as empty space
	_str[wordLength - 1] = '\0';
	return _str;
}

int len(const char* string) {
	int length = 0;

	for (int i = 0; string[i] != '\n' && string[i] != '\0'; i++)
	{
		length++;
	}

	return length;
}

char* MakeSentence(char** arr) {
	int totalLength = 0;
	for (int i = 0;  ; i++) {
		const char* word = arr[i];

		if (word == nullptr) 
			break;
		totalLength += (len(word) + 1);
	}
	totalLength++;

	char* _str = static_cast<char*>(malloc(totalLength * sizeof(char)));
	assert(_str);
	_str[totalLength - 1] = '\0';

	int currIndex = 0;
	for (int i = 0;; i++) {
		const char* word = arr[i];
		if (word == nullptr)
			break;

		for (int i = currIndex; i < currIndex + len(word) && i<totalLength; i++)
		{
			_str[i] = word[i - currIndex];
		}

		currIndex += len(word);
		delete[] word;
		_str[currIndex++] = ' ';
	}
	if (currIndex > 0) 
		_str[currIndex - 1] = '.';
	return _str;
}

void RunMakeSentence() {
	DynamicStringArray words;

	char* thisWord;
	do {
		std::cout << "Enter a word, pass empty string to finish : ";
		thisWord = readWords();
		words.push_back(thisWord);
	} while (thisWord != nullptr);

	int wordSize = words.Size();

	char** wordsArray = new char* [wordSize];
	for (size_t i = 0; i < wordSize; i++) {
		wordsArray[i] = words[i];
	}
	std::cout << std::endl;
	char* pSentence = MakeSentence(wordsArray);
	printf("Your Sentence is: %s\n", pSentence);

	delete[] wordsArray;
	free(pSentence);
}

int main()
{
	//_CrtSetBreakAlloc(171);
	RunMakeSentence();

#if defined(_DEBUG)
	_CrtDumpMemoryLeaks();
#endif // _DEBUG
}

