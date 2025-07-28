#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* lchild;
	int data;
	struct Node* rchild;
};
struct Node* createNode(int item){
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=item;
	ptr->lchild=ptr->rchild=NULL;
	return ptr;
}
struct Node* insert(struct Node* r, int item) {
    if (r == NULL) {  // If tree is empty, create the root
        return createNode(item);
    }

    struct Node* temp = r;
    struct Node* parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (item < temp->data) {
            temp = temp->lchild;
        } else if (item > temp->data) {
            temp = temp->rchild;
        } else {
            return r; // No duplicates
        }
    }

    if (item < parent->data) {
        parent->lchild = createNode(item);
    } else {
        parent->rchild = createNode(item);
    }

    return r;
}





void inOrder(struct Node* r){
	if(r==NULL){
		return;
	}	
	inOrder(r->lchild);
	printf("%3d",r->data);
	inOrder(r->rchild);
}
void preOrder(struct Node* r){
	if(r==NULL){
		return;
	}
	printf("%3d",r->data);
	preOrder(r->lchild);
	preOrder(r->rchild);	
}
void postOrder(struct Node* r){
	if(r==NULL){
		return;
	}
	postOrder(r->lchild);
	postOrder(r->rchild);	
	printf("%3d",r->data);
}
int main(){
	int choice,item;
	struct Node* root= NULL;
	while(1){
		printf("\n0. To Exit\n1. Insert Node\n2. In Order Traversal\n3. Pre Order Traversal\n4. Post Order Traversal\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
					break;
			case 1: printf("Enter the value to add : ");
					scanf("%d",&item);
					root=insert(root,item);
					break;
			case 2: inOrder(root);
					break;
			case 3: preOrder(root);
					break;
			case 4: postOrder(root);
					break;
		}
	}
}
