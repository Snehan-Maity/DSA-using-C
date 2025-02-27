#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* lchild;
	int data;
	struct Node* rchild;
	int height;
};
//struct Node* root=NULL;
struct Node* createNode(int item){
	struct Node* ptr=(struct Node* )malloc(sizeof(struct Node));
	ptr->lchild=NULL;
	ptr->data=item;
	ptr->rchild=NULL;
	ptr->height=1;
	return ptr;
}
int Max(int a,int b){
	return (a>b)?a:b;
}
int getH(struct Node* h){
	if(h==NULL){
		return 0;
	}
	return(h->height);
}
struct Node* rotateRight(struct Node* x){
	struct Node* y=x->lchild;
	struct Node* T=y->rchild;
	y->rchild=x;
	x->lchild=T;
	x->height=Max(getH(x->lchild),getH(x->rchild))+1;
	y->height=Max(getH(y->lchild),getH(y->rchild))+1;
	return y;
}
struct Node* rotateLeft(struct Node* x){
	struct Node* y=x->rchild;
	struct Node* T=y->lchild;
	y->lchild=x;
	x->rchild=T;
	x->height=Max(getH(x->lchild),getH(x->rchild));
	y->height=Max(getH(y->lchild),getH(y->rchild));
	return y;
}
int getBalance(struct Node* r){
	if(r==NULL){
		return 0;
	}	
	return getH(r->lchild)-getH(r->rchild);
}
struct Node* insert(struct Node* r,int item){
	if(r==NULL){
		return createNode(item);
	}
	if(item<r->data){
		r->lchild=insert(r->lchild,item);
	}
	else if(item>r->data){
		r->rchild=insert(r->rchild,item);
	}
	else{
		return r;
	}
	r->height=Max(getH(r->lchild),getH(r->rchild))+1;
	int balance=getBalance(r);
	if(balance>1 && item<r->lchild->data){
		return rotateRight(r);
	}
	if(balance<-1 && item>r->lchild->data){
		return rotateLeft(r);
	}
	if(balance>1 && item>r->lchild->data){
		r->lchild=rotateLeft(r->lchild);
		return rotateRight(r);
	}
	if(balance<-1 && item<r->rchild->data){
		r->rchild=rotateRight(r->rchild);
		return rotateLeft(r);
	}
	return r;
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
struct Node* delNode(struct Node* r,int key){
	if(r==NULL){
		return r;
	}
	if(key<r->data){
		r->lchild=delNode(r->lchild,key);
	}
	else if(key>r->data){
		r->rchild=delNode(r->rchild,key);
	}
	else{
		if(r->lchild==NULL){
			struct Node* ptr=r->rchild;
			free(r);
			return ptr;
		}
		else if(r->rchild==NULL){
			struct Node* ptr= r->lchild;
			free(r);
			return ptr;
		}
		struct Node* succ=minNode(r->rchild);
		r->data=succ->data;
		r->rchild=delNode(r->rchild,succ->data);
	}
	r->height=Max(getH(r->lchild),getH(r->rchild))+1;
	int balance=getBalance(r);
	if(balance>1 && getBalance(r->lchild)>=0){
		return rotateRight(r);
	}
	if(balance>1 && getBalance(r->lchild)<0){
		r->lchild=rotateLeft(r->lchild);
		return rotateRight(r);
	}
	if(balance<-1 && getBalance(r->rchild)<=0){
		return rotateLeft(r);
	}
	if(balance<-1 && getBalance(r->rchild)>0){
		r->rchild=rotateRight(r->rchild);
		return rotateLeft(r);
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
int main(){
	struct Node* root=NULL;
	int choice,n,d;
	struct Node* p;
	while(1){
		printf("\n0. To Exit\n1. To Insert Element\n2. To Delete Element\n3.In Oder\n4. Pre Oder\n5. Post Order\n6. Search\n"); //Total Nodes\n7. Total External Nodes\n8. Total Internal Nodes\n9. To delete a Node\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
					break;
			case 1: printf("Enter the number to insert : ");
					scanf("%d",&n);
					root=insert(root,n);
					break;
			case 2: printf("Enter the number to delete : ");
					scanf("%d",&d);
					root=delNode(root,d);
					break;
			case 3: printf("In Order Traversal : ");
					inOrder(root);
					break;
			case 4: printf("Pre Order Traversal : ");
					preOrder(root);
					break;
			case 5: printf("Post Order Traversal : ");
					postOrder(root);
					break;
			case 6: printf("Enter the item to search : ");
					scanf("%d",&n);
					p=search(root,n);
					if(p!=NULL){
						printf("Item found");
					}
					else{
						printf("Item not found");
					}
					break;
		/*	case 6: n=totalNodes(root);
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
					break;			*/
			default: printf("Invalid Choice !!");
		}
	}
}
