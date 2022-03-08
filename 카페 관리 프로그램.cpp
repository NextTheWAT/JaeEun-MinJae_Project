#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//�޴� ���� ����ü
typedef struct _MENU {
	char drink[30];
	char price[30];
}MENU;

//�� ���� ����ü
typedef struct _customer {
	char name[30];
	char phone[30];
}CUSTOMER;

//��ȣǥ ����ü
typedef struct _ticket_number {
	char number[30];
	char name[30];
	char drink[30];
	char price[30];
}TICKET_NUMBER;

//�Լ�
void new_add_menu();           //�޴� �߰� 
void new_add_customer();	   //�� �߰� 

int search_menu();				//�޴� �˻� 
int search_customer();			//�� �˻� 
int search_ticket_number();		//��ȣǥ �˻� 

void edit_customer();			//�� ���� 
void edit_menu();				//�޴� ���� 

void del_customer();			//�� ���� 
void del_menu();				//�޴� ���� 

void view_menu();				//�޴� ��ü ���� 
void view_customer();			//������ ��ü ���� 

void end();						//������ 

void input_menu();             //ȣ������ �� ������ ���� ����ü�� ��� �Լ�
void input_customer();
void input_ticket_number();

void SetTextColor(int background, int text) // UI
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background<<4) | text);
	//������ background�� 4��Ʈ ������ ������, text�� ���Ͽ� ����
}

//����ü �迭 �������� ����
MENU menu_info[200];
int menu_idx=0;        //�޴� ���� ī����

CUSTOMER customer_info[200];
int customer_idx=0;        //�� ���� ī����

TICKET_NUMBER ticket_number_info[200];
int ticket_number_idx=0;        //��ȣǥ ���� ī����


int main()				//����ȭ��
{
	int i, sel=1, idx;
	input_menu();
	input_customer();
	input_ticket_number();

	SetTextColor(15, 0); //15: ���, 0: ������

	while(sel!=10)
	{
		system("cls"); //ȭ�������
		printf("============================\n");
		printf("|     ī�� ���� ���α׷�    |\n");
		printf("============�߰�============\n");
		printf("|  1. �ű� �޴� �߰�        |\n");
		printf("|  2. �ű� �� �߰�        |\n");
		printf("============�˻�============\n");
		printf("|  3. ���� �޴� �˻�        |\n");
		printf("|  4. ���� �� �˻�        |\n");
		printf("|  5. ��ȣǥ �˻�           |\n");
		printf("============����============\n");
		printf("|  6. ���� �� ����        |\n");
		printf("|  7. ���� �޴� ����        |\n");
		printf("==========��ü ����=========\n");
		printf("|  8. �޴� ��ü ����        |\n");
		printf("|  9. �� ��ü ����        |\n");
		printf("============����============\n");
		printf("|  10. ���α׷� ����        |\n");
		printf("============================\n");
		printf("  ���ϴ� �޴��� �����ϼ���: ");

		scanf("%d", &sel) ;

switch(sel)
		{
		case 1:
			new_customer();
			break;
		case 2:
			idx=search_customer();
			if(idx==1)
				printf("ã���ô� ������ �����ϴ�.\n");
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
				printf("ã���ô� ������ �����ϴ�.\n");
			else
			{
				printf("%s	%s	%s  %s\n",clothes_info[idx].brand, clothes_info[idx].type, clothes_info[idx].size, clothes_info[idx].color);
			}
			break;
		case 5:
			idx=search_brand();
			if(idx==-1)
				printf("ã���ô� ������ �����ϴ�.\n");
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
			printf("\n�߸� �����ϼ̽��ϴ�.\n");
			break;
		}
		printf("\n�۾��� �Ϸ��Ͽ����ϴ�.\n���ο� �޴��� �����Ϸ��� Enter�� �����ּ���.\n");
		getch(); // �׸� �Է� �ޱ� ��� -> ����ġ�� ���Ӱ� �׺� ���� ����
	}
	return 0;
}











