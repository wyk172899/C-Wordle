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
	while (1) {
		Sleep(500);
		system("cls");
		printf("                           ....\n");
		printf("                      ?GGBB##&J\n");
		printf("                      J@@@@@@@B................\n");
		printf("                      ~@@@@@@@@&&################BBBBBBBBBBBBBBBBGGGGGGP.\n");
		printf("                      .&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#\n");
		printf("                       G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G\n");
		printf("                       Y@@@@@@@P:^^^^^^^^^^~~~~~~~!!!!!!!777777P@@@@@@@5\n");
		printf("                       !@@@@@@@G                               J@@@@@@@J\n");
		printf("                       :@@@@@@@&.                              5@@@@@@@7\n");
		printf("                        B@@@@@@@^                              P@@@@@@@!\n");
		printf("                        5@@@@@@@7                              G@@@@@@@^\n");
		printf("                        ?@@@@@@@5                              B@@@@@@&:\n");
		printf("                        ^@@@@@@@G         ......::::^^^~~~~!!!7&@@@@@@#.\n");
		printf("                        .#@@@@@@&PPGGGBBB#####&&&&&@@@@@@@@@@@@@@@@@@@G\n");
		printf("                         G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P\n");
		printf("                         J@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&####BBGGGPP555!\n");
		printf("                         ~#BBGGGPP55YYJJ???7P@@@@@@#^::....\n");
		printf("                                            7@@@@@@&.\n");
		printf("                                            ~@@@@@@@:\n");
		printf("            .:::::::^^^^^^^^^^^^^^~~~~~~~~~~7@@@@@@@J77????????JJJJJJJJJYYYYYYYY555Y.\n");
		printf("            5@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:\n");
		printf("            Y@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^\n");
		printf("            J@@@@@@@@@@@@@@&&&&&&&&&&&&#########BBBBBBBBBBBGGGGGGGGPPPPPPPPP5555555Y:\n");
		printf("            :~~^^^^^^^^^:::::::::::...........  ::\n");
		printf("                                              .?#&P7:\n");
		printf("                                            .?#@@@@@&P?:\n");
		printf("                                          .?#@@@@@@@@@P^\n");
		printf("                                        .?#@@@@@@@@&5^\n");
		printf("                                      .?#@@@@@@@@@&7\n");
		printf("                                    .?#@@@@@@@@@@@@&B57:\n");
		printf("                                  .?#@@@@@@@@@@@@@@@@@@@BY!:\n");
		printf("                                .?#@@@@@@@@&Y!5B@@@@@@@@@@@&GY!:\n");
		printf("                              .J#@@@@@@@@&Y:    ^?P#@@@@@@@@@@@&GJ~.\n");
		printf("                            .J#@@@@@@@@&Y:         .~JG&@@@@@@@@@@@#P?~.\n");
		printf("                          .J#@@@@@@@@&J:               :!5B@@@@@@@@@@@@#P?^.\n");
		printf("                        .J#@@@@@@@@&J:                     ^?P#@@@@@@@@@@@@B^\n");
		printf("                       ?&@@@@@@@@&J:                          .~JG&@@@@@@@B~\n");
		printf("                       ^Y#@@@@@#J.                                :!5B@@@Y.\n");
		printf("                         .!P@#J.                                      ^?!\n");
		printf("                            ^.\n");
		Sleep(500);
		system("cls");
		printf("           !PPPGGBB^                                               5BBGGGGY\n");
		printf("           !@@@@@@@~       ..................:::::::::.            G@@@@@@B\n");
		printf("           ^@@@@@@@#BBBBB#############&&&&&&&&&&&&&&&@!            B@@@@@@G\n");
		printf("           .&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@~            #@@@@@@G\n");
		printf("            B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@@@@@@@&:           .#@@@@@@P\n");
		printf("            P@@@@@@#777!!!!!~~~~~~^^^^^^^:::::#@@@@@@#.           .#@@@@@@P\n");
		printf("            Y@@@@@@#.                        .#@@@@@@G            :&@@@@@@P\n");
		printf("            7@@@@@@@^                        :&@@@@@@5            :&@@@@@@P\n");
		printf("            ~@@@@@@@7                        ^@@@@@@@?            :@@@@@@@5\n");
		printf("            :&@@@@@@J                        !@@@@@@@!            ^@@@@@@@G!!!!!!!!~~~~.\n");
		printf("            .#@@@@@@P                        ?@@@@@@@^            ^@@@@@@@@@@@@@@@@@@@@!\n");
		printf("             G@@@@@@#.                       J@@@@@@&:            ~@@@@@@@@@@@@@@@@@@@@^\n");
		printf("             5@@@@@@&:                       5@@@@@@B             !@@@@@@@&&&&&@@@@@@@&:\n");
		printf("             ?@@@@@@@~                       P@@@@@@G             !@@@@@@@7.:::::^^^^^^\n");
		printf("             !@@@@@@@?             ...::^^~~!#@@@@@@Y             7@@@@@@@~\n");
		printf("             ^@@@@@@@G7??JYY5PPGGBB##&&&@@@@@@@@@@@@?             ?@@@@@@@^\n");
		printf("             .&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@!             J@@@@@@@^\n");
		printf("              B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&##BBG:             J@@@@@@&:\n");
		printf("              P@@@@@@&&&##BBGPP55YJ??77!~~^^::...                 Y@@@@@@&:\n");
		printf("              ^!!~^^::...                                         5@@@@@@#\n");
		printf("                                     .7777777777777777777777777777B@@@@@@&?777?7\n");
		printf("                                     ^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&.\n");
		printf("                                     ^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&.\n");
		printf("                                     :PPPPPPPPPPPPP5G@@@@@@@@#PPPPPPPPPPPPPPPPP5.\n");
		printf("                                                   7#@@@@@@@G:\n");
		printf("                                                 ~B@@@@@@@@@&B5!:\n");
		printf("                                               ^P@@@@@@@@@@@@@@@&GJ~.\n");
		printf("                                             .Y&@@@@@@@55#@@@@@@@@@@#P7^\n");
		printf("                                            ?#@@@@@@@G~  .~YB@@@@@@@@@@@BY!:\n");
		printf("                                          !B@@@@@@@#7        ^?P&@@@@@@@@@@&GJ~.\n");
		printf("                                        ^P@@@@@@@&J.            .!5#@@@@@@@@@@@#P?.\n");
		printf("                                      .Y@@@@@@@@P:                  ^JG&@@@@@@@@@Y.\n");
		printf("                                    .?&@@@@@@@B~                       :75#@@@@&7\n");
		printf("                                    !B@@@@@@#?                            .~JBB^\n");
		printf("                                      :?G&@Y.\n");
		printf("                                         :^\n");
		Sleep(500);
		system("cls");
		printf("                         :!YGB7.\n");
		printf("                      :5#@@@@@@#?.\n");
		printf("                       ^5&@@@@@@@#?.\n");
		printf("                         :Y&@@@@@@@#?.\n");
		printf("            ~GGGGGGGGGGGGPP#@@@@@@@@@#PPPGGGGGGGGGGGGG?                5#BBBBBB:\n");
		printf("            7@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P                #@@@@@@&.\n");
		printf("            7@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P               .&@@@@@@B\n");
		printf("            ^YYYYYYYYYYYYJ5&@@@@@@@G?????????????????J!               ^@@@@@@@P\n");
		printf("                         7B@@@@@@@@BY7~:                              !@@@@@@@Y\n");
		printf("                      .7#@@@@@@@@@@@@@@@#G5?~:.                       ?@@@@@@@?\n");
		printf("                     7B@@@@@@@&&@@@@@@@@@@@@@@#GY?~:.                 Y@@@@@@@~\n");
		printf("                   !B@@@@@@@@5^.^7JPB&@@@@@@@@@@@@@&#GY?~:.           P@@@@@@@^\n");
		printf("                 !G@@@@@@@@P^        :~?5G#@@@@@@@@@@@@@@#^           B@@@@@@#.\n");
		printf("               ~G@@@@@@@@P~               .^!JPB&@@@@@@@G:           .&@@@@@@B\n");
		printf("             ~G@@@@@@@@G~                       :~7YG#&J             ^@@@@@@@P\n");
		printf("            !#@@@@@@@G~                               .              ~@@@@@@@J\n");
		printf("             .!5&@@B!. ....::::^^^~~~!!!777???JJYYY555PPPGGGB#7      ?@@@@@@@7\n");
		printf("      .JY55PPPPG#@@#B####&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y      Y@@@@@@@~\n");
		printf("      .&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5      P@@@@@@&:\n");
		printf("       B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&####BBBBGGPP555YYJJ!      B@@@@@@#.\n");
		printf("       5BBGGGPP555YYJJJ??777!!~J@@@@@@@5.:.....  ~BGGGPPP55YYJJJJJ???&@@@@@@G\n");
		printf("                               ^@@@@@@@P         ?@@@@@@@@@@@@@@@@@@@@@@@@@@5\n");
		printf("                               .&@@@@@@B         5@@@@@@@@@@@@@@@@@@@@@@@@@@J\n");
		printf("                                B@@@@@@&.       .?555PPPGGGBBBB#####&@@@@@@@!\n");
		printf("                                P@@@&&&&^      P&B5?~:.         ....G@@@@@@@^\n");
		printf("                                :^^::::.      P@@@@@@@P.           .#@@@@@@@B57\n");
		printf("                                            .P@@@@@@@B:             Y@@@@@@@@@!\n");
		printf("                                           .G@@@@@@@G.             :B@@@@@@@&~\n");
		printf("                                          .G@@@@@@@5              .B@@@@@@@&~\n");
		printf("                                         .G@@@@@@@@57^.          .B@@@@@@@&~\n");
		printf("                                        .G@@@@@@@@@@@@#PJ~:     .G@@@@@@@@J\n");
		printf("                                       .G@@@@@@@@@@@@@@@@@&GY7:.P@@@@@@@@@@#P?~.\n");
		printf("                                      .B@@@@@@@#P#@@@@@@@@@@@@@#@@@@@@@@@@@@@@@#P?~.\n");
		printf("                                     :B@@@@@@@B: .^75B&@@@@@@@@@@@@@@@&&@@@@@@@@@@@#P?^.\n");
		printf("                                    :B@@@@@@@B:       :!JP#@@@@@@@@@@B:.!YB&@@@@@@@@@@@#P?~\n");
		printf("                                   :B@@@@@@@G.             !&@@@@@@@B:     :75#@@@@@@@@@@@5\n");
		printf("                                  :B@@@@@@@P.             :B@@@@@@@G.         .^?P#@@@@@@5\n");
		printf("                                 :#@@@@@@@P              ~#@@@@@@@P.              .~JG&@Y\n");
		printf("                                 .!?5B&@@5              !@@@@@@@@P                    :~\n");
		printf("                                      .^!               ~YG&@@@@5.\n");
		printf("                                                           :!JGY");
		Sleep(500);
		system("cls");
		printf("                   .........................................................\n");
		printf("                  ^#########################################################G.\n");
		printf("                  ^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.\n");
		printf("                  ^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&.\n");
		printf("                  :55555555555555555555B@@@@@@@@@&P5555555555555555555555555Y.\n");
		printf("                                      ?#@@@@@@@@P^\n");
		printf("                                    ~B@@@@@@@@#!\n");
		printf("                                  :5@@@@@@@@@@&PJ~.\n");
		printf("                                 ?&@@@@@@@@@@@@@@@#P?^.\n");
		printf("                               ~G@@@@@@@@@@@@@@@@@@@@@#P7^\n");
		printf("                             .Y@@@@@@@@@5^~YB&@@@@@@@@@@@@B57:\n");
		printf("                            7#@@@@@@@@B~     :75#@@@@@@@@@@@@&BY!:\n");
		printf("                          ^G@@@@@@@@&J.         .^?P&@@@@@@@@@@@@&GJ~.\n");
		printf("                        .J@@@@@@@@@P^               .~JG&@@@@@@@@@@@@&GJ~.\n");
		printf("                       !#@@@@@@@@#!                     :75#@@@@@@@@@@@@@#P?^.\n");
		printf("                     :P@@@@@@@@@Y.                         .^?P&@@@@@@@@@@@@@#P7^.\n");
		printf("                    ?&@@@@@@@@G^                               .~JG&@@@@@@@@@@@@@P.\n");
		printf("                  ~B@@@@@@@@&7:7?JJYY5P^                 !GPPPP55Y^:75#@@@@@@@@@P.\n");
		printf("                :5@@@@@@@@@5: ~@@@@@@@@7                 J@@@@@@@@~    ^?P#@@@&?\n");
		printf("               ^B@@@@@@@@B~   :@@@@@@@@7                 Y@@@@@@@@^       .~YP^\n");
		printf("                :!5&@@@&J.    .&@@@@@@@?                 5@@@@@@@&:\n");
		printf("                   .!PP^      .#@@@@@@@J                 P@@@@@@@#.\n");
		printf("                               B@@@@@@@Y                 G@@@@@@@B\n");
		printf("                               G@@@@@@@5                 B@@@@@@@G\n");
		printf("                               5@@@@@@@P                 B@@@@@@@5\n");
		printf("                               Y@@@@@@@G                .#@@@@@@@Y\n");
		printf("                               ?@@@@@@@B                .&@@@@@@@?\n");
		printf("                    ...........?@@@@@@@#::::^^^^^^^~~~~~7&@@@@@@@5?????JJJJJJYYYYYYY55555^\n");
		printf("        .GBBBBBBBBB#########&&&&@@@@@@@@&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@!\n");
		printf("        .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@7\n");
		printf("         G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&7\n");
		printf("         Y#BBBBBGGGGGGGPPPPPP555555YYYYYYJJJJJJ??????77777!!!!!!~~~~~~^^^^^^^^^::::::::...\n");
		Sleep(500);
		system("cls");
		printf("                       .!!~^^::..\n");
		printf("                       !@@@@@&&&##BGGP55YJ?77!~~^^:...\n");
		printf("                       Y@@@@@@@@@@@@@@@@@@@@@@@@@@&&##BBGPP5YJJ?7!!~^^::..\n");
		printf("                       B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&##BGGPPJ\n");
		printf("                       ^~!!7?JYY5PGGB##&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J\n");
		printf("                                     ...::^~~!7?JJY5PPGBB#&&&@@@@@@@@@@@@@@@@@@&:\n");
		printf("                                                         ..::^^~!77?JYG@@@@@@@@P\n");
		printf("                                                                      5@@@@@@@@!\n");
		printf("                                                                     :&@@@@@@@B\n");
		printf("                                                                     ?@@@@@@@@J\n");
		printf("                  :!!~~~~^^^^^:::::.......                           B@@@@@@@&:\n");
		printf("                  Y@@@@@@@@@@@@&&&&&&&#####BBBBGGGGPPPPP555YYYYJJJ??J@@@@@@@@P\n");
		printf("                  P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@!\n");
		printf("                  B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.\n");
		printf("                  7JJJJYYYY5555PPPPGGGGBBBBB#####&&&&&&&@@@@@@@@@@@@@@@@@@@@J\n");
		printf("                                             .......:::::^^^^^~~~~!#@@@@@@@&:\n");
		printf("                                                                  ^@@@@@@@@P\n");
		printf("                                                                  Y@@@@@@@@!\n");
		printf("                                                                 .#@@@@@@@#.\n");
		printf("                                                                 7@@@@@@@@J\n");
		printf("                                                                 G@@@@@@@@^\n");
		printf("                                                                ^@@@@@@@@P\n");
		printf("                                                                J@@@@@@@@!\n");
		printf("                                                               .#@@@@@@@#.\n");
		printf("                                                               .~!?J5PB#J\n");
		printf("                                                                       .\n");
	}
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