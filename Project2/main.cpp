#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM_OF_WORDS 2500
char input_clear[6][6];
int prc=0;
char afprocess[6][6];
char title[7] = { "WORDLE" };
int* Pprc = &prc;
//판별
bool processGuess(const char* theAnswer, const char theGuess[]) {
	
	
	//the clue
	char clue[6] = { 'F', 'F', 'F', 'F', 'F', '\0' };
	//a set of flags indicating if that letter in the answer is used as clue
	bool answerFlags[5] = { false, false, false, false, false };

	//T구분
	for (int i = 0; i < 5; i++) {
		if (theGuess[i] == theAnswer[i]) {
			clue[i] = 'T';
			answerFlags[i] = true;
		}
	}

	//S구분
	for (int i = 0; i < 5; i++) {
		if (clue[i] == 'F') {//means no exact match from first pass
			for (int j = 0; j < 5; j++) {
				if (theGuess[i] == theAnswer[j] && !answerFlags[j]) {
					//a match at another position and has not been used as clue
					clue[i] = 'S';
					answerFlags[j] = true;
					break; //end this j-loop because we don't want multiple clues from the same letter
				}
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		afprocess[*Pprc][i] = clue[i];
	}
	
	printf("%s\n\n", clue);
	return strcmp(clue, "TTTTT") == 0; //if match strcmp returns 0
}


//문자열 길이
int cus_strlen(char* string) { 
	int cnt = 0;
	while (string[cnt] != '\0') {
		++cnt; 
	}
	return cnt;
}

void give_up() {
	system("mode con cols=120 lines=40");
	printf("저런.. 맞추지 못했어요");
}

//시작할때 촤라라락
void titleprint() {
	for (int i = 0; i < 6; i++) {
		printf("\t\t");
		for (int j = 1; j <= 15; j++) {
			printf("%c", title[i]);
			Sleep(1);
		}
		printf("\n");
	}
}

//입력 다섯글자아닐때 한줄 지워줌
void wordClear(int x) {
	Sleep(1000);
	system("cls");
	printf("\tWORDLE\n");
	for (int i = 0; i < x; i++) {
		printf("%s\n", input_clear[i]);
		printf("%s\n\n", afprocess[i]);
	}
}


int main()
{
	system("mode con cols=55 lines=7");
	int i=0, j, correct = 0;

	//정답불러오기
	char** wordsList = (char**)calloc(MAX_NUM_OF_WORDS, sizeof(char*));
	int wordCount = 0;
	char* fiveLetterWord = (char*)malloc(6 * sizeof(char));
	FILE* wordsFile = fopen("wordlist.txt", "r");
	if (wordsFile == NULL) {
		printf("0");
		return 0;
	}
	while (fscanf(wordsFile, "%s", fiveLetterWord) != EOF && wordCount < MAX_NUM_OF_WORDS) {
		wordsList[wordCount] = fiveLetterWord;
		wordCount++;
		fiveLetterWord = (char*)malloc(6 * sizeof(char));
	}
	fclose(wordsFile);

	//랜덤수 생성
	srand(time(NULL));
	char* answer = wordsList[rand() % wordCount];
	
	//char* answer = wordsList[rand()%wordCount];

	//질문횟수, 정답여부
	int num_of_guesses = 0;
	bool guessed_correctly = false;
	char input[6];
	//memset(input, , 6 * sizeof(char)); //변수명, 초기화할 내용, 용량
	
	titleprint();
	Sleep(100);
	system("cls");

	printf("\t간단한 설명\n");
	printf("알파벳이 정답에 포함되지 않을 경우:F (false)\n");
	printf("알파벳이 정답에 포함되지만 위치가 다를 경우:S (similar)\n");
	printf("알파벳이 정답에 포함되고 위치도 맞을 경우:T (true)\n");
	printf("\nGG 입력 시 포기");

	Sleep(3000);
	system("mode con cols=25 lines=22");
	system("cls");
	printf("\tWORDLE\n");
	while ((*Pprc)<6&&!guessed_correctly) {
		//입력된게 다섯글자가 아닌경우 다시 물어봄
		while (1) {
			scanf("%s", &input);
			if ((!strcmp(input, "gg"))||(!strcmp(input, "GG"))) {
				printf("\n정답은 %s\n", answer);
				Sleep(3000);
				give_up();
			}
			else if (strlen(input)==5) {
				break;
			}
			else{
				printf("다섯글자를 입력해주세요\n");
				wordClear(prc);
			}
		}

		//다섯글자 입력이 되지않았을때 지우고 다시 출력할거
		for (j = 0; j < 5; j++) {
			input_clear[prc][j] = input[j];
		}

		//소문자 입려되면 대문자로 변환
		for (j = 0; j < 5; j++) {
			if (input[j] <= 'z' && input[j] >= 'a') {
				input[j] -= 32;
			}
		}
		
		//판별결과
		guessed_correctly = processGuess(answer, input);
		(*Pprc)++;
	}
	if (guessed_correctly) {
		printf("정답입니다! %d번만에 맞추셨네요!!\n", prc);
	}
	else {
		printf("\n정답은 %s 이였습니다..", answer);
	}

	//할당한 메모리 해제
	for (int i = 0; i < wordCount; i++) {
		free(wordsList[i]);
	}
	free(wordsList);
	free(fiveLetterWord);
	return 0;
}
