#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

struct Stack {
	float date;
	Stack* head;
	Stack* next;
};

void menu();
void push(struct Stack*& MyStack);
float pop(Stack* myStk);
void clearStack(struct Stack*& MyStack);
void showStack(Stack*& MyStack);
void clearStack(Stack*& MyStack);
void search(Stack* MySt);
void WriteInFile(Stack* myStk);
void ReadFromFile(Stack* MySt, string fileName);
