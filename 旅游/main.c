#include"head.h"
int main()
{
	DestPtr* destHead = NULL;
	UserPtr* userHead = NULL;
	System* setting = NULL;
	int userCount = 0, destCount = 0;
	int loadSign = -1, loginSign = -1;
	int select1 = 1,select2=1;
	int s = 0;
	char x[10];
	initSystem(&destHead, &userHead, &setting);
	loadSign = load(&destHead, &userHead, *setting, &userCount, &destCount);
	if (loadSign != 0)
	{
		//printxy(9, 1, "����������");
	}
	while (1)
	{
		while (s != ENTER)
		{
		LOGIN:system("cls");
			hello();
			printxy(1, select1, ">");
			sprintf(x, "Current:%1d", select1);
			printxy(0, 8, x);
			s = _getch();
			if (s == ESC)
				goto EXIT;
			printxy(1, select1, " ");
			if (s == '-')select1--;
			else if (s == '=')select1++;
			if (select1 == 0)
				select1++;
			else if (select1 == 3)
				select1--;
			printxy(1, select1, ">");
		}
		s = 0;
		switch (select1)
		{
		case 1:loginSign = login(userHead, userCount); break;
		case 2:sign(userHead, &userCount); goto LOGIN;
		}
		if (loginSign == 1)//1��½�ɹ�
		{
			while (1)
			{
				while (s != ENTER)
				{
					system("cls");
					menu();
					printxy(1, select2, ">");
					sprintf(x, "Current:%1d", select2);
					printxy(0, 8, x);
					s = _getch();
					if (s == ESC)
					{
						memcpy(&currentUser,malloc(sizeof(Users)) , sizeof(Users));//�˳�ʱ��յ�ǰ�û���Ϣ
						goto LOGIN;
					}
					printxy(1, select2, " ");
					if (s == '-')select2--;
					else if (s == '=')select2++;
					if (select2 == 0)//1�� 2ɾ 3�� 4�� 5���� 6����
						select2++;
					else if (select2 == 7)
						select2--;
					printxy(1, select2, ">");
				}
				s = 0;
				switch (select2)
				{
				case 1:add(userHead, destHead,&userCount,&destCount); break;
				case 2:delete(userHead, destHead, &userCount, &destCount); break;
				case 3:motify(userHead, destHead); break;
				case 4:LookUp(userHead, destHead); break;
				case 5:setSystem(setting); break;
				case 6:save(destHead,userHead,*setting);
				}
			}
		}
		else if (loginSign == 0)
		{
			printxy(0,10, "�޴��˻�");
			SLEEP;
		}
		else if (loginSign == 2)
		{
			printxy(0,10, "�������");
			SLEEP;
		}
		else if (loginSign == 4)
		{
			printxy(0,10, "���˻�����ע��");
			SLEEP;
		}
	}
EXIT:printxy(0,10, "ϵͳ�˳�");
	SLEEP;
	return 0;
}