#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//메뉴 정보 구조체
typedef struct _MENU {
	char drink[30];
	char price[30];
}MENU;

//고객 정보 구조체
typedef struct _customer {
	char name[30];
	char phone[30];
}CUSTOMER;

//번호표 구조체
typedef struct _ticket_number {
	char number[30];
	char name[30];
	char drink[30];
	char price[30];
}TICKET_NUMBER;

//함수
void new_add_menu();           //메뉴 추가 
void new_add_customer();	   //고객 추가 

int search_menu();				//메뉴 검색 
int search_customer();			//고객 검색 
int search_ticket_number();		//번호표 검색 

void edit_customer();			//고객 수정 
void edit_menu();				//메뉴 수정 

void del_customer();			//고객 삭제 
void del_menu();				//메뉴 삭제 

void view_menu();				//메뉴 전체 보기 
void view_customer();			//고객정보 전체 보기 

void end();						//끝내기 

void input_menu();             //호출했을 떄 정보를 전부 구조체에 담는 함수
void input_customer();
void input_ticket_number();

void SetTextColor(int background, int text) // UI
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background<<4) | text);
	//배경색인 background를 4비트 앞으로 보내고, text와 더하여 적용
}

//구조체 배열 전역변수 선언
MENU menu_info[200];
int menu_idx=0;        //메뉴 정보 카운팅

CUSTOMER customer_info[200];
int customer_idx=0;        //고객 정보 카운팅

TICKET_NUMBER ticket_number_info[200];
int ticket_number_idx=0;        //번호표 정보 카운팅


int main()				//메인화면
{
	int i, sel=1, idx;
	input_menu();
	input_customer();
	input_ticket_number();

	SetTextColor(15, 0); //15: 흰색, 0: 검은색

	while(sel!=10)
	{
		system("cls"); //화면지우기
		printf("============================\n");
		printf("|     카페 관리 프로그램    |\n");
		printf("============추가============\n");
		printf("|  1. 신규 메뉴 추가        |\n");
		printf("|  2. 신규 고객 추가        |\n");
		printf("============검색============\n");
		printf("|  3. 기존 메뉴 검색        |\n");
		printf("|  4. 기존 고객 검색        |\n");
		printf("|  5. 번호표 검색           |\n");
		printf("============삭제============\n");
		printf("|  6. 기존 고객 삭제        |\n");
		printf("|  7. 기존 메뉴 삭제        |\n");
		printf("==========전체 보기=========\n");
		printf("|  8. 메뉴 전체 보기        |\n");
		printf("|  9. 고객 전체 보기        |\n");
		printf("============종료============\n");
		printf("|  10. 프로그램 종료        |\n");
		printf("============================\n");
		printf("  원하는 메뉴를 선택하세요: ");

		scanf("%d", &sel) ;

switch(sel)
		{
		case 1:
			new_customer();
			break;
		case 2:
			idx=search_customer();
			if(idx==1)
				printf("찾으시는 정보가 없습니다.\n");
			else
			{
				printf("%s	%s	%s\n", customer_info[idx].name, customer_info[idx].size, customer_info[idx].phone);
			}
			break;
		case 3:
			new_add();
			break;
		case 4:
			idx=search_type();
			if(idx==-1)
				printf("찾으시는 정보가 없습니다.\n");
			else
			{
				printf("%s	%s	%s  %s\n",clothes_info[idx].brand, clothes_info[idx].type, clothes_info[idx].size, clothes_info[idx].color);
			}
			break;
		case 5:
			idx=search_brand();
			if(idx==-1)
				printf("찾으시는 정보가 없습니다.\n");
			else
			{
				printf("%s	%s	%s  %s\n",clothes_info[idx].brand, clothes_info[idx].type, clothes_info[idx].size, clothes_info[idx].color);
			}
			break;
		case 6:
			edit();
			break;
		case 7:
			del();
			break;
		case 8:
			view_clothes();
			break;
        case 9:
			view_customer();
			break;
		case 10:
			end();
			break;
		default:
			printf("\n잘못 선택하셨습니다.\n");
			break;
		}
		printf("\n작업을 완료하였습니다.\n새로운 메뉴를 선택하려면 Enter를 눌러주세요.\n");
		getch(); // 항목 입력 받기 대기 -> 엔터치면 새롭게 항복 선택 가능
	}
	return 0;
}











