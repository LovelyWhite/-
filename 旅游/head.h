#ifndef head2h
#define head2h
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#define TURE 1
#define FALSE 0
#define ENTER 13
#define BACKSPACE 8
#define ESC 27
#define SLEEP Sleep(300)
typedef struct Dest
{
	int number;//���
	char city[20];//����
	char interest[20];//����
	int level;//���㼶��
	int time[2];//ʱ���
	double price;//�۸�
}Destination;//���εص����ݽṹ
typedef struct Use
{
	char number[20];//���
	char name[20];//����
	int destNumber[20];//Ŀ�ĵؾ�����
	char password[20];//����
	int authority;//Ȩ��
}Users;
typedef struct DestPt
{
	struct Dest data;
	struct DestPt* next;
}DestPtr;
typedef struct UsePt
{
	struct Use data;
	struct UsePt* next;
}UserPtr;
typedef struct Sys
{
	char usersFileAddr[30];
	char interestFileAddr[30];
	char setFileAddr[30];
	int curVisibility; //���ɼ�
}System;
Users currentUser;
void initSystem(DestPtr** destHead, UserPtr** userHead, System** setting);//��ʼ��ϵͳ
void setSystem(System* setting);//ϵͳ����
int fuzzyCompare(char* origin, char * textin);//ģ���Ƚ��ַ�������
int load(DestPtr** destHead, UserPtr** userHead, System setting, int* userCount, int* destCount);//���뺯��
void save(DestPtr* destHead, UserPtr* userHead, System setting);//���溯��
void printxy(int x,int y,const char* words);//�����������
void menu();//���˵�
void hello();//ע���½����
void addInterface();//��ӽ���
void deleteInterface();//ɾ������
void lookUpInterface();//���ҽ���
int login(UserPtr* userHead,int userCount);//��½����
void sign(UserPtr* userHead  ,int* userCount);//ע�ắ��
void add(UserPtr* userHead, DestPtr* destHead, int* userCount, int* destCount);//��Ӻ���
void addUserInterest(UserPtr* userHead);//����û�����
void addSystemInterest(DestPtr* destHead);//���ϵͳ����
void delete(UserPtr* userHead, DestPtr* destHead, int* userCount, int* destCount);//ɾ������
void deleteUserInterest(UserPtr* userHead);//ɾ���û�����
void deleteSystemInterest(DestPtr* destHead);//ɾ��ϵͳ����
void deleteUser(UserPtr* userHead);//ɾ���û�
void motify(UserPtr* userHead, DestPtr* destHead);//�޸ĺ���
void LookUp(UserPtr* userHead, DestPtr* destHead);//���Һ���
void addSlash(char *name);//���˫б�ܺ���
void normalLookUpInterest();//��ȷ���Ҿ���
void fuzzyLookUpInterest();//ģ�����Ҿ���
void normalLookUpUser();//��ȷ�����û�
void fuzzyLookUpUser();//ģ�������û�
#endif // !head2h

