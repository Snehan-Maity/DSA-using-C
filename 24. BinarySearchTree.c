#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* lchild;
	int data;
	struct Node* rchild;
};
//struct Node* root=NULL;
struct Node* createNode(int item){
	struct Node* ptr=(struct Node* )malloc(sizeof(struct Node));
	ptr->lchild=NULL;
	ptr->data=item;
	ptr->rchild=NULL;
	return ptr;
}
struct Node* insert(struct Node* r,int item){
	if(r==NULL){
		return createNode(item);
	}
	struct Node* temp=r,* parent;
	while(temp!=NULL){
		parent=temp;
		if(item<temp->data){
			temp=temp->lchild;
		}
		else if(item>temp->data){
			temp=temp->rchild;
		}
		else{
			return r;
		}
	}
	if(item<parent->data){
		parent->lchild=createNode(item);
	}
	else{
		parent->rchild=createNode(item);
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
struct Node* search(struct Node* r,int key){
	if(r==NULL||r->data==key){
		return r;
	}
	if(key<r->data){
		return search(r->lchild,key);
	}
	else{
		return search(r->rchild,key);
	}
}
int totalNodes(struct Node* r){
	if(r==NULL){
		return 0;
	}
	return(totalNodes(r->lchild)+totalNodes(r->rchild)+1);
}
int totalInNodes(struct Node* r){
	if(r==NULL){
		return 0;
	}
	if(r->lchild==NULL && r->rchild==NULL){
		return 0;
	}
	return(totalInNodes(r->lchild)+totalInNodes(r->rchild)+1);
}
int totalExNodes(struct Node* r){
	if(r==NULL){
		return 0;
	}
	if(r->lchild==NULL && r->rchild==NULL){
		return 1;
	}
	return(totalInNodes(r->lchild)+totalInNodes(r->rchild));
}
struct Node* minNode(struct Node* r){
	if(r==NULL){
		return r;
	}
	struct Node* temp=r;
	while(temp->lchild!=NULL){
		temp=temp->lchild;
	}
	return temp;
}
struct Node* deleteNode(struct Node* r,int key){
	if(r==NULL){
		return r;
	}
	if(key<r->data){
		r->lchild=deleteNode(r->lchild,key);
	}
	else if(key>r->data){
		r->rchild=deleteNode(r->rchild,key);
	}
	else{
		if(r->lchild==NULL){
			struct Node* temp=r->rchild;
			free(r);
			return temp;
		}
		if(r->rchild==NULL){
			struct Node* temp=r->lchild;
			free(r);
			return temp;
		}
		struct Node* succ=minNode(r->rchild);
		r->data=succ->data;
		r->rchild=deleteNode(r->rchild,succ->data);
	}
	return r;
}
int main(){
	struct Node* root=NULL;
	int choice,n,d;
	struct Node* p;
	while(1){
		printf("\n0. To Exit\n1. To Insert Element\n2. In Oder\n3. Pre Oder\n4. Post Order\n5. Search\n6. Total Nodes\n7. Total External Nodes\n8. Total Internal Nodes\n9. To delete a Node\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
					break;
			case 1: printf("Enter the number to insert : ");
					scanf("%d",&n);
					root=insert(root,n);
					break;
			case 2: inOrder(root);
					break;
			case 3: preOrder(root);
					break;
			case 4: postOrder(root);
					break;
			case 5: printf("Enter the item to search : ");
					scanf("%d",&n);
					p=search(root,n);
					if(p!=NULL){
						printf("Item found");
					}
					else{
						printf("Item not found");
					}
					break;
			case 6: n=totalNodes(root);
					printf("%d",n);
					break;
			case 7: n=totalExNodes(root);
					printf("%d",n);
					break;
			case 8: n=totalInNodes(root);
					printf("%d",n);
					break;
			case 9: printf("Enter the number to delete :");
					scanf("%d",&d);
					deleteNode(root,d);
					break;			
			default: printf("Invalid Choice !!");
		}
	}
}
