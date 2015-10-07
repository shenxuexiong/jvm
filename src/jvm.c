/*******************************
 * file name:   jvm.c
 * description: program entry 
 * date:        2015-01-19
 * author:      kari.zhang
 *
 * modifications:
 *
 * 1. Modified by Kari.Zhang @ 2015-01-19
 *      rearchitect & redesign
 * ****************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"
#include "instruction.h"
#include "jvm.h"

struct JavaStack {
	int top;
	int size;
	StackFrame **base;
};

bool pushStack(JavaStack *stack, StackFrame *frame) {
	if (NULL == stack || NULL == frame) {
		return FALSE;
	}
	if (stack->top + 1 >= stack->size) {
		fprintf(stderr, "Stack is overflow\n");
		return FALSE;
	}

	stack->base[++stack->top] = frame;
	return TRUE;
}

StackFrame* popStack(JavaStack *stack) {
	if (NULL == stack || stack->top < 1) {
		fprintf(stderr, "Stack is downflow\n");
		return NULL;
	}

	return stack->base[--stack->top];
}

bool isEmpty(JavaStack *stack) {
	assert(NULL != stack);
	return stack->top < 1;
}


void initMem(InitArgs *args) {

}

void initGC(InitArgs *args) {

}

void initVM(InitArgs *args, VM *vm) {

}

bool startVM(VM *vm) {

}

bool exitVM(VM *vm) {

}

void setDefaultInitArgs(InitArgs *args)
{

}

int readSysConfig(char *path, Property *props) {
	return 0;
}

int setInitArgs(Property *props, int nprop, InitArgs *args) {
	return 0;
}

int parseCmdLine(int argc, char **argv, Property *props) {
	if (argc == 1) {
		printf("Invalid parameter\n");
		printf("Usage\n");
		printf("  jvm CLASS\n");
		exit(0);
	}

	return 0;
}

int main(int argc, char *argv[]) {
	InitArgs initArgs;	
	setDefaultInitArgs(&initArgs);
	Property props[argc - 1];
	int len = parseCmdLine(argc, argv, props);
	setInitArgs(props, len, &initArgs);

    char path[256];
    strcpy(path, argv[1]);
    strcat(path, ".class");
	Class *mainClass = loadClassFromFile(path, argv[1]);
    if (NULL == mainClass) {
        fprintf(stderr, "Failed loadClass from file\n");
        return -1;
    }
    ClassEntry *clsEntry = CLASS_CE(mainClass);
//    logClassEntry(clsEntry);

}
