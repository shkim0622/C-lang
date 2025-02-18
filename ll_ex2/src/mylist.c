#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "common.h"
#include "mylist.h"

typedef struct _Node {
    int data;
    node *pnode;
} node;

// global variables, only uses in mylist
node *proot;

// Hidden functions
node *_mylist_make_new_node(int);

/**
 * mylist를 초기화 한다.
 * 단지 root에 NULL을 넣는다
 * @param none
 * @returns 성공 여부, 늘 성공
*/
int mylist_init() {
    proot = NULL;
    return SUCCESS;
} // end func

int mylist_append(int data) {

    node *p;

    p = proot;

    // 1. Find last node
    if (p != NULL) { // mylist is not empty
        while(p->pnode != NULL) {
            p = p->pnode;
        } // end while
        // 2. if root is not empty, create new node and append
        p->pnode = _mylist_make_new_node(data);
    } else { // root is NULL (empty)
        // 3. if root is empty, create new node and put it on 
        proot = _mylist_make_new_node(data);
    }
    return SUCCESS;
}

/**
 * 새 노드를 만들고 그 위치를 돌려준다.
 * @param {int} 새 노드에 들어갈 데이터
 * @returns 성공시 해당 포인터 주소, 실패시 NULL
*/
node *_mylist_make_new_node(int data) {

    node *p;

    p = (node *)malloc(sizeof(node));
    if (p == NULL) {
        return NULL;
    }
    p->data = data;
    p->pnode = NULL;
    return p;
}


/**
 * 숫자를 받아, mylist 내에서 그 위치를 알려준다.
 * @param {int} 찾을 데이터
 * @returns 성공시 mylist 내의 위치값, 실패시 0
*/
int mylist_search(int data) {
    node *p = proot;
    int count = 0;

    if (p == NULL) { // if mylist is empty, return 0
        return 0; // not found
    }

    while(p != NULL) {
        count++;
        if (p->data == data) { // found!!
            return count;
        }
        p = p->pnode;
    }

    // not found
    return 0;
}
int mylist_delete(int data)	{
	node *p = proot;
	node *rm
	if (p == NULL)	{	
	
		return 0;
	} 
	else	{
		if(p->data == data) {
			p->pnode = rm ->pnode;
			free(rm);
		}
		while(p->pnode != NULL) {
			p = p->pnode;	
		} 			
	}
	return 0;
}

/**
 * mylist의 모든 값들을 나열한다.
 * @param none
 * @return none
*/
void mylist_print() {
    node *p = proot;

    while (p != NULL) { // be careful!!, not p->pnode
        printf("%3d ", p->data);
        p = p->pnode;
    }
    printf("\n");

}

/**
 * mylist의 모든 노드들을 삭제하고 root에 NULL을 대입
 * @param none
 * @return none
*/
void mylist_cleanup() {
    node *p = proot;
    node *pt;

    if (p == NULL) {
        return;
    }

    while (p != NULL) { // be careful!!, not p->pnode
        pt = p->pnode;
        free(p);
		
        p = pt;
    }
}

